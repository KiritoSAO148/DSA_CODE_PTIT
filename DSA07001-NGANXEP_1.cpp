#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back

int main(){
	string s;
	stack<int>st;
	while (cin >> s){
		if (s=="push"){
			int x; cin >> x;
			st.push(x);
		}
		if (s=="show"){
			if (st.empty()){
				cout << "empty\n";
			}
			else{
				vi v;
				while (!st.empty()){
					v.pb(st.top());
					st.pop();
				}
				for (int i=v.size()-1; i>=0; i--) st.push(v[i]);
				for (int i=v.size()-1; i>=0; i--) cout << v[i] << " ";
				cout << endl;
				v.clear();
			}
		}
		if (s=="pop"){
			if (st.empty()) cout << "empty\n";
			else st.pop();
		}
	}
	return 0;
}
