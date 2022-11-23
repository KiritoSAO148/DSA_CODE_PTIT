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
#define MAX 101

int n, k; 
int a[MAX]; //vector trong luong
int b[MAX]; //vector gia tri su dung
int MaxB; //Tong gia tri su dung
int minA;
int pa[MAX];//ket qua toi uu, phuong an toi uu
int x[MAX]; //xau nhi phan do dai n

void sinh(){
	++x[n-1];
	for (int i=n-1; i>0; i--){
		if (x[i]>1){
			++x[i-1];
			x[i]-=2;
		}
	}
}

void solve(){
	int use=0, weight=0;
	for (int i=0; i<n; i++){
		use+=b[i]*x[i];
		weight+=a[i]*x[i];
	}
	if (weight<=k && use>MaxB){
		minA=weight;
		MaxB=use;
		for (int i=0; i<n; i++) pa[i]=x[i];
	}
}

void process(){
	for (int i=0; i<n; i++) x[i]=0;
	for (int i=0; i<pow(2,n); i++){
		solve();
		sinh();
	}
}

void inp(){
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	minA=0, MaxB=0;
	process();
	cout << MaxB << "\n";
	for (int i=0; i<n; i++) cout << pa[i] << " ";
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
	}
	return 0;
}