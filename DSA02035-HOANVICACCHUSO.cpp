#include <bits/stdc++.h>
using namespace std;
int n,k,a[10];
vector<string> v;
long long res;
bool ok;
void SinhKt(){
	int i=k-1;
	while(i>=1&&a[i]>a[i+1]) --i;
	if(i==0) ok=true;
	else{
		int j=k;
		while(a[i]>a[j]) --j;
		swap(a[i],a[j]);
		for(int h=0; h<n;h++)
			swap(v[h][i-1],v[h][j-1]);
		reverse(a+i+1,a+k+1);
		for(int h=0;h<n;h++){
			reverse(v[h].begin()+i,v[h].end());
		}
	}
}
int main(){
	cin>>n>>k;
	v.resize(n);
	for(auto &x : v) cin>>x;
	for(int i=1;i<=k;i++) a[i]=i;
	res=10e9;
	ok=false; 
	while(!ok){
		vector<string> s=v;
		sort(s.begin(),s.end());
		res=min(res,stoll(s[n-1])-stoll(s[0]));
		SinhKt();
	}
	cout<<res<<endl;
	return 0;
}
