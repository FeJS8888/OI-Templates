#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b){
	if(!a || !b) return a | b;
	return gcd(b,a % b);
}

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int g = 0;
	for(int i = 1;i <= n;++ i){
		int x;
		cin>>x;
		if(x < 0) x = -x;
		g = gcd(g,x);
	}
	cout<<g;
	return 0;
}
