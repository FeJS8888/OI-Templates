#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
long long a[N];

namespace SegTree{
	#define l(p) t[(p)].l
	#define r(p) t[(p)].r
	#define dat(p) t[(p)].dat
	#define add(p) t[(p)].add
	#define lc(p) ((p) << 1)
	#define rc(p) ((p) << 1 | 1)
	#define len(p) (r(p) - l(p) + 1)
	struct node{
		int l;
		int r;
		long long dat;
		long long add;
	}t[N << 2];
	int cur = 0;
	
	inline void push_up(int p){
		dat(p) = dat(lc(p)) + dat(rc(p));
	}
	
	inline void do_cover(int p,long long d){
		add(p) += d;
		dat(p) += len(p) * d;
	}
	
	inline void push_down(int p){
		if(add(p)){
			do_cover(lc(p),add(p));
			do_cover(rc(p),add(p));
			add(p) = 0;
		}
	}
	
	inline void build(int p,int l,int r){
		l(p) = l;
		r(p) = r;
		add(p) = 0;
		if(l == r){
			dat(p) = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(p),l,mid);
		build(rc(p),mid + 1,r);
		push_up(p);
	}
	
	inline void change(int p,int l,int r,long long d){
		if(l <= l(p) && r >= r(p)){
			do_cover(p,d);
			return;
		}
		push_down(p);
		int mid = (l(p) + r(p)) >> 1;
		if(l <= mid) change(lc(p),l,r,d);
		if(r > mid) change(rc(p),l,r,d);
		push_up(p);
	}
	
	inline long long query(int p,int l,int r){
		if(l <= l(p) && r >= r(p)) return dat(p);
		push_down(p);
		int mid = (l(p) + r(p)) >> 1;
		long long ans = 0;
		if(l <= mid) ans += query(lc(p),l,r);
		if(r > mid) ans += query(rc(p),l,r);
		return ans;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;++ i) cin>>a[i];
	SegTree::build(1,1,n);
	for(int i = 1;i <= m;++ i){
		int op;
		cin>>op;
		if(op == 1){
			int l,r;
			long long k;
			cin>>l>>r>>k;
			SegTree::change(1,l,r,k);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<SegTree::query(1,l,r)<<"\n";
		}
	} 
	return 0;
}
