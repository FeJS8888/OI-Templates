#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
bool used[N];

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
	
	int match[N];
	inline bool dfs(int u){
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(used[v]) continue;
			used[v] = true;
			if(!match[v] || dfs(match[v])){
				match[v] = u;
				return true;
			}
		}
		return false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,ans = 0;
	cin>>n>>m>>k;
	for(int i = 1;i <= k;++ i){
		int x,y;
		cin>>x>>y;
		y += n;
		Graph::addedge(x,y);
		Graph::addedge(y,x);
	}
	for(int i = 1;i <= n;++ i){
		memset(used,0,sizeof(used));
		if(Graph::dfs(i)) ans ++;
	}
	cout<<ans;
	return 0;
}
