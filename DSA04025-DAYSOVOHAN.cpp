#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
using ll = long long;

struct Matran{
	ll f[2][2];
};

Matran operator * (Matran A, Matran B){
	Matran C;
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			C.f[i][j]=0;
			for (int k=0; k<2; k++){
				C.f[i][j]=(C.f[i][j]+A.f[i][k]*B.f[k][j]%MOD)%MOD;
			}
		}
	}
	return C;
}

Matran powMod(Matran A, int k){
	if (k==1) return A;
	Matran X=powMod(A,k/2);
	if (k%2==0) return X*X;
	return A*X*X;
}

int main(){
	int t; cin >> t;
	while (t--){
		int k; cin >> k;
		Matran A;
		A.f[0][0]=1; A.f[0][1]=1; A.f[1][0]=1; A.f[1][1]=0;
		Matran KQ=powMod(A,k);
		cout << KQ.f[1][0] << endl;
	}
	return 0;
}
