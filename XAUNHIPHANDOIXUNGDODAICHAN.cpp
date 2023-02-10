#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> v;

void init(){
	queue<string>q;
	q.push("0");
	q.push("1");
	while (true){
		string top = q.front(); q.pop();
		if (top.size()>15) break;
		string tmp = top;
		reverse(top.begin(),top.end());
		v.push_back(tmp+top);
		q.push(tmp+"0");
		q.push(tmp+"1");
	}
}

int main(){
	int t; cin >> t;
	init();
	while (t--){
		cin >> n;
		for (string x : v){
			if (x.size() <= n) cout << x << ' ';
			else break;
		}
		cout << "\n";
	}
	return 0;
}
