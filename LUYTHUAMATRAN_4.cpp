#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using ll = long long;
int n; ll k;

struct Matrix{
	ll f[15][15];
};

Matrix operator * (Matrix A, Matrix B){
	Matrix C;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			C.f[i][j]=0;
			for (int k=0; k<n; k++){
				C.f[i][j]=(C.f[i][j]+A.f[i][k]*B.f[k][j]%MOD)%MOD;
			}
		}
	}
	return C;
}

Matrix powMod (Matrix A, ll k){
	if (k==1) return A;
	Matrix X = powMod(A,k/2);
	if (k%2==0) return X*X;
	return A*X*X;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		Matrix A;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++) cin >> A.f[i][j];
		}
		Matrix ans=powMod(A,k);
		ll sum=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (i==0) sum+=ans.f[i][j];
				sum%=MOD;
			}
		}
		cout << sum << endl;
	}
}
