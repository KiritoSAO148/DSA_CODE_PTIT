#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	ll s1=0, s2=0, s3=0, s4=0;
	sort(a,a+n);
	s1=a[0]*a[1];
	s2=a[n-1]*a[n-2];
	s3=a[n-1]*a[n-2]*a[n-3];
	s4=a[0]*a[1]*a[n-1];
	ll ans=max(s1,s2);
	ll res=max(s3,s4);
	cout << max(ans,res);
}
