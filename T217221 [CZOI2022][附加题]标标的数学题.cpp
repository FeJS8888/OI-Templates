#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mod = 1e9 + 7;
long long x[N],y[N];

inline long long qpow(long long base,long long times){
	if(!times) return 1;
	long long ans = 1;
	while(times){
		if(times & 1) ans = ans * base % mod;
		base = base * base % mod;
		times >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long ans = 0,sum = 0,n,k;
	cin>>n>>k;
	for(int i = 1;i <= k + 5;++ i){
		sum += qpow(i,k);
		sum %= mod;
		x[i] = i;
		y[i] = sum;
	}
	for(int i = 1;i <= k + 5;++ i){
		long long p = 1,q = 1;
		for(int j = 1;j <= k + 5;++ j){
			if(i == j) continue;
			p = p * (n - x[j]) % mod;
			q = q * (x[i] - x[j]) % mod;
		}
		ans += y[i] * p % mod * qpow(q,mod - 2) % mod;
		ans %= mod;
	}
	ans = (ans % mod + mod) % mod;
	cout<<ans;
	return 0;
}
