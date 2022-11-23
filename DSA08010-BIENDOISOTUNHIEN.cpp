#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int solve(int n){
	queue<pi>q;
	unordered_set<int>s;
	s.insert(n);
	q.push({n,0});
	while (!q.empty()){
		pi top=q.front(); q.pop();
		if (top.first==1) return top.second;
		for (int i=2; i<=sqrt(top.first); i++){
			if (top.first%i==0){
				int m=max(i,top.first/i);
				if (!s.count(m)){
					q.push({m,top.second+1});
					s.insert(m);
				}
			}
		}
		if (!s.count(top.first-1)){
			q.push({top.first-1,top.second+1});
			s.insert(top.first-1);
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
