#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int tinh(int s, int t){
	queue<pi>q;
	set<int>se1;
	q.push({s,0});
	while (!q.empty()){
		pi top = q.front(); q.pop();
		if (top.first==t) return top.second;
		if (top.first-1==t || top.first*2==t) return top.second+1;
		se1.insert(top.first);
		if (top.first>=1 && !se1.count(top.first-1)) q.push({top.first-1,top.second+1});
		if (top.first<t && !se1.count(top.first*2)) q.push({top.first*2,top.second+1});
	}
	return 0;
}

int main(){
	int t; cin >> t;
	while (t--){
		int s,t; cin >> s >> t;
		cout << tinh(s,t) << endl;
	}
	return 0;
}
