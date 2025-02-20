#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int LOGN = 25;
int a[N];

namespace ST{
	int logn[N],data[N][LOGN];
	inline void build(int n){
		for(int i = 2;i <= n;++ i) logn[i] = logn[i >> 1] + 1;
		for(int i = 1;i <= n;++ i) data[i][0] = a[i];
		for(int k = 1;k <= logn[n];++ k){
			for(int i = 1;i + (1 << k) - 1 <= n;++ i){
				data[i][k] = max(data[i][k - 1],data[i + (1 << (k - 1))][k - 1]);
			}
		}
	}
	
	inline int query(int l,int r){
		int s = logn[r - l + 1];
		return max(data[l][s],data[r - (1 << s) + 1][s]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;++ i) cin>>a[i];
	ST::build(n);
	for(int i = 1;i <= m;++ i){
		int l,r;
		cin>>l>>r;
		cout<<ST::query(l,r)<<"\n";
	}
	return 0;
}
