#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char c;

bool check (string s){
	for (int i = 1; i < s.size() - 1; ++i){
		if (s[i] == 'A' || s[i] == 'E'){
			if (s[i - 1] != 'A' && s[i + 1] != 'E' && s[i - 1] != 'E' && s[i + 1] != 'A') return true;
		}
	}
	return false;
}

int main(){
	cin >> c;
	string s = "";
	for (int i = 'A'; i <= c; ++i) s += (char) i;
	do{
		if (!check(s)) cout << s << '\n';
	}while (next_permutation(s.begin(), s.end()));
    return 0;
}
