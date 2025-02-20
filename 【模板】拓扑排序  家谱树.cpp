#include<bits/stdc++.h>
using namespace std;
const int N = 100;

namespace Graph{
	struct edge{
		int v;
		int next;
	}e[N << 2];
	int head[N],din[N];
	int cur = 0;
	
	inline void addedge(int u,int v){
		e[++ cur].v = v;
		e[cur].next = head[u];
		head[u] = cur;
		din[v] ++;
	}
	
	inline vector<int> topo(int n){
		queue<int> q;
		vector<int> ans;
		for(int i = 1;i <= n;++ i){
			if(!din[i]) q.push(i);
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			ans.push_back(u);
			for(int i = head[u];i;i = e[i].next){
				int v = e[i].v;
				din[v] --;
				if(!din[v]) q.push(v);
			}
		}
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int u = 1;u <= n;++ u){
		int v;
		while(cin>>v){
			if(!v) break;
			Graph::addedge(u,v);
		}
	}
	vector<int> ans = Graph::topo(n);
	for(int u : ans) cout<<u<<" ";
	return 0;
}
