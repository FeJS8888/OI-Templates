#include<bits/stdc++.h>
using namespace std;
const int N = 102;
const int mod = 1e9 + 7;
 
class Matrix{
	public:
		int n;
		long long data[N][N];
		
		Matrix(int n):n(n) {
			memset(data,0,sizeof(data));
		};
}; 

Matrix operator*(Matrix& A,Matrix& B){
	Matrix C(A.n);
	for(int i = 1;i <= A.n;++ i){
		for(int j = 1;j <= B.n;++ j){
			for(int k = 1;k <= A.n;++ k){
				C.data[i][j] += A.data[i][k] * B.data[k][j];
				C.data[i][j] %= mod;
			}
		}
	}
	return C;
}

inline Matrix qpow(Matrix base,long long times){
	Matrix ans(base.n);
	for(int i = 1;i <= base.n;++ i) ans.data[i][i] = 1;
	while(times){
		if(times & 1) ans = ans * base;
		base = base * base;
		times >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long k;
	cin>>n>>k;
	Matrix A(n);
	for(int i = 1;i <= n;++ i){
		for(int j = 1;j <= n;++ j){
			cin>>A.data[i][j];
		}
	}
	A = qpow(A,k);
	for(int i = 1;i <= n;++ i){
		for(int j = 1;j <= n;++ j){
			cout<<A.data[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
