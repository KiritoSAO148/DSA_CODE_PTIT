#include <bits/stdc++.h>
using namespace std;

int prime[10001];

void sieve(){
	for (int i=0; i<=10000; i++){
		prime[i]=true;
	}
	prime[0]=false; prime[1]=false;
	for (int i=2; i<=sqrt(10000); i++){
		if (prime[i]){
			for (int j=i*i; j<=10000; j+=i){
				prime[j]=false;
			}
		}
	}
}

bool used[10001];
typedef pair<int,int> pi;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back

int solve(int s, int t){
	queue<pi>q;
	used[s]=true;
	q.push({s,0});
	while (!q.empty()){
		pi top=q.front(); q.pop();
		int tmp=top.fi;
		if (tmp==t) return top.se;
		int x=tmp;
		vi digit;
		while (x){
			digit.pb(x%10);
			x/=10;
		}
		reverse(begin(digit),end(digit));
		for (int i=0; i<4; i++){
			for (int j=0; j<=9; j++){
				if (i==0 && j==0) continue;
				if (digit[i]!=j){
					int new_num=0;
					for (int k=0; k<4; k++){
						if (i!=k) new_num=new_num*10+digit[k];
						else new_num=new_num*10+j;
					}
					if (!used[new_num] && prime[new_num]){
						used[new_num]=true;
						q.push({new_num,top.se+1});
					}
				}
			}
		}
	}
	return -1;
}

int main(){
	int t; cin >> t;
	sieve();
	while (t--){
		int s,t; cin >> s >> t;
		memset(used,false,sizeof(used));
		cout << solve(s,t) << endl;
	}
	return 0;
}
