#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
int n;
int adj[1001][1001];
vector<pi>edge;

int main(){
	cin >> n;
	cin.ignore();
	for (int i=1; i<=n; i++){
		string s; getline(cin,s);
		string num="";
		stringstream ss(s);
		while (ss>>num){
			if (stoi(num)>i) edge.push_back({i,stoi(num)});
		}
	}
	for (auto it : edge) cout << it.first << " " << it.second << endl;
	return 0;
}
