#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int k; cin >> k;
		string s; cin >> s;
		map<char,long long>mp;
		for (int i=0; i<s.size(); i++) mp[s[i]]++;
		priority_queue<long long>q;
		for (auto it : mp) q.push(it.second);
		while (k--){
			long long tmp=q.top();
			--tmp;
			q.pop();
			if (tmp>0) q.push(tmp);
			else q.push(0);
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

