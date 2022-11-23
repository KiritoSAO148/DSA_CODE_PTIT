#include <bits/stdc++.h>
using namespace std;

int n,k,a[1001],x[1001];
vector<vector<int>>v;

bool nto (int n){
	for (int i=2; i<=sqrt(n); i++){
		if (n%i==0) return false;
	}
	return n>1;
}

bool check (int m){
    int res=0;
    for(int i=1;i<=m;i++) res+=a[x[i]];
    if(nto(res)) return true;
    return false;
}

void ktao(){
    for(int i=1;i<=n;i++) cin>>a[i];
}

void Try(int i){
    for(int j=x[i-1]+1;j<=n-k+i;j++){
        	x[i]=j;
        	if(i==k){
            	if(check(k)){   
                	vector<int>v1;
                	for(int j=1;j<=k;j++) v1.push_back(a[x[j]]);
                	v.push_back(v1);
                	v1.clear();
            	}
       		}else Try(i+1);
    	}
	}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        ktao();
        for(int i=1;i<=n;i++){
            k=i; x[0]=0;
            Try(1);
        }
        for(int i=0;i<v.size();i++){
            sort(v[i].begin(),v[i].end(),greater<int>());
        }
        sort(v.begin(),v.end());
        for(auto it:v){
            for(auto x:it) cout<<x<<" ";
            cout<<endl;
        }
        v.clear();
    }
    return 0;
}
