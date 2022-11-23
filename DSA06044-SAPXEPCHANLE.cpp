#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;

int main(){
	int n; cin >> n;
	vi chan,le;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i+=2) le.pb(a[i]);
	for (int i=1; i<n; i+=2) chan.pb(a[i]);
	sort(chan.begin(), chan.end(), greater<int>());
	sort(le.begin(), le.end());
	int i=0, j=0;
	while (i<le.size() && j<chan.size()) cout << le[i++] << " " << chan[j++] << " ";
	while (i<le.size()) cout << le[i++] << " ";
	while (j<chan.size()) cout << chan[j++] << " ";
	return 0;
}
