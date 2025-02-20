#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 19260817;
int x,y;

int gcd(int a,int b){
	if(!a || !b) return a | b;
	return gcd(b,a % b); 
}

int exgcd(int a,int b){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	int g = exgcd(b,a % b);
	int t = x;
	x = y;
	y = t - (a / b) * y;
	return g;
}

signed main(){
	int a,b;
	cin>>a>>b;
	exgcd(b,mod);
	x = (x % mod + mod) % mod;
	cout<<a * x % mod;
}
