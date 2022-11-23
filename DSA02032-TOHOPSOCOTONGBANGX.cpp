#include <bits/stdc++.h>
using namespace std;

int n, s, a[25], x[25];
vector<vector<int>> v;

void inp(){
	cin >> n >> s;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	v.clear();
}

void Try (int i, int sum, int pos){
	if (sum==s){
		vector<int>res(x+1,x+i);
		v.push_back(res);
	}
	for (int j=pos; j<=n; j++){
		if (a[j]+sum<=s){
			x[i]=a[j];
			Try(i+1,sum+a[j],j);
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		inp();
		Try(1,0,1);
		if (v.size()){
			cout << v.size() << " ";
			for (auto it : v){
				cout << "{";
				for (int i=0; i<it.size(); i++){
					cout << it[i];
					if (i==it.size()-1) cout << "} ";
					else cout << " ";
				}
			}
		}else cout << -1;
		cout << endl;
	}
	return 0;
}
