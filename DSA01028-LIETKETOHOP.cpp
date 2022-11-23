#include <bits/stdc++.h>
using namespace std;

int n,k,a[100],ok;
set<int>s;

void ktao(){
	for (int i=1; i<=k; i++){
		a[i]=i;
	}
}

void sinh(){
	int i=k;
	while (i>=1 && a[i]==n-k+i) --i;
	if (i==0) ok=false;
	else{
		++a[i];
		for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
	}
}

int main(){
	int x,y; cin >> x >> y;
	s.clear();
	for (int i=0; i<x; i++){
		int tmp; cin >> tmp;
		s.insert(tmp);
	}
	n=s.size();
	k=y;
	vector<int>v;
	for (int x : s) v.push_back(x);
	ok=true;
	ktao();
	while (ok){
		for (int i=1; i<=k; i++){
			cout << v[a[i]-1] << " ";
		}
		cout << endl;
		sinh();
	}
	return 0;
}
