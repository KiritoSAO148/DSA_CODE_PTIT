#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
int n, k, x[25], ok;

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
		cin >> n >> k;
		ok=1;
		ktao();
		while (ok){
			vector<int>res(x+1,x+k+1);
			v.push_back(res);
			sinh();
		}
		for (int i=v.size()-1; i>=0; i--){
			for (int x : v[i]) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}
