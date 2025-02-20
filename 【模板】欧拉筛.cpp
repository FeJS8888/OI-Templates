#include<bits/stdc++.h>
using namespace std;
const int N = 100000005;
const int M = 1000005;
bool flag[N];
int prime[M],cnt;

inline void init(int n){
	for(int i = 2;i <= n;++ i){
		if(!flag[i]){
			prime[++ cnt] = i;
		}
		for(int j = 1;j <= cnt;++ j){
			if(i * prime[j] > n) break;
			flag[i * prime[j]] = true;
			if(!(i % prime[j])) break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	init(n);
	while(q --){
		int x;
		cin>>x;
		cout<<prime[x]<<"\n";
	}
	return 0;
}
