#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --){
		int n;
		cin>>n;
		int xum = 0;
		for(int i = 1;i <= n;++ i){
			int x;
			cin>>x;
			xum ^= x;
		}
		cout<<(xum ? "Yes" : "No")<<"\n";
	}
	return 0;
}
