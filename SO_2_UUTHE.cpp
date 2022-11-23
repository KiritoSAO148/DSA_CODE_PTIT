#include <bits/stdc++.h>
using namespace std;

vector<string>v;

bool check (string s){
	int cnt=0;
	for (int i=0; i<s.size(); i++){
		if (s[i]=='2') ++cnt;
	}
	if (cnt>s.size()/2 && s[0]!='0') return true;
	return false;
}

void init(){
	queue<string>q;
	q.push("0");
	q.push("1");
	q.push("2");
	int l=0;
	while (l<=10){
		string top=q.front(); q.pop();
		if (check(top)) v.push_back(top);
		q.push(top+"0");
		q.push(top+"1");
		q.push(top+"2");
		l=q.front().size();
	}
}

int main(){
	int t; cin >> t;
	init();
	while (t--){
		int n; cin >> n;
		for (int i=0; i<n; i++) cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}
