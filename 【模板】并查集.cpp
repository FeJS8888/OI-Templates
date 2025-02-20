#include<bits/stdc++.h>
using namespace std;
const int N = 200005;

namespace Set{
	int f[N],r[N];
	inline void init(int n){
		for(int i = 1;i <= n;++ i){
			f[i] = i;
			r[i] = 1;
		}
	}
	
	inline int find(int w){
		if(f[w] == w) return w;
		return f[w] = find(f[w]);
	}
	
	inline void merge(int x,int y){
		x = find(x),y = find(y);
		if(x == y) return;
		if(r[x] > r[y]) swap(x,y);
		r[y] += r[x];
		f[x] = y; 
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	Set::init(n);
	while(m --){
		int op,x,y;
		cin>>op>>x>>y;
		if(op == 1){
			Set::merge(x,y);
		}
		else{
			cout<<(Set::find(x) == Set::find(y) ? 'Y' : 'N')<<"\n";
		}
	}
	return 0;
}
