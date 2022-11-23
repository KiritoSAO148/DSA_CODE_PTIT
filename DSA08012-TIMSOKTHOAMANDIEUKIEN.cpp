#include <bits/stdc++.h>
using namespace std;

bool check(string s){
	int cnt[10]={0};
	for (int i=0; i<s.size(); i++){
		if (s[i]-'0'>5) return false;
		cnt[s[i]-'0']++;
	}
	for (int i=0; i<10; i++){
		if (cnt[i]>1) return false;
	}
	return true;
}

int main(){
	int t; cin >> t;
	while (t--){
		int L,R; cin >> L >> R;
		int cnt=0;
		for (int i=L; i<=R; i++){
			if (check(to_string(i))) ++cnt;
		}
		cout << cnt << endl;
	}
	return 0;
}
