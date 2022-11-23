#include <bits/stdc++.h>
using namespace std;

int n, a[10], ok;
vector<string>hoanvi,chinhhop;

void ktao(){
	for (int i=1; i<=n; i++) a[i]=1;
}

void sinh(){
	int i=n;
	while (i>=1 && a[i]==n) --i;
	if (i==0) ok=false;
	else{
		++a[i];
		for (int j=i+1; j<=n; j++) a[j]=1;
	}
}

int main(){
	cin >> n;
	string s="";
	for (int i=1; i<=n; i++) s+='A'+i-1;
	do{
		hoanvi.push_back(s);
	}while (next_permutation(s.begin(),s.end()));
	ok=1;
	ktao();
	while (ok){
		string tmp="";
		for (int i=1; i<=n; i++) tmp+=to_string(a[i]);
		chinhhop.push_back(tmp);
		sinh();
	}
	for (auto x : hoanvi){
		for (auto y : chinhhop) cout << x << y << endl;
	}
	return 0;
}
