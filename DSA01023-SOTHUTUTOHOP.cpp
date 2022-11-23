#include <bits/stdc++.h>
using namespace std;

int n,k,x[100],ok;
string s;
vector<string> ans;
vector<vector<string>>v;

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
	int t; cin >> t;
	while (t--){
		v.clear();
		ans.clear();
		cin >> n >> k;
		cin.ignore();
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		while (ss>>tmp){
			ans.push_back(tmp);
		}
		//for (auto it : ans) cout << it;
		//cout << endl;
		ok=true;
		ktao();
		while (ok){
			vector<string>res;
			for (int i=1; i<=k; i++){
				res.push_back(to_string(x[i]));
			}
			v.push_back(res);
			sinh();
		}
		//for (int i=0; i<v.size(); i++){
		//	for (int j=0; j<v[i].size(); j++) cout << v[i][j];
		//	cout << endl;
		//}
		for (int i=0; i<v.size(); i++){
			if (v[i]==ans) cout << i+1 << endl;
		}
	}
	return 0;
}
