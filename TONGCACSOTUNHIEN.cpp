#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
int x[15], n;

void Try(int pos, int i, int sum){
	for (int j=pos; j>=1; j--){
		x[i]=j;
		if (j==sum){
			vector<int>res(x+1,x+i+1);
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
		for (int i=0; i<v.size(); i++){
			cout << "(";
			for (int j=0; j<v[i].size(); j++){
				cout << v[i][j];
				if (j==v[i].size()-1) cout << ") ";
				else cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
