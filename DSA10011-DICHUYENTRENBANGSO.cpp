#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n, m;
int a[505][505];
bool visited[501][501];

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

struct cmp{
    bool operator () (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        return a.se.se > b.se.se;
    }
};

void inp(){
    ms(visited,false);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) cin >> a[i][j];
    }
}

int bfs(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp>pq;
    pq.push({1,{1,a[1][1]}});
    visited[1][1]=true;
    while(!pq.empty()){
        pair<int,pair<int,int>>top=pq.top(); pq.pop();
        int i=top.fi;
        int j=top.se.fi;
        if (i==n && j==m) return top.se.se;
        for(int k = 0; k < 4; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            // if(i == n && j == m)
            //     return top.se.se + a[i][j];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]){
                visited[i1][j1] = true;
                pq.push({i1, {j1, top.se.se + a[i1][j1]}});
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        inp();
        cout << bfs() << "\n";
    }
    return 0;
}