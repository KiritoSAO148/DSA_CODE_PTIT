#include <bits/stdc++.h>
using namespace std;

queue<string>q;
vector<string>v;
int n;
#define pb push_back

void sieve(){
	q.push("9");
	while (1){
		string top=q.front(); q.pop();
		if (top.size()>8) break;
		v.pb(top);
		q.push(top+"0");
		q.push(top+"9");
	}
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		cin >> n;
		for (int i=0; i<v.size(); i++){
			if (stoll(v[i])%n==0){
				cout << v[i] << endl; break;
			}
		}
	}
	return 0;
}
