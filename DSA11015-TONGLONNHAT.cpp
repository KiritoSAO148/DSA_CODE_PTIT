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

void makeNode (Node *root, int u, int v, char c){
	if (c=='L') root->left=new Node(v);
	else root->right=new Node(v);
}

void insert(Node *root, int u, int v, char c){
	if (root==NULL) return;
	if (root->val==u){
		makeNode(root,u,v,c);
	}
	insert(root->left,u,v,c);
	insert(root->right,u,v,c);
}

int maxSum (Node *root, int &ans){
	if (root==NULL) return 0;
	if (root->left==NULL && root->right==NULL){
		//cay khong co node la
		return root->val;
	}
	int l=maxSum(root->left,ans);
	int r=maxSum(root->right,ans);
	if (root->left!=NULL && root->right!=NULL){
		//cay nhi phan du 2 node la
		ans=max(ans,l+r+root->val);
		return max(l,r)+root->val; //truong hop co node la am
	}
	if (root->left==NULL) return r+root->val;
	if (root->right==NULL) return l+root->val;
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
		Node *root=NULL;
		while (n--){
			int u,v; char c;
			cin >> u >> v >> c;
			if (root==NULL){
				root=new Node(u);
				makeNode(root,u,v,c);
			}else insert(root,u,v,c);
		}
		int ans=-1e9;
		maxSum(root,ans);
		cout << ans << "\n";
	}
	return 0;
}