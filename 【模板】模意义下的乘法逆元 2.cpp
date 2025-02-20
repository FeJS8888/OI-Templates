#include<bits/stdc++.h>
using namespace std;
const int N = 5000005;
int pre[N],suf[N];
int a[N];

char buf[(int)1e8],*ss=buf;
inline int init(){buf[fread(buf,1,(int)1e8-1,stdin)]='\n';fclose(stdin);return 0;}
const int __START__=init();
inline int readint(){
    int d=0;
    while(!isdigit(*ss))++ss;
    while(isdigit(*ss))d=d*10+(*ss++^'0');
    return d;
}

long long qpow(long long base,long long times,long long mod){
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
	int n,mod,k;
    long long ans = 0,K = 1;
	n = readint(),mod = readint(),k = readint();
	K = pre[0] = suf[n + 1] = 1;
	for(int i = 1;i <= n;++ i){
		a[i] = readint();
		pre[i] = (long long)pre[i - 1] * a[i] % mod;
	}
	for(int i = n;i >= 1;-- i) suf[i] = (long long)suf[i + 1] * a[i] % mod;
	for(int i = 1;i <= n;++ i){
		K = K * k % mod;
		ans = (ans + K * (long long)pre[i - 1] % mod * (long long)suf[i + 1]) % mod;
	}
	ans = ans * qpow(pre[n],mod - 2,mod) % mod;
	printf("%lld",ans);
	return 0;
}
