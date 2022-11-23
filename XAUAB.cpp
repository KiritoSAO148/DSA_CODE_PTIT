#include <bits/stdc++.h>
using namespace std;

int n, x[15], ok;
vector<string>v;

void ktao(){
	for (int i=1; i<=n; i++) x[i]=0;
}

void sinh(){
	int i=n;
	while (i>=1 && x[i]==1){
		x[i]=0;
		--i;
	}
	if (i==0) ok=false;
	else x[i]=1;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		v.clear();
		ok=1;
		ktao();
		while (ok){
			string tmp="";
			for (int i=1; i<=n; i++){
				if (x[i]==0) tmp+="A";
				else tmp+="B";
			}
			v.push_back(tmp);
			sinh();
		}
		for (int i=0; i<v.size()-1; i++){
			cout << v[i] << ",";
		}
		cout << v[v.size()-1];
		cout << endl;
	}
	return 0;
}
