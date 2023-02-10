#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	vector <vector<int>> v;
	for (int i = 0; i < n; ++i) a[i] = i + 1;
	do{
		vector <int> tmp(a, a + n);
		v.push_back(tmp);
	}while (next_permutation(a, a + n));
	for (int i = 0; i < v.size(); ++i){
		cout << i + 1 << ": ";
		for (int j = 0; j < v[i].size(); ++j) cout << v[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
