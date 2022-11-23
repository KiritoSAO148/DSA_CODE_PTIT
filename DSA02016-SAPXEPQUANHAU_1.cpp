#include <bits/stdc++.h>
using namespace std;

int a[100], n, cot[100], d1[100], d2[100], cnt;

void ktao(){
	memset(cot,0,sizeof(cot));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
}

void Try(int i){
	for (int j=1; j<=n; j++){
		if (cot[j]==0 && d1[i-j+n]==0 && d2[i+j-1]==0){
			a[i]=j;
			cot[j]=1;
			d1[i-j+n]=1;
			d2[i+j-1]=1;
			if (i==n) ++cnt;
			else Try(i+1);
			cot[j]=0;
			d1[i-j+n]=0;
			d2[i+j-1]=0;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		ktao();
		cnt=0;
		Try(1);
		cout << cnt << endl;
	}
	return 0;
}
