#include <bits/stdc++.h>
using namespace std;

int a[1001][1001];
vector<int>adj[1001];
int n;

int main(){
	cin >> n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> a[i][j];
			if (a[i][j]) adj[i].push_back(j);
		}
	}
	for (int i=1; i<=n; i++){
		for (int x : adj[i]) cout << x << " ";
		cout << endl;
	}
	return 0;
}
