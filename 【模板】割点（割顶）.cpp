#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

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
	
	int low[N],dfn[N],tot = 0;
	int cut[N];
	inline void tarjan(int u,int fa){
		dfn[u] = low[u] = ++ tot;
		int son = 0;
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(!dfn[v]){
				tarjan(v,fa);
				low[u] = min(low[v],low[u]);
				if(low[v] >= dfn[u] && u != fa) cut[u] ++;
				son ++;
			}
			else low[u] = min(low[u],dfn[v]);
		}
		if(u == fa && son >= 2) cut[u] = true;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= m;++ i){
		int u,v;
		cin>>u>>v;
		Graph::addedge(u,v);
		Graph::addedge(v,u);
	}
	for(int i = 1;i <= n;++ i){
		if(!Graph::dfn[i]) Graph::tarjan(i,i);
	}
	int ans = 0;
	for(int i = 1;i <= n;++ i){
		if(Graph::cut[i]) ans ++;
	}
	cout<<ans<<"\n";
	for(int i = 1;i <= n;++ i){
		if(Graph::cut[i]) cout<<i<<" ";
	}
	return 0;
}
