#include <bits/stdc++.h>
using namespace std;

int n, s, a[105], ok;
bool visited[105];

void Try (int sum, int cnt){
	if (cnt==2){
		ok=1; return;
	}
	if (ok) return;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			visited[i]=true;
			if (sum==s){
				Try(0,cnt+1);
			}
			else if (sum<s)
				Try(sum+a[i],cnt);
		}
		visited[i]=false;
	}
}

void inp(){
	memset(visited,false,sizeof(visited));
	cin >> n; s=0;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		s+=a[i];
	}
	if (s%2){
		cout << "NO\n"; return;
	}
	s/=2;
	Try(0,1);
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
	}
	return 0;
}
