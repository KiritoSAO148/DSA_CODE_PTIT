#include <bits/stdc++.h>
using namespace std;

int n, a[25], x[25], s, ok;

void inp(){
	cin >> n >> s;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
}

void Try(int i, int sum, int pos){
	if (sum==s){
		cout << "[";
		for (int j=1; j<i; j++){
			cout << x[j];
			if (j==i-1) cout << "]";
			else cout << " ";
		}
		ok=1;
	}
	for (int j=pos; j<=n; j++){
		if (sum+a[j]<=s && a[j]>=x[i-1]){
			x[i]=a[j];
			Try(i+1,sum+a[j],j);
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
		ok=0;
		Try(1,0,1);
		if (!ok) cout << -1;
		cout << endl;
	}
	return 0;
}
