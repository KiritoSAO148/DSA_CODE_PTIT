#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n];
		int count[3]={0};
		for (int i=0; i<n; i++){
			cin >> a[i];
			count[a[i]]++;
		}
		for (int i=0; i<3; i++){
			for (int j=0; j<count[i]; j++){
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
