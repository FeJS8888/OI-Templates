#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;

namespace KMP{
	int next[N];
	inline void build(const string& s){
		int len = s.length();
		next[0] = next[1] = 0;
		for(int i = 1;i < len;++ i){
			int j = next[i];
			while(j && s[i] != s[j]) j = next[j];
			if(s[i] == s[j]) next[i + 1] = j + 1;
			else next[i + 1] = 0;
		}
	}
	
	inline vector<int> query(const string& s,const string& p){
		int slen = s.length(),plen = p.length();
		build(p);
		int j = 0;
		vector<int> ans;
		for(int i = 0;i < slen;++ i){
			while(j && s[i] != p[j]) j = next[j];
			if(s[i] == p[j]) j ++;
			if(j == plen){
				ans.push_back(i - plen + 2);
				j = next[j];
			}
		}
		return ans;
	}
}

int main(){
	string s,p;
	cin>>s>>p;
	vector<int> ans = KMP::query(s,p);
	for(int pos : ans) cout<<pos<<"\n";
	int len = p.length();
	for(int i = 1;i <= len;++ i) cout<<KMP::next[i]<<" ";
	return 0;
}
