#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n,k; cin >> n >> k;
		int a[k];
		for (int i=0; i<k; i++) cin >> a[i];
		vector<int>v(a,a+k);
		int i=v.size()-1;
		while (v[i]-v[i-1]==1) --i;
		if (i==-1){
			for (int j=0; j<k; j++) v[j]=n-k+j+1;
		}else{
			v[i]--;
			for (int j=i+1; j<k; j++) v[j]=n-k+j+1;
		}
		for (int i=0; i<v.size(); i++) cout << v[i] << " ";
		cout << endl;
		v.clear();
	}
	return 0;
}
