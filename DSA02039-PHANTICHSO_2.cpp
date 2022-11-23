#include <bits/stdc++.h>
using namespace std;

int n, a[15];
vector<vector<int>> v;

void Try (int pos, int i, int sum){
	for (int j=pos; j>=1; j--){
		a[i]=j;
		if (j==sum){
			vector<int>res(a+1,a+i+1);
			v.push_back(res);
		}
		else if (j<sum) Try(j,i+1,sum-j);
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		v.clear();
		Try(n,1,n);
		cout << v.size() << endl;
		for (auto it : v){
			cout << "(";
			for (int i=0; i<it.size(); i++){
				cout << it[i];
				if (i==it.size()-1) cout << ") ";
				else cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
