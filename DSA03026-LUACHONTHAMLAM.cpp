#include <bits/stdc++.h>
using namespace std;

void smallest(int s, int n){
	if (s==0){
		if (n==1) cout << 0 << " ";
		else cout << -1 << " ";
		return;
	}
	if (s>9*n){
		cout << -1 << " ";
		return;
	}
	int a[n];
	s-=1;
	for (int i=n-1; i>0; i--){
		if (s>9){
			a[i]=9;
			s-=9;
		}else{
			a[i]=s;
			s=0;
		}
	}
	a[0]=s+1;
	for (int i=0; i<n; i++) cout << a[i];
	cout << " ";
}

void biggest(int s, int n){
	if (s==0){
		if (n==1) cout << 0 << " ";
		else cout << -1 << " ";
		return;
	}
	if (s>9*n){
		cout << -1 << endl;
		return;
	}
	int b[n];
	for (int i=0; i<n; i++){
		if (s>9){
			b[i]=9;
			s-=9;
		}else{
			b[i]=s;
			s=0;
		}
	}
	for (int i=0; i<n; i++) cout << b[i];
}

int main(){
	int n,s; cin >> n >> s;
	smallest(s,n);
	biggest(s,n);
	return 0;
}
