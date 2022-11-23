#include <bits/stdc++.h>
using namespace std;

struct task{
	int s,f;
};

bool cmp(task a, task b){
	return a.f<b.f;
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		task a[n];
		for (int i=0; i<n; i++) cin >> a[i].s;
		for (int i=0; i<n; i++) cin >> a[i].f;
		sort(a,a+n,cmp);
		int cnt=1, i=0;
		for (int j=1; j<n; j++){
			if (a[j].s>=a[i].f){
				++cnt;
				i=j;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
