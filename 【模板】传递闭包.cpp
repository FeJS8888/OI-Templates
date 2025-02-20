#include<bits/stdc++.h>
using namespace std;
const int N = 105;
bitset<N> dis[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i <= n;++ i){
		for(int j = 1;j <= n;++ j){
			int x;
			cin>>x;
			dis[i][j] = x;
		}
	}
	for(int k = 1;k <= n;++ k){
		for(int i = 1;i <= n;++ i){
			if(!dis[i][k]) continue;
			dis[i] |= dis[k];
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
