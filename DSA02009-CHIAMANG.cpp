#include <bits/stdc++.h>
using namespace std;

int n, ok, s, k, a[30];
bool visited[30];

void Try (int sum, int cnt){
	if (cnt==k){
		ok=1; return;
	}
	if (ok) return;
	for (int i=1; i<=n; i++){
		if (!visited[i]){
			visited[i]=true;
			if (sum==s)
				Try(0,cnt+1);
			else if (sum<s)
				Try(sum+a[i],cnt);
		}
		visited[i]=false;
	}
}

void inp(){
	cin >> n >> k;
	s=0, ok=0;
	memset(visited,false,sizeof(visited));
	for (int i=1; i<=n; i++){
		cin >> a[i];
		s+=a[i];
	}
	if (s%k){
		cout << 0 << endl;
		return;
	}
	Try(0,0);
	cout << ok << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
	}
	return 0;
}
