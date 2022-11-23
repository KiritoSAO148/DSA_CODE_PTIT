#include <bits/stdc++.h>
using namespace std;

queue<string>q; int n;
using ll = long long;
vector<string>v;
#define pb push_back

void sieve(){
	q.push("1");
	while (1){
		string top=q.front(); q.pop();
		if (top.size()>14) break;
		v.pb(top);
		q.push(top+"0");
		q.push(top+"1");
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
