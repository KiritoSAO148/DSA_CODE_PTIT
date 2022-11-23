#include <bits/stdc++.h>
using namespace std;

int C[1001][1001];
const int MOD = 1e9+7;

void init(){
	for (int i=0; i<=1000; i++){
		for (int j=0; j<=i; j++){
			if (j==0 || j==i){
				C[i][j]=1;
			}else{
				C[i][j]=C[i-1][j]+C[i-1][j-1];
				C[i][j]%=MOD;
			}
		}
	}
}

int main(){
	int t; cin >> t;
	init();
	while (t--){
		int n,k; cin >> n >> k;
		cout << C[n][k] << endl;
	}
	return 0;
}
