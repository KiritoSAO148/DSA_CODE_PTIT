#include <bits/stdc++.h>
using namespace std;

int n,k,ok,x[101];
string a[101];
set <string> s;

void ktao(){
	for (int i=1; i<=k; i++) x[i]=i;
}

void sinh(){
	int i=k;
	while (i>=1 && x[i]==n-k+i) --i;
	if (i==0) ok=false;
	else{
		++x[i];
		for (int j=i+1; j<=k; j++) x[j]=x[j-1]+1;
	}
}

int main(){
	cin >> n >> k;
	int d=1;
	for (int i=1; i<n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	for (auto x : s){
		a[d]=x;
		++d;
	}
	n=d-1;
	ktao();
	ok=true;
	while (ok){
		for (int i=1; i<=k; i++){
			cout << a[x[i]] << " ";
		}
		cout << endl;
		sinh();
	}
	return 0;
}
