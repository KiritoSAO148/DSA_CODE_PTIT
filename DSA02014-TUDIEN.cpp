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

char a[101][101];
int k,m,n;
set <string> dict;
bool used[101][101];
vector <string> v;
string ans;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void inp(){
	dict.clear();
	v.clear();
	ans="";
	cin >> k >> m >> n;
	for (int i=0; i<k; i++){
		string word; cin >> word;
		dict.insert(word);
	}
	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++) cin >> a[i][j];
	}
}

void Try(int i, int j){
	ans+=a[i][j];
	if (dict.count(ans)) v.pb(ans);
	for (int k=0; k<8; k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if (i1>=1 && i1<=m && j1>=1 && j1<=n && !used[i1][j1]){
			used[i1][j1]=true;
			Try(i1,j1);
			used[i1][j1]=false;
		}
	}
	ans.pop_back();
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
		inp();
		for (int i=1; i<=m; i++){
			for (int j=1; j<=n; j++){
				ms(used,false);
				used[i][j]=true;
				Try(i,j);
			}
		}
		//sort(all(v));
		if (!sz(v)) cout << "-1\n";
		else {
			for (string x : v) cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}
