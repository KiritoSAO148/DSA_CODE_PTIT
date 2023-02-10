#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> v;
int n, k, a[20], ok;

void init(){
	for (int i = 1; i <= k; ++i) a[i] = i;
}

void next(){
	int i = k;
	while (i >= 1 && a[i] == n - k +i) --i;
	if (i == 0) ok = 0;
	else{
		++a[i];
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		ok = 1;
		v.clear();
		init();
		while (ok){
			vector <int> tmp;
			for (int i = 1; i <= k; ++i){
				tmp.push_back(a[i]);
			}
			v.push_back(tmp);
			next();
		}
		for (int i = v.size() - 1; i >= 0; --i){
			for (int j = 0; j < v[i].size(); ++j) cout << v[i][j] << ' ';
			cout << "\n";
		}
	}
	return 0;
}
