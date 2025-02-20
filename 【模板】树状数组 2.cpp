#include<bits/stdc++.h>
using namespace std;
const int N = 500005;

namespace BIT{
	int tree[N],zero;
	inline void add(int x,int d){
		if(!x){
			zero += d;
			return;
		}
		while(x < N){
			tree[x] += d;
			x += x & -x; 
		}
	}
	
	inline int query(int x){
		int ans = zero;
		while(x){
			ans += tree[x];
			x -= x & -x;
		}
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;++ i){
		int x;
		cin>>x;
		BIT::add(i,x);
		BIT::add(i + 1,-x);
	}
	for(int i = 1;i <= m;++ i){
		int op;
		cin>>op;
		if(op == 1){
			int l,r,k;
			cin>>l>>r>>k;
			BIT::add(l,k);
			BIT::add(r + 1,-k);
		}
		else{
			int x;
			cin>>x;
			cout<<BIT::query(x)<<"\n"; 
		}
	}
	return 0;
}
