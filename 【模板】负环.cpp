#include<bits/stdc++.h>
using namespace std;
const int N = 5005;

namespace Graph{
	struct edge{
		int v;
		int w;
		int next;
	}e[N << 1];
	int head[N];
	int cur = 0;
	
	inline void clear(){
		memset(head,0,sizeof(head));
		cur = 0;
	}
	
	inline void addedge(int u,int v,int w){
		e[++ cur].v = v;
		e[cur].w = w;
		e[cur].next = head[u];
		head[u] = cur;
	}
	
	int dis[N],cnt[N];
	bool used[N];
	inline bool spfa(int S,int n){
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		memset(used,0,sizeof(used));
		dis[S] = 0;
		queue<int> q;
		q.push(S);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			used[u] = false;
			for(int i = head[u];i;i = e[i].next){
				int v = e[i].v;
				int w = e[i].w;
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					cnt[v] = cnt[u] + 1;
					if(cnt[v] >= n) return true;
					if(used[v]) continue;
					used[v] = true;
					q.push(v); 
				}
			}
		}
		return false;
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --){
		Graph::clear();
		int n,m;
		cin>>n>>m;
		for(int i = 1;i <= m;++ i){
			int u,v,w;
			cin>>u>>v>>w;
			Graph::addedge(u,v,w);
			if(w >= 0) Graph::addedge(v,u,w);
		}
		cout<<(Graph::spfa(1,n) ? "YES" : "NO")<<"\n";
	}
	return 0;
}
