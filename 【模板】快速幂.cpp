#include<bits/stdc++.h>
using namespace std;
const int N = 100005;

inline long long qpow(long long base,long long times,long long mod){
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
	long long a,b,mod;
	cin>>a>>b>>mod;
	cout<<a<<"^"<<b<<" mod "<<mod<<"="<<qpow(a,b,mod);
	return 0;
}
