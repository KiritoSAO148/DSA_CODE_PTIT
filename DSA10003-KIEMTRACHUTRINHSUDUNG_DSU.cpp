#include <bits/stdc++.h>
using namespace std;

int n,m;
int par[1001];
int size[1001];

int find (int u){
	if (u==par[u]) return u;
	return par[u]=find(par[u]);
}

bool dsu (int a, int b){
	a=find(a);
	b=find(b);
	if (a==b) return false;
	if (size[a]>size[b]){
		par[b]=a;
		size[a]+=size[b];
	}
	else {
		par[a]=b;
		size[b]+=size[a];
	}
	return true;
}

void ktao(){
	for (int i=1; i<=n; i++){
		par[i]=i;
		size[i]=1;
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		ktao();
		bool ok=false;
		for (int i=0; i<m; i++){
			int x,y; cin >> x >> y;
			if (!dsu(x,y)){
				ok=true;
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
