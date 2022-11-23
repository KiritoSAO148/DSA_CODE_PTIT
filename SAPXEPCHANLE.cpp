#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	int a[n];
	for (int &x : a) cin >> x;
	vector<int>chan,le;
	for (int x : a){
		if (x%2==0) chan.push_back(x);
		else le.push_back(x);
	}
	sort(begin(chan),end(chan));
	sort(begin(le),end(le),greater<int>());
	int i=0, j=0;
	for (int k=0; k<n; k++){
		if (a[k]%2==0){
			cout << chan[i] << " ";
			++i;
		}else{
			cout << le[j] << " ";
			++j;
		}
	}
	return 0;
}
