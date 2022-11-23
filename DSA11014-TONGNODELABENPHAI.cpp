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

int sum;

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

void insert (Node *root, int u, int v, char c){
	if (root==NULL) return;
	if (root->val==u){
		makeNode(root,u,v,c);
	}
	insert(root->left,u,v,c);
	insert(root->right,u,v,c);
}

void rightSum (Node *root){
	if (root==NULL) return;
	if (root->right!=NULL && root->right->left==NULL && root->right->right==NULL){
		sum+=root->right->val;
	}
	if (root->right && root->right->left && root->right->right) rightSum(root->right);
	if (root->left && root->left->left && root->left->right) rightSum(root->left);
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
		sum=0;
		rightSum(root);
		cout << sum << "\n";
	}
	return 0;
}