#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left, *right;
	Node (int x){
		val=x;
		left=right=NULL;
	}
};

//tao not goc
void makeNode(Node *root, int u, int v, char c){
	if (c=='L') root->left=new Node(v);
	else root->right=new Node(v);
}

//them mot not vao cay
void insert(Node *root, int u, int v, char c){
	if (root==NULL) return;
	if (root->val==u){
		makeNode(root,u,v,c);
	}
	insert(root->left,u,v,c);
	insert(root->right,u,v,c);
}

int height (Node* root){
	if (root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

bool check (Node* root, int level, int h){
	if (root==NULL) return true;
	if (root->left==NULL && root->right==NULL && level<h) return false;
	return check(root->left,level+1,h) && check(root->right,level+1,h);
}

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		Node* root = NULL;
		while (n--){
			int u,v; char c;
			cin >> u >> v >> c;
			if (root==NULL){
				root=new Node(u);
				makeNode(root,u,v,c);
			}else insert(root,u,v,c);
		}
		if (check(root,1,height(root))) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}

