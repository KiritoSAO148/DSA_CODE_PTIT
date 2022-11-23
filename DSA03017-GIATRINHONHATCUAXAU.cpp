#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int k; cin >> k;
		string s; cin >> s;
		map<char,int>mp;
		for (int i=0; i<s.size(); i++) mp[s[i]]++;
		priority_queue<int>q;
		for (auto it : mp) q.push(it.second);
		while (k--){
			int tmp=q.top();
			--tmp;
			q.pop();
			q.push(max(tmp,0));
		}
		long long ans=0;
		while (!q.empty()){
			ans+=q.top()*q.top();
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
