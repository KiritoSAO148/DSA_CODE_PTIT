#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int search (int in[], int x, int n){
	for (int i=0; i<n; i++){
		if (in[i]==x) return i;
	}
	return -1;
}

void postOrder (int in[], int pre[], int n){
	int root=search(in,pre[0],n);
	if (root!=0){
		postOrder(in,pre+1,root);
	}
	if (root!=n-1){
		postOrder(in+root+1,pre+root+1,n-root-1);
	}
	cout << pre[0] << " ";
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int in[n], pre[n];
		for (int i=0; i<n; i++) cin >> in[i];
		for (int i=0; i<n; i++) cin >> pre[i];
		postOrder(in,pre,n);
		cout << "\n";
	}
	return 0;
}