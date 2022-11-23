#include <bits/stdc++.h>
using namespace std;

vector<string>v;

bool check (string s){
	if (s.size()%2!=0) return false;
	int i=0, j=s.size()-1;
	while (i<j){
		if (s[i]!=s[j]) return false;
		++i;--j;
	}
	return true;
}

void sieve(){
	queue<string>q;
	q.push("4");
	q.push("5");
	while (1){
		string top = q.front(); q.pop();
		if (top.size()>12) break;
		if (check(top)) v.push_back(top);
		q.push(top+"4");
		q.push(top+"5");
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		int n; cin >> n;
		for (int i=0; i<n; i++) cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}
