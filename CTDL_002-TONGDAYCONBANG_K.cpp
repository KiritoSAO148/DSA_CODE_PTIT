#include <bits/stdc++.h>
using namespace std;

int n,k,a[1005],x[1005];
vector<vector<int>> v;

void Try(int i, int sum, int pos){
	if (sum==k){
		vector<int>res(x+1,x+i);
		v.push_back(res);
	}
	for (int j=pos; j<=n; j++){
		if (a[j]+sum<=k){
			x[i]=a[j];
			Try(i+1,sum+a[j],j+1);
		}
	}
}

int main(){
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	Try(1,0,1);
	for (int i=v.size()-1; i>=0; i--){
		for (int j=0; j<v[i].size(); j++) cout << v[i][j] << " ";
		cout << endl;
	}
	cout << v.size();
	return 0;
}
