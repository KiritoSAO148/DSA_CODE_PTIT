#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		bool ok=false;
		vector<int>v;
		map<int,int>mp;
		for (int i=0; i<n; i++){
			int x; cin >> x;
			mp[x]++;
			v.push_back(x);
		}
		for (int i=0; i<v.size(); i++){
			if (mp[v[i]]>1){
				cout << v[i] << endl;
				ok=true;
				break;
			}
		}
		if (ok==false) cout << "NO\n";
	}
	return 0;
}
