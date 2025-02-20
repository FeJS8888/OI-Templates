#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
const int M = 2000005;

namespace Graph{
	struct edge{
		int v;
		int next;
	}e[M << 1];
	int head[N];
	int cur = 1;
	
	inline void addedge(int u,int v){
		e[++ cur].v = v;
		e[cur].next = head[u];
		head[u] = cur;
	}
	
	int dfn[N],low[N],tot = 0;
	vector<int> scc[N];
	int sccno[N],cnt = 0;
	int s[N],top = 0;
	inline void tarjan(int u,int from){
		low[u] = dfn[u] = ++ tot;
		s[++ top] = u;
		for(int i = head[u];i;i = e[i].next){
			if(i == from || i == (from ^ 1)) continue;
			int v = e[i].v;
			if(!dfn[v]){
				tarjan(v,i);
				low[u] = min(low[u],low[v]);
			}
			else if(!sccno[v]) low[u] = min(low[u],dfn[v]);
		}
		if(low[u] == dfn[u]){
			cnt ++;
			int x;
			do{
				x = s[top --];
				sccno[x] = cnt;
				scc[cnt].push_back(x);
			} while(u != x);
		}
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
		if(Graph::dfn[i]) continue;
		Graph::tarjan(i,0);
	}
	cout<<Graph::cnt<<"\n";
	for(int i = 1;i <= Graph::cnt;++ i){
		cout<<Graph::scc[i].size()<<" ";
		for(int x : Graph::scc[i]) cout<<x<<" ";
		cout<<"\n";
	}
	return 0;
}
