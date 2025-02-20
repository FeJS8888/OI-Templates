#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 1000005;
typedef unsigned long long ull;

namespace Hash{
	const int base = 13131;
	ull hash(const string& s){
		ull h = 0;
		for(int i = 0;i < s.length();++ i){
			h = h * base + s[i];
		}
		return h;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	set<ull> h;
	for(int i = 1;i <= n;++ i){
		string s;
		cin>>s;
		h.insert(Hash::hash(s));
	}
	cout<<h.size();
	return 0;
}
