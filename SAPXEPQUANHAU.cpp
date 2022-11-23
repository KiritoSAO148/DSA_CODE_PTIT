#include <bits/stdc++.h>
using namespace std;

int x[100], n=8, cot[100], d1[100], d2[100], ans=0, a[100][100];
int cnt=0;

void inp(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cin >> a[i][j];
	}
	memset(cot,0,sizeof(cot));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
}

void Try(int i){
	for (int j=1; j<=n; j++){
		if (cot[j]==0 && d1[i-j+n]==0 && d2[i+j-1]==0){
			x[i]=j;
			cot[j]=1;
			d1[i-j+n]=1;
			d2[i+j-1]=1;
			if (i==n){
				int sum=0;
				for (int k=1; k<=n; k++) sum+=a[k][x[k]];
				ans=max(ans,sum);
			}
			Try(i+1);
			cot[j]=0;
			d1[i-j+n]=0;
			d2[i+j-1]=0;
		}
	}
}

int main(){
	int t; cin >> t;
	for (int i=1; i<=t; i++){
		inp();
		ans=0;
		Try(1);
		cout << "Test " << i << ": " << ans << endl;
	}
	return 0;
}
