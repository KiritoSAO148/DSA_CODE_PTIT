#include <bits/stdc++.h>
using namespace std;

int n,x[101];
string s;
vector <string> v;
int ok;

void ktao(){
	for (int i=0; i<n; i++) x[i]=0;
}

void sinh(){
	int i=n-1;
	while (i>=0 && x[i]==1){
		x[i]=0;
		--i;
	}
	if (i==-1) ok=false;
	else x[i]=1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		v.clear();
		ktao();
		ok=true;
		while (ok){
			string res="";
			for (int i=0; i<n; i++){
				if (x[i]) res+=s[i];
			}
			v.push_back(res);
			sinh();
		}
		sort(v.begin(),v.end());
		for (string x : v) cout << x << " ";
		cout << endl;
	}
}
