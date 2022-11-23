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

void insert (Node *root, int u, int v, char c){
	if (root==NULL) return;
	if (root->val==u){
		makeNode(root,u,v,c);
	}
	insert(root->left,u,v,c);
	insert(root->right,u,v,c);
}

int height (Node *root){
	if (root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

bool check1 (Node *root, int level, int h){
	if (root==NULL) return true;
	if (root->left==NULL && root->right==NULL && level<h) return false;
	return check1(root->left,level+1,h) && check1(root->right,level+1,h);
}

bool check2 (Node *root){
	if (root==NULL) return true;
	if ((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)){
		return false;
	}
	return check2(root->left) && check2(root->right);
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
		int h=height(root);
		if (check1(root,1,h) && check2(root)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}