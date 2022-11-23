#include <bits/stdc++.h>
using namespace std;

int cnt, int m, int d;
vector<string>v;

bool check(string s){
	for (int i=0; i<s.size(); i++){
		if (i%2==0){
			if (stoi(s[i])!=d) return false;
		}
	}
	if (stoll(s)%m==0) return true;
	return false;
}

int main(){
	cin >> m >> d;
	int a,b; cin >> a >> b;
	for (int i=a; i<=b; i++){
		if (check(to_string(i))) ++cnt;
	}
	cout << cnt << endl;
	return 0;
}
