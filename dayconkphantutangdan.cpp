#include <bits/stdc++.h>
using namespace std;

int n, k, ok, a[20], x[20];
vector<vector<int>> v;

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

bool check(){
	int cnt=0;
	for (int i=1; i<=n; i++) cnt+=x[i];
	return cnt==k;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i=1; i<=n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		v.clear();
		ok=1;
		ktao();
		while (ok){
			if (check()){
				vector<int>tmp(x+1,x+n+1);
				v.push_back(tmp);
			}
			sinh();
		}
		for (int i=v.size()-1; i>=0; i--){
			for (int j=0; j<v[i].size(); j++){
				if (v[i][j]==1){
					cout << a[j+1] << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
