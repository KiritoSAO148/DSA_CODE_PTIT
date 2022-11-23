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
	char c;
	Node *left, *right;
	Node (char x){
		c=x;
		left=right=NULL;
	}
};

bool check (char c){
	return c=='+' || c=='-' || c=='*' || c=='/';
}

void inOrder (Node *root){
	if (root==NULL) return;
	inOrder(root->left);
	cout << root->c;
	inOrder(root->right);
}

// void preOrder (Node *root){
// 	if (root==NULL) return;
// 	cout << root->c;
// 	preOrder(root->left);
// 	preOrder(root->right);
// }

// void postOrder (Node *root){
// 	if (root==NULL) return;
// 	postOrder(root->left);
// 	postOrder(root->right);
// 	cout << root->c;
// }

void solve (string s){
	stack<Node* >st;
	Node *root;
	for (char x : s){
		if (!check(x)) st.push(new Node(x));
		else{
			Node *tmp=new Node(x);
			Node *t1=st.top(); st.pop();
			Node *t2=st.top(); st.pop();
			tmp->left=t2;
			tmp->right=t1;
			st.push(tmp);
		}
	}
	root=st.top();
	inOrder(root);
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
		string s; cin >> s;
		solve(s);
		cout << "\n";
	}
	return 0;
}