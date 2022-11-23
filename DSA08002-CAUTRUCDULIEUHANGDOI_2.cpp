#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	queue<int>q;
	while (t--){
		string s; cin >> s;
		if (s=="PUSH"){
			int x; cin >> x;
			q.push(x);
		}
		if (s=="PRINTFRONT"){
			if (q.empty()) cout << "NONE\n";
			else cout << q.front() << endl;
		}
		if (s=="POP"){
			if (!q.empty()) q.pop();
		}
	}
	return 0;
}
