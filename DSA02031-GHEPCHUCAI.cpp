#include <bits/stdc++.h>
using namespace std;

int n, used[30]; char a[30], c;

bool check(){
	for (int i=2; i<n; i++){
		if (a[i]=='A' && a[i-1]!='E' && a[i+1]!='E') return false;
		if (a[i]=='E' && a[i-1]!='A' && a[i+1]!='A') return false;
	}
	return true;
}

void in(){
	for (int i=1; i<=n; i++) cout << a[i];
	cout << endl;
}

void Try(int i){
	char j;
	for (j='A'; j<=c; j++){
		if (used[j]==0){
			a[i]=j;used[j]=1;
			if (i==n){
				if (check()) in();
			}
			else Try(i+1);
			used[j]=0;
		}
	}
}

int main(){
	cin >> c; n=(c-'A')+1;
	Try(1);
}
