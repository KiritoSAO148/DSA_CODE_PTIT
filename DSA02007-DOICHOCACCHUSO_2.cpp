#include <bits/stdc++.h>
using namespace std;

int k; string s, kq;

void Try (int k){
	if (k==0) return;
	int n=s.size();
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if (s[j]>s[i]){
				swap(s[i],s[j]);
				if (s.compare(kq)>0) kq=s;
				Try(k-1);
				swap(s[i],s[j]);
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> k >> s;
		kq=s;
		Try(k);
		cout << kq << endl;
	}
	return 0;
}
