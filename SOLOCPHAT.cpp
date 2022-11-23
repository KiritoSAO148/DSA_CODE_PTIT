#include <bits/stdc++.h>
using namespace std;

vector<string>v;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		v.clear();
		queue<string>q;
		q.push("6");
		q.push("8");
		int l=0;
		while (l<=n){
			string s=q.front(); q.pop();
			if (s.size()==n) v.push_back(s);
			q.push(s+"6");
			q.push(s+"8");
			l=q.front().size();
		}
		cout << v.size() << endl;
		for (string x : v) cout << x << " ";
		cout << endl;
	}
	return 0;
}
