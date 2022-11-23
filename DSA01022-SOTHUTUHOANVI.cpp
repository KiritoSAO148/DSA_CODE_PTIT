#include <bits/stdc++.h>
using namespace std;

int n,x[100],ok;
string s;
vector<string>ans;
vector<vector<string>>v;

void ktao(){
	for (int i=1; i<=n; i++) x[i]=i;
}

void sinh(){
	int i=n-1;
	while (i>=1 && x[i]>x[i+1]) --i;
	if (i==0) ok=false;
	else{
		int j=n;
		while (x[i]>x[j]) --j;
		swap(x[i],x[j]);
		reverse(x+i+1,x+n+1);
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		ans.clear();
		v.clear();
		cin >> n;
		cin.ignore();
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		while (ss>>tmp){
			ans.push_back(tmp);
		}
		ok=true;
		ktao();
		while (ok){
			vector<string>res;
			for (int i=1; i<=n; i++) res.push_back(to_string(x[i]));
			v.push_back(res);
			sinh();
		}
		for (int i=0; i<v.size(); i++){
			if (v[i]==ans) cout << i+1 << endl;
		}
	}
	return 0;
}
