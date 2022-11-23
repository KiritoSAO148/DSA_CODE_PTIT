#include <bits/stdc++.h>
using namespace std;

int n,a[1005],k;
bool ok;
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void ktao(){
	for (int i=1; i<=k; i++) a[i]=i;
}

void sinh(){
	int i=k;
	while (i>=1 && a[i]==n-k+i) --i;
	if (i==0) ok=false;
	else{
		++a[i];
		for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
	}
}

void in(){
	for (int i=1; i<=k; i++) cout << s[a[i]-1];
	cout << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		ok=true;
		ktao();
		while (ok){
			in();
			sinh();
		}
	}
	return 0;
}
