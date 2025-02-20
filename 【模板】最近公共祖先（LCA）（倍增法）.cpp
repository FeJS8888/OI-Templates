#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
const int LOGN = 30;

namespace Graph{
	struct edge{
		int v;
		int next;
	}e[N << 1];
	int head[N];
	int cur = 0;
	
	inline void addedge(int u,int v){
		e[++ cur].v = v;
		e[cur].next = head[u];
		head[u] = cur;
	}
	
	int dep[N],g[N][LOGN];
	inline void dfs(int u,int fa){
		dep[u] = dep[fa] + 1;
		g[u][0] = fa;
		for(int k = 1;k < LOGN;++ k){
			g[u][k] = g[g[u][k - 1]][k - 1];
		}
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(v == fa) continue;
			dfs(v,u);
		}
	}
	
	inline int lca(int x,int y){
		if(x == y) return x;
		if(dep[x] < dep[y]) swap(x,y);
		for(int k = LOGN - 1;k >= 0;-- k){
			if(dep[g[x][k]] >= dep[y]){
				x = g[x][k];
			}
		}
		if(x == y) return x;
		for(int k = LOGN - 1;k >= 0;-- k){
			if(g[x][k] != g[y][k]){
				x = g[x][k];
				y = g[y][k];
			}
		}
		return g[x][0];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,rt;
	cin>>n>>m>>rt;
	for(int i = 1;i <= n - 1;++ i){
		int u,v;
		cin>>u>>v;
		Graph::addedge(u,v);
		Graph::addedge(v,u);
	}
	Graph::dfs(rt,0);
	for(int i = 1;i <= m;++ i){
		int x,y;
		cin>>x>>y;
		cout<<Graph::lca(x,y)<<"\n";
	}
	return 0;
}
