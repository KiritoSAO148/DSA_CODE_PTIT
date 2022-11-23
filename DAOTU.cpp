#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; getline(cin,s);
		queue<string>q;
		stringstream ss(s);
		string token="";
		while (ss>>token) q.push(token);
		while (!q.empty()){
			string top = q.front(); q.pop();
			for (int i=top.size()-1; i>=0; i--) cout << top[i];
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}
