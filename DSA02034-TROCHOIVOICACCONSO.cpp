#include <bits/stdc++.h>
using namespace std;

int n, a[30], used[30];

void in(){
	for (int i=1; i<=n; i++) cout << a[i];
	cout << endl;
}

bool check(){
	for (int i=1; i<n; i++){
		if (abs(a[i]-a[i+1])==1) return false;
	}
	return true;
}

void Try (int i){
	for (int j=1; j<=n; j++){
		if (!used[j]){
			a[i]=j;used[j]=1;
			if (i==n){
				if (check()) in();
			}else Try(i+1);
			used[j]=0;
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		memset(a,0,sizeof(a));
		memset(used,0,sizeof(used));
		Try(1);
	}
	return 0;
}
