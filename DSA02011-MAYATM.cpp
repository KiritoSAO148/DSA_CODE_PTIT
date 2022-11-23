#include <bits/stdc++.h>
using namespace std;

int n,s,a[35],ok,x[35],k;

void Try(int i){
	if (ok) return;
	for (int j=x[i-1]+1; j<=n-k+i; j++){
		x[i]=j;
		if (i==k){
			int sum=0;
			for (int j=1; j<=k; j++)
				sum+=a[x[j]];
			if (sum==s) ok=1;
		}else Try(i+1);
	}
}

void inp(){
	cin >> n >> s;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1,greater<int>());
	ok=0;
	for (int i=1; i<=n; i++){
		k=i;
		Try(1);
		if (ok){
			cout << i << endl;
			return;
		}
	}
	if (!ok) cout << -1 << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
	}
	return 0;
}
