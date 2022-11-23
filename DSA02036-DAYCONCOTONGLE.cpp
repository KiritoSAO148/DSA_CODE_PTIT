#include <bits/stdc++.h>
using namespace std;

int n,a[101],x[101];
vector<vector<int>> res;

void inp(){
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1,greater<int>());
	res.clear();
}

void Try(int i, int sum, int pos){
	if (sum%2){
		vector <int> tmp(x+1,x+i);
		res.push_back(tmp);
	}
	for (int j=pos; j<=n; j++){
		x[i]=a[j];
		Try(i+1,sum+a[j],j+1);
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
		Try(1,0,1);
		for (auto it : res) sort(it.begin(),it.end());
		sort(res.begin(),res.end());
		for (auto it : res){
			for (int x : it){
				cout << x << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
