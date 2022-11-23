#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
queue<ull>q;
vector<ull>v;
#define pb push_back

void sieve(){
	q.push(1);
	while (1){
		ull top = q.front(); q.pop();
		if (top>1e17) break;
		v.pb(top);
		q.push(top*10);
		q.push(top*10+1);
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		ull n; cin >> n;
		int cnt=0;
		for (int i=0; i<v.size(); i++){
			if (v[i]<=n) ++cnt;
			else break;
		}
		cout << cnt << endl;
	}
	return 0;
}
