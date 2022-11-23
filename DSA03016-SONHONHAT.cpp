#include <bits/stdc++.h>
using namespace std;

void solve (int s, int d){
	if (s==0){
		if (d==1) cout << 0 << endl;
		else cout << -1 << endl;
		return;
	}
	if (s>9*d){
		cout << -1 << endl;
		return;
	}
	int a[d];
	s-=1;
	for (int i=d-1; i>0; i--){
		if (s>9){
			a[i]=9;
			s-=9;
		}
		else{
			a[i]=s;
			s=0;
		}
	}
	a[0]=s+1;
	for (int i=0; i<d; i++) cout << a[i];
	cout << endl;
}

int main(){
	int t; cin >> t;
	while (t--){
		int s,d; cin >> s >> d;
		solve(s,d);
	}
	return 0;
}
