#include<bits/stdc++.h>
using namespace std;
const int N = 500005;

namespace BIT{
	int tree[N];
	inline void add(int x,int d){
		while(x < N){
			tree[x] += d;
			x += x & -x;
		}
	}
	
	inline int query(int x){
		int ans = 0;
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
	}
	for(int i = 1;i <= m;++ i){
		int op,x,y;
		cin>>op>>x>>y;
		if(op == 1) BIT::add(x,y);
		else cout<<BIT::query(y) - BIT::query(x - 1)<<"\n"; 
	}
	return 0;
}
