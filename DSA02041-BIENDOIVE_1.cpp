#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
#define fi first
#define se second

int tinh(int n){
	queue<pi>q;
	q.push({n,0});
	while (!q.empty()){
		pi top = q.front(); q.pop();
		if (top.fi==1) return top.se;
		if (top.fi%3==0) q.push({top.fi/3,top.se+1});
		if (top.fi%2==0) q.push({top.fi/2,top.se+1});
		if (top.fi>1) q.push({top.fi-1,top.se+1});
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		cout << tinh(n) << endl;
	}
	return 0;
}
