#include <bits/stdc++.h>
using namespace std;

int n, A[25], B[25];

bool check(){
	for (int i=1; i<n; i++){
		if (abs(A[i]-A[i+1])==1) return false;
	}
	return true;
}

void in(){
	for (int i=1; i<=n; i++) cout << A[i];
	cout << endl;
}

void Try(int i){
	for (int j=1; j<=n; j++){
		if (B[j]==0){
			A[i]=j; B[j]=1;
			if (i==n){
				if (check()) in();
			}else Try(i+1);
			B[j]=0;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		cin >> n;
		Try(1);
	}
	return 0;
}
