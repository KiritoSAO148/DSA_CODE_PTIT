#include <bits/stdc++.h>
using namespace std;

int n,k,X[100];
string a[100];
set <string> s;

void in(){
	for (int i=1; i<=k; i++){
		cout << a[X[i]] << " ";
	}
	cout << endl;
}

void Try(int i){
	for (int j=X[i-1]+1; j<=n-k+i; ++j){
		X[i]=j;
		if (i==k){
			in();
		}else{
			Try(i+1);
		}
	}
}

int main(){
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	int d=1;
	for (auto x : s){
		a[d]=x;
		++d;
	}
	n=d-1;
	Try(1);
	return 0;
}
