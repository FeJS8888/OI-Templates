#include<bits/stdc++.h>
using namespace std;
const int N = 500005;

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
	
	int dep[N],g[N],size[N],son[N];
	inline void dfs1(int u,int fa){
		dep[u] = dep[fa] + 1;
		g[u] = fa;
		size[u] = 1;
		son[u] = 0;
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(v == fa) continue;
			dfs1(v,u);
			size[u] += size[v];
			if(!son[u] || size[son[u]] < size[v]) son[u] = v;
		}
	}
	
	int top[N],dfn[N],tot = 0;
	inline void dfs2(int u,int topx){
		top[u] = topx;
		dfn[u] = ++ tot;
		if(!son[u]) return;
		dfs2(son[u],topx);
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(v == g[u] || v == son[u]) continue;
			dfs2(v,v);
		}
	}
	
	inline int lca(int x,int y){
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]]) swap(x,y);
			x = g[top[x]];
		}
		if(dep[x] > dep[y]) swap(x,y);
		return x;
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
	Graph::dfs1(rt,0);
	Graph::dfs2(rt,rt);
	for(int i = 1;i <= m;++ i){
		int x,y;
		cin>>x>>y;
		cout<<Graph::lca(x,y)<<"\n";
	}
	return 0;
}
