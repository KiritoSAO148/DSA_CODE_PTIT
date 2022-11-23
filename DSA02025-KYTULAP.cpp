#include <bits/stdc++.h>
using namespace std;
int c[20][20], n, x[20], fopt=1e9, xopt[20], cmin=1e9, cost=0;
bool chuaxet[20];

void Try(int i){
    int j;
    for(int j=1;j<=n;j++){
        if(chuaxet[j]){
            x[i]=j;
            chuaxet[j]=false;
            cost+=c[x[i-1]][x[i]];
            if(i==n) fopt=min(fopt,cost);
            else if(cost+cmin*(n-i+1)<fopt) Try(i+1);
            cost-=c[x[i-1]][x[i]];
            chuaxet[j]=true;
        }
    }
}

int dem(string s1,string s2){
    int i=0,j=0,d=0;
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            i++;j++;d++;
        }
        else if(s1[i]<s2[j]) i++;
        else j++;
    }
    return d;
}

int main(){
    int i,j;
    cin>>n;
    vector<string>vs;
    for(int i=0;i<n;i++){
        string tmp; cin>>tmp;
        vs.push_back(tmp);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) c[i][j]=1e9;
            else c[i][j] = dem(vs[i-1],vs[j-1]);
            cmin=min(cmin,c[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        x[i]=i;
        chuaxet[i]=true;
    }
    Try(1);
    cout<<fopt<<endl;
}
