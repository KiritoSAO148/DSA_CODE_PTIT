#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n,m,k;
 
void inp(){
	cin>>n>>m>>k;
	ll a[n],b[m],c[k];
	for (int i=0; i<n; i++) cin>>a[i];
	for (int i=0; i<n; i++) cin>>b[i];
	for (int i=0; i<n; i++) cin>>c[i];
	int i=0,j=0,l=0;
	vector<ll> res;
	while(i<n && j<m && l<k){
		if(a[i]==b[j] && b[j]==c[l]){
			res.push_back(a[i]);
			++i;++j;++l;
		}
		else if(a[i]<=b[j] && a[i]<=c[l]){
			++i;
		}
		else if(b[j]<=a[i] && b[j]<=c[l]){
			++j;
		}
		else
			++l;
	}
	if(res.size()==0){
		cout<<"-1\n";
		return;
	}
	for(ll x : res)
		cout<<x<<" ";
	cout<<"\n";
}
 
int main(){
	int t;cin>>t;
	while(t--){
		inp();
	}
	return 0;
}
