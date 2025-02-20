#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
const int M = 500005;
const int INF = 0x3f3f3f3f;

namespace Graph{
	struct edge{
		int v;
		int w;
		int next;
	}e[M];
	int head[N];
	int cur = 0;
	
	inline void addedge(int u,int v,int w){
		e[++ cur].v = v;
		e[cur].w = w;
		e[cur].next = head[u];
		head[u] = cur;
	}
	
	int dis[N];
	bool used[N];
	inline void dijkstra(int S){
		memset(dis,0x3f,sizeof(dis));
		memset(used,0,sizeof(used));
		priority_queue<pair<int,int> > q;
		q.push({-0,S});
		dis[S] = 0;
		while(!q.empty()){
			int u = q.top().second;
			q.pop();
			if(used[u]) continue;
			used[u] = true;
			for(int i = head[u];i;i = e[i].next){
				int v = e[i].v;
				int w = e[i].w;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					q.push({-dis[v],v});
				}
			}
		}
	}
	
	inline void spfa(int S){
		memset(dis,0x3f,sizeof(dis));
		memset(used,0,sizeof(used));
		queue<int> q;
		q.push(S);
		dis[S] = 0;
		used[S] = true;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			used[u] = false;
			for(int i = head[u];i;i = e[i].next){
				int v = e[i].v;
				int w = e[i].w;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					if(used[v]) continue;
					used[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,S;
	cin>>n>>m>>S;
	for(int i = 1;i <= m;++ i){
		int u,v,w;
		cin>>u>>v>>w;
		Graph::addedge(u,v,w);
	}
	Graph::dijkstra(S);
	for(int i = 1;i <= n;++ i) cout<<(Graph::dis[i] == INF ? (1 << 31) - 1 : Graph::dis[i])<<" ";
	return 0;
}
