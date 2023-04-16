#include <bits/stdc++.h>
using namespace std;

void Try(string s, int a, int b, int c, int n){
	if (s.size() == n && a > 0 && b > 0 && c > 0 && a <= b && b <= c) cout << s << '\n';
	if (s.size() < n){
		Try(s + 'A', a + 1, b, c, n);
        Try(s + 'B', a, b + 1, c, n);
        Try(s + 'C', a, b, c + 1, n);
	}
}

int main(){
    int n; cin >> n;
    for (int i = 3; i <= n; ++i) Try("", 0, 0, 0, i);
    return 0;
}
