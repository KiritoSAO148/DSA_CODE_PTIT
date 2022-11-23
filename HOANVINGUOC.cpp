#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, x[15], ok;
vector<string>v;

void init(){
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		cin >> n;
		ok=1;
		init();
		v.clear();
		while (ok){
			string tmp="";
			for (int i=1; i<=n; i++){
				tmp+=to_string(x[i]);
			}
			v.push_back(tmp);
			sinh();
		}
		for (int i=v.size()-1; i>=0; i--){
			cout << v[i];
			if (i!=0) cout << ",";
			else cout << endl;
		}
	}
	return 0;
}
