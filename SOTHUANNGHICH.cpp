#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		int ans=0;
		for (int i=0; i<s.size(); i++){
			int l=i, r=i+1;
			int cnt=0;
			while (l>=0 && r<s.size()){
				if (s[l]!=s[r]) break;
				else{
					cnt+=2;
					--l;++r;
				}
			}
			ans=max(ans,cnt);
		}
		for (int i=1; i<s.size(); i++){
			int l=i-1, r=i+1;
			int cnt=1;
			while (l>=0 && r<s.size()){
				if (s[l]!=s[r]) break;
				else{
					cnt+=2;
					--l;++r;
				}
			}
			ans=max(ans,cnt);
		}
		cout << ans << "\n";
	}
	return 0;
}
