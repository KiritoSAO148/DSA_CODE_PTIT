#include <bits/stdc++.h>
using namespace std;
 
int a[1000001];
void init(){
	int n = 1000000;
	for (int i=1; i<= n; i++)
		a[i]=0;
	a[0]=0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n/i; j++){
			a[j*i]+=i;
		}
	}
}
 
int main (){
	int L, R;
	cin>>L>>R;
	init();
	int cnt=0;
	for (int i=L; i<=R; i++){
		if (a[i]-i>i) cnt++;
	}
	cout<<cnt;
	return 0;
}
