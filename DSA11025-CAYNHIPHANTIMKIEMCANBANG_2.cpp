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

struct Node{
	int val;
	Node *left, *right;
	Node (int x){
		val=x;
		left=right=NULL;
	}
};

Node *build (int a[], int l, int r){
	if (l>r) return NULL;
	int m=(l+r)/2;
	Node *root = new Node(a[m]);
	root->left = build(a, l, m-1);
	root->right = build(a, m+1, r);
	return root;
}

void preOrder (Node *root){
	if (root==NULL) return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	#ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin);
  	freopen("output.txt", "w", stdout);
  	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i=0; i<n; i++) cin >> a[i];
		sort(a,a+n);
		Node *root = build(a, 0, n-1);
		preOrder(root);
		cout << "\n";
	}
	return 0;
}