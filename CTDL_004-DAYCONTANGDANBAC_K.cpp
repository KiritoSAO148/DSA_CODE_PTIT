#include <bits/stdc++.h>
using namespace std;

int n, k, a[105], x[105];
vector<vector<int>> v;

void Try (int i, int pos){
	for (int j=pos; j<=n; j++){
		if (a[j]>x[i-1]){
			x[i]=a[j];
			if (i==k){
				vector<int>res(x+1,x+i+1);
				v.push_back(res);
			}else Try(i+1,j+1);
		}
	}
}

int main(){
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	Try(1,1);
	cout << v.size();
	return 0;
}
