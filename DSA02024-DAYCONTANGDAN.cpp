#include <bits/stdc++.h>
using namespace std;
 
int n, a[100], X[100];
vector<string> res;
 
void inp(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
}
 
void Try(int i, int pos){
	for(int j = pos; j <= n; j++){
		if(a[j] > X[i - 1]){
			X[i] = a[j];
			if(i >= 2){
				string tmp = "";
				for(int k = 1; k <= i; k++){
					tmp += to_string(X[k]) + " ";
				}
				res.push_back(tmp);
			}
			Try(i + 1, j + 1);
		}
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	inp();
	X[0] = 0;
	Try(1, 1);
	sort(res.begin(), res.end());
	for(string x : res){
		cout << x << endl;
	}
	return 0;
}
