#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;

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
	int s[N],top = 0;
	vector<int> bcc[N];
	int cnt = 0;
	inline void tarjan(int u,bool isRT){
		low[u] = dfn[u] = ++ tot;
		s[++ top] = u;
		int son = 0;
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(!dfn[v]){
				son ++;
				tarjan(v,false);
				low[u] = min(low[u],low[v]);
				if(low[v] >= dfn[u]){
					cnt ++;
					int x;
					do{
						x = s[top --];
						bcc[cnt].push_back(x);
					} while(x != v);
					bcc[cnt].push_back(u);
				}
			}
			else low[u] = min(low[u],dfn[v]);
		}
		if(!son && isRT) bcc[++ cnt].push_back(u);
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
		if(!Graph::dfn[i]) Graph::tarjan(i,true);
		Graph::top = 0;
	}
	cout<<Graph::cnt<<"\n";
	for(int i = 1;i <= Graph::cnt;++ i){
		cout<<Graph::bcc[i].size()<<" ";
		for(int x : Graph::bcc[i]){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
