#include <bits/stdc++.h>
using namespace std;

vector<string>v;
int n;

bool check1(string s){
	for (int i=0; i<s.size(); i++){
		if (s[i]!='2' && s[i]!='3' && s[i]!='5' && s[i]!='7') return false;
	}
	return true;
}

bool check2(string s){
	int cnt2=0, cnt3=0, cnt5=0, cnt7=0;
	for (int i=0; i<s.size(); i++){
		if (s[i]=='2') ++cnt2;
		else if (s[i]=='3') ++cnt3;
		else if (s[i]=='5') ++cnt5;
		else if (s[i]=='7') ++cnt7;
	}
	if (cnt2==0 || cnt3==0 || cnt5==0 || cnt7==0) return false;
	return true;
}

bool check3(string s){
	if (stoll(s)%2==0) return false;
	return true;
}

void sieve(){
	queue<string>q;
	q.push("2");
	q.push("3");
	q.push("5");
	q.push("7");
	while (1){
		string top = q.front(); q.pop();
		if (top.size()>n) break;
		if (check1(top) && check2(top) && check3(top)) v.push_back(top);
		q.push(top+"2");
		q.push(top+"3");
		q.push(top+"5");
		q.push(top+"7");
	}
}

int main(){
	cin >> n;
	sieve();
	for (int i=0; i<v.size(); i++) cout << v[i] << "\n";
}
