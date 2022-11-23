#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	deque<int>dq;
	while (t--){
		string s; cin >> s;
		if (s=="PUSHFRONT"){
			int x; cin >> x;
			dq.push_front(x);
		}
		if (s=="PRINTFRONT"){
			if (dq.empty()) cout << "NONE\n";
			else cout << dq.front() << endl;
		}
		if (s=="POPFRONT"){
			if (!dq.empty()) dq.pop_front();
		}
		if (s=="PUSHBACK"){
			int x; cin >> x;
			dq.push_back(x);
		}
		if (s=="PRINTBACK"){
			if (dq.empty()) cout << "NONE\n";
			else cout << dq.back() << endl;
		}
		if (s=="POPBACK"){
			if (!dq.empty()) dq.pop_back();
		}
	}
	return 0;
}
