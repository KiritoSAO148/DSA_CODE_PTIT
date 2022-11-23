#include <bits/stdc++.h>
using namespace std;

int n,k;
char c;
char a[100];
bool ok;

void ktao(){
	for (int i=1; i<=k; i++){
		a[i]='A';
	}
}

void sinh(){
	int i=k;
	while (i>=1 && a[i]==c){
		--i;
	}
	if (i==0){
		ok=false;
	}else{
		a[i]++;
		for (int j=i+1; j<=k; j++){
			a[j]=a[i];
		}
	}
}

int main(){
	cin >> c >> k;
	n=c-'A'+1;
	ok=true;
	ktao();
	while (ok){
		for (int i=1; i<=k; i++){
			cout << a[i];
		}
		cout << endl;
		sinh();
	}
	return 0;
}
