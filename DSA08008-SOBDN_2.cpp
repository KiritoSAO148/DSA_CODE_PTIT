#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
vector<ull>v;
queue<ull>q;
#define pb push_back

void sieve(){
	q.push(1);
	while (1){
		ull top = q.front(); q.pop();
		if (top>1e19) break;
		v.pb(top);
		q.push(top*10);
		q.push(top*10+1);
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		int n; cin >> n;
		for (int i=0; i<v.size(); i++){
			if (v[i]%n==0){
				cout << v[i] << endl; break;
			}
		}
	}
	return 0;
}
