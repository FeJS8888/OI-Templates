#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
int dis[N][N];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;++ i){
		for(int j = 1;j <= n;++ j){
			dis[i][j] = INF;
		}
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;++ i){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v] = dis[v][u] = min(dis[u][v],w);
	}
	for(int k = 1;k <= n;++ k){
		for(int i = 1;i <= n;++ i){
			if(dis[i][k] == INF) continue;
			for(int j = 1;j <= n;++ j){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1;i <= n;++ i){
		for(int j = 1;j <= n;++ j){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
