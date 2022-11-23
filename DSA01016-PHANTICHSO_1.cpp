#include <bits/stdc++.h>
using namespace std;

int a[50];

void in (int m){
	cout << "(";
	for (int i=1; i<m; i++) cout << a[i] << " ";
	cout << a[m] << ") ";
}

void Try (int pos, int i, int sum){
	for (int j=pos; j>=1; j--){
		a[i]=j;
		if (j==sum) in(i);
		else if (j<sum) Try(j,i+1,sum-j);
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Try(n,1,n);
		cout << endl;
	}
	return 0;
}
