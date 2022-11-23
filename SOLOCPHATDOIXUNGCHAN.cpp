#include <bits/stdc++.h>
using namespace std;

vector<string>v;

void sieve(){
	queue<string>q;
	q.push("6");
	q.push("8");
	while (1){
		string top = q.front(); q.pop();
		if (top.size()>13) break;
		string tmp = top;
		reverse(top.begin(),top.end());
		v.push_back(tmp+top);
		q.push(top+"6");
		q.push(top+"8");
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		int n; cin >> n;
		cout << v.size() << endl;
		for (int i=0; i<n; i++) cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
