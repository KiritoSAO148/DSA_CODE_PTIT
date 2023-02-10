#include <bits/stdc++.h>
using namespace std;

int n, k, a[25], b[25], ok;
vector <vector<int>> v;

void init(){
	for (int i = 1; i <= k; ++i) a[i] = i;
}

void next(){
	int i = k;
	while (i >= 1 && a[i] == n - k + i) --i;
	if (i == 0) ok = 0;
	else{
		++a[i];
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> b[i];
	sort(b + 1, b + n + 1);
	ok = 1;
	init();
	while (ok){
		vector <int> tmp;
		for (int i = 1; i <= k; ++i) tmp.push_back(b[a[i]]);
		sort(tmp.begin(), tmp.end());
		v.push_back(tmp);
		next();
	}
	for (auto it : v){
		for (int x : it) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
