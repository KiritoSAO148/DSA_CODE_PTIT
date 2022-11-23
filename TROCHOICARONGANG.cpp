#include <bits/stdc++.h>
using namespace std;

int n, a[20], ok;
char c;
vector<vector<int>>v;

void ktao(){
	for (int i=1; i<=n; i++) a[i]=0;
}

void sinh(){
	int i=n;
	while (i>=1 && a[i]==1){
		a[i]=0;
		--i;
	}
	if (i==0) ok=false;
	else a[i]=1;
}

bool check(){
	int cnt=0, cnt1=0;
	int ans=0;
	int max1=0, max2=0;
	for (int i=1; i<=n; i++){
		if (a[i]==1){
			++cnt1;
			max1=max(max1,cnt1);
			cnt=0;
		}else{
			++cnt;
			max2=max(max2,cnt);
			cnt1=0;
		}
	}
	if (max1>=5) ++ans;
	if (ans>=1 && max1>max2) return true;
	return false;
}

int main(){
	int t; cin >> t;
	while (t--){
		v.clear();
		cin >> n >> c;
		ok=1;
		ktao();
		while (ok){
			if (check()){
				vector<int>res(a+1,a+n+1);
				v.push_back(res);
			}
			sinh();
		}
		if (c=='X'){
			for (auto it : v){
				for (int i=0; i<it.size(); i++){
					if (it[i]==0) cout << 'O';
					else cout << 'X';
				}
				cout << endl;
			}
		}else{
			for (int i=v.size()-1; i>=0; i--){
				for (int j=0; j<v[i].size(); j++){
					if (v[i][j]==0) cout << 'X';
					else cout << 'O';
				}
				cout << endl;
			}
		}
	}
	return 0;
}
