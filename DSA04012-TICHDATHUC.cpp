#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100],b[100];

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		int res[n+m-1]={0};
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<m; i++) cin >> b[i];
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++) res[i+j]+=a[i]*b[j];
		}
		for (int x : res) cout << x << " ";
		cout << endl;
	}
	return 0;
}
