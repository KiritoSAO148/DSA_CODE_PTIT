#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		sort(s.begin(), s.end());
		vector <int> v;
		do{
			v.push_back(stoi(s));
		}while (next_permutation(s.begin(), s.end()));
		for (int x : v) cout << x << '\n';
	}
	return 0;
}
