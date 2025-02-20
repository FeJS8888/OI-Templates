#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
int Ans[N];

namespace BIT{
	int tree[N];
	inline void add(int x,int d){
		while(x < N){
			tree[x] += d;
			x += x & -x;
		}
	}
	
	inline int query(int x){
		int ans = 0;
		while(x){
			ans += tree[x];
			x -= x & -x;
		}
		return ans;
	}
}

struct Data{
	int pos;
	int val;
}a[N];

struct OP{
	int id;
	int l;
	int r;
	int val;
}op[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;++ i){
		cin>>a[i].val;
		a[i].pos = i;
	}
	for(int i = 1;i <= m;++ i){
		cin>>op[i].l>>op[i].r>>op[i].val;
		op[i].id = i;
	}
	
	int cur = 1;
	sort(a + 1,a + n + 1,[&](const Data& A,const Data& B) -> bool { return A.val < B.val; });
	sort(op + 1,op + m + 1,[&](const OP& A,const OP& B) -> bool { return A.val < B.val; });
	while(cur <= m && op[cur].val < a[1].val){
		Ans[op[cur].id] = 0;
		cur ++;
	}
	for(int i = 1;i <= n;++ i){
		BIT::add(a[i].pos,1);
		if(i == n || a[i].val != a[i + 1].val){
			while(cur <= m && op[cur].val < a[i + 1].val){
				Ans[op[cur].id] = BIT::query(op[cur].r) - BIT::query(op[cur].l - 1);
				cur ++;
			}
		}
	}
	while(cur <= m){
		Ans[op[cur].id] = BIT::query(op[cur].r) - BIT::query(op[cur].l - 1);
		cur ++;
	}
	for(int i = 1;i <= m;++ i) cout<<Ans[i]<<"\n";
	return 0;
}
