#include <bits/stdc++.h>
using namespace std;

queue<string>q;
vector<string>v;

void sieve(){
	q.push("6");
	q.push("8");
	while (1){
		string top = q.front(); q.pop();
		if (top.size()>=15) break;
		v.push_back(top);
		q.push(top+"6");
		q.push(top+"8");
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		int n; cin >> n;
		for (int i=v.size()-1; i>=0; i--){
			if (v[i].size()<=n) cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
