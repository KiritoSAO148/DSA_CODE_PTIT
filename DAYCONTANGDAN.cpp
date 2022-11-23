#include <bits/stdc++.h>
using namespace std;

int n, a[25], x[25];
vector <string> v;

void Try(int i, int pos){
	for (int j=pos; j<=n; j++){
		if (a[j]>x[i-1]){
			x[i]=a[j];
			if (i>=2){
				string res="";
				for (int k=1; k<=i; k++) res+=to_string(x[k]) + " ";
				v.push_back(res);
			}
			Try(i+1,j+1);
		}
	}
}

int main(){
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	Try(1,1);
	sort(v.begin(),v.end());
	for (string x : v) cout << x << endl;
	return 0;
}
