#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N],b[N];
vector<int> p;

int main(){
	int n;
	cin>>n;
	for(int i = 1;i <= n;++ i){
		int x;
		cin>>x;
		a[x] = i;
	}
	for(int i = 1;i <= n;++ i){
		int x;
		cin>>x;
		x = a[x];
		auto it = lower_bound(p.begin(),p.end(),x);
		if(it == p.end()) p.push_back(x);
		else *it = x;
	}
	cout<<p.size();
	return 0;
}
