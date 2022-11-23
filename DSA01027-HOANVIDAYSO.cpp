#include <bits/stdc++.h>
using namespace std;

int n,a[100],x[100],ok;

void ktao(){
	for (int i=1; i<=n; i++) x[i]=i;
}

void sinh(){
	int i=n-1;
	while (i>=1 && x[i]>x[i+1]) --i;
	if (i==0) ok=false;
	else{
		int j=n;
		while (x[i]>x[j]) --j;
		swap(x[i],x[j]);
		reverse(x+i+1,x+n+1);
	}
}

int main(){
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	ktao();
	ok=true;
	while (ok){
		for (int i=1; i<=n; i++) cout << a[x[i]] << " ";
		cout << endl;
		sinh();
	}
	return 0;
}
