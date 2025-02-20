#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 200005;

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
	
	inline bool merge(int x,int y){
		x = find(x),y = find(y);
		if(x == y) return false;
		if(r[x] > r[y]) swap(x,y);
		r[y] += r[x];
		f[x] = y;
		return true;
	}
}

namespace Graph{
	struct edge{
		int u;
		int v;
		int w;
	}e[M];
	int cur = 0;
	
	inline void addedge(int u,int v,int w){
		e[++ cur].u = u;
		e[cur].v = v;
		e[cur].w = w;
	}
	
	inline int kruskal(int n){
		int ans = 0;
		Set::init(n);
		sort(e + 1,e + cur + 1,[&](const edge& A,const edge& B) -> bool { return A.w < B.w; });
		for(int i = 1;i <= cur;++ i){
			int u = e[i].u;
			int v = e[i].v;
			int w = e[i].w;
			if(Set::merge(u,v)){
				ans += w; 
				n --;
			}
		}
		if(n != 1) return -1;
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m;++ i){
		int u,v,w;
		cin>>u>>v>>w;
		Graph::addedge(u,v,w);
	}
	int ans = Graph::kruskal(n);
	if(ans == -1) cout<<"orz";
	else cout<<ans;
	return 0;
}
