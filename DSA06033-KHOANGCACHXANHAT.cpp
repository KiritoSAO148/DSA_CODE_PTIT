#include <bits/stdc++.h>
using namespace std;

int find(int a[], int n){
    int b[n];
    b[n-1]= a[n-1];
    for(int i = n-2; i>=0; i--)
        b[i] = max(b[i+1] , a[i]);
    int m = INT_MIN;
    int i = 0, j = 0;
    while(i<n && j<n){
        if(b[j] >= a[i]){
            m = max(m, j-i);
            j++;
        }
        else
            i++;
    }
    return m;     
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		if (find(a,n)==0) cout << -1;
		else cout << find(a,n);
		cout << endl;
	}
	return 0;
}
