#include<bits/stdc++.h>
using namespace std;
const int N = 3000005;

namespace Trie{
	const int CharSet = 26 + 26 + 10;
	int trie[CharSet][N];
	int f[N];
	int cur = 0;
	inline void clear(){
		memset(f,0,sizeof(int) * (cur + 2));
		for(int i = 0;i < CharSet;++ i){
			memset(trie[i],0,sizeof(int) * (cur + 2));
		}
		cur = 0;
	}
	
	inline int T(char ch){
		if(ch >= '0' && ch <= '9') return ch - '0';
		if(ch >= 'a' && ch <= 'z') return ch - 'a' + 10;
		if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10 + 26;
		return -1;
	}
	
	inline void insert(const string& s){
		int p = 0;
		int len = s.length();
		for(int i = 0;i < len;++ i){
			int ch = T(s[i]);
			if(!trie[ch][p]) trie[ch][p] = ++ cur;
			p = trie[ch][p];
			f[p] ++;
		}
	}
	
	inline int query(const string& s){
		int len = s.length();
		int p = 0;
		for(int i = 0;i < len;++ i){
			int ch = T(s[i]);
			if(!trie[ch][p]) return 0;
			p = trie[ch][p];
		}
		return f[p];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --){
		int n,q;
		cin>>n>>q;
		Trie::clear();
		for(int i = 1;i <= n;++ i){
			string s;
			cin>>s;
			Trie::insert(s);
		}
		for(int i = 1;i <= q;++ i){
			string s;
			cin>>s;
			cout<<Trie::query(s)<<"\n";
		}
	}
	return 0;
}
