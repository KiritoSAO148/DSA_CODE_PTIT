#include <bits/stdc++.h>
using namespace std;

void solve(pair<int,int>a[], int n){
    int dp[n];
    for (int i=0; i<n; i++){
        dp[i] = 1;
		for (int j=0; j<i; j++){
            if (a[j].first < a[i].first && a[j].second < a[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n-1] << endl;
}

int main(){
	int n; cin >> n;
	pair<int,int>a[n];
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
	solve(a,n);
}
