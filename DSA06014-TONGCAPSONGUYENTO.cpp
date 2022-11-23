#include <bits/stdc++.h>
using namespace std;

/*int p[1000001];

void sang(){
	for (int i=0; i<=1000000; i++){
		p[i]=true;
	}
	p[0]=false;
	p[1]=false;
	for (int i=2; i<=sqrt(1000000); i++){
		if (p[i]){
			for (int j=i*i; j<=1000000; j+=i){
				p[j]=false;
			}
		}
	}
}

int main(){
	int t; cin >> t;
	sang();
	while (t--){
		int n; cin >> n;
		bool ok=false;
		for (int i=0; i<=1000000; i++){
			if(p[i]==true && p[n-i]==true){
				ok=true;
				cout << i << " " << n-i;
				break;
			}
		}
		if (ok==false) cout << -1;
		cout << endl;
	}
	return 0;
}*/

bool check (int n){
	for (int i=2; i<=sqrt(n); ++i){
		if (n%i==0) return false;
	}
	return n>1;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		bool ok=true;
		for (int i=2; i<=n; i++){
			if (ok){
				if (check(i) && check(n-i)){
					cout << i << " " << n-i;
					ok=false;
					break;
				}
			}
		}
		if (ok==true) cout << -1;
		cout << endl;
	}
	return 0;
}
