#include <bits/stdc++.h>
using namespace std;

int a[10]={1,2,5,10,20,50,100,200,500,1000};

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		sort(a,a+10,greater<int>());
		int i=0;
		int ans=0;
		while (n>0){
			int tmp=n/a[i];
			ans+=tmp;
			n-=tmp*a[i];
			++i;
		}
		cout << ans << endl;
	}
	return 0;
}
