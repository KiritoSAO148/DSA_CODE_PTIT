#include <bits/stdc++.h>
using namespace std;

int n,s,a[35],kq=1000;

void Try(int i, int sum, int x){
	if (sum>s || x>kq) return;
	if (i==n){
		if (sum==s){
			kq=min(kq,x);
		}
		return;
	}
	Try(i+1,sum,x);
	Try(i+1,sum+a[i],x+1);
}

int main(){
	cin >> n >> s;
	for (int i=0; i<n; i++) cin >> a[i];
	Try(0,0,0);
	if (kq==1000) cout << -1;
	else cout << kq;
}
