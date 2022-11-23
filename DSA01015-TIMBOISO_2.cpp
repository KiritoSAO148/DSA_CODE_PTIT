#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
vector<ull>v;

void sieve(){
	queue<ull>q;
	q.push(9);
	while (1){
		ull top = q.front(); q.pop();
		if (top>1e12) break;
		v.push_back(top);
		q.push(top*10);
		q.push(top*10+9);
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		int n; cin >> n;
		for (ull x : v){
			if (x%n==0){
				cout << x << "\n";
				break;
			}
		}
	}
	return 0;
}
