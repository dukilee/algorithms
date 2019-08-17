#include<bits/stdc++.h>

using namespace std;

//START
struct node{
	//BST in x
	//MINIMUM HEAP in y
	int x, y;
	node* left, *right;
};

node *root = NULL;

//LEFT is strictly smaller than cut
//RIGHT is greater or equal to cut
pair<node*, node*> split(node* n, int cut){
	if(n==NULL) return pair<node*, node*>(NULL, NULL);

	if(n->x>=cut){
		pair<node*, node*> aux = split(n->left, cut);
		n->left = aux.second;
		aux.second = n;
		return aux;
	}else{
		pair<node*, node*> aux = split(n->right, cut);
		n->right = aux.first;
		aux.first = n;
		return aux;
	}
}

node* merge(node* left, node* right){
	if(left == NULL) return right;
	if(right == NULL) return left;

	if(right->y < left->y){
		node* aux = merge(left, right->left);
		right->left = aux;
		return right;
	}else{
		node* aux = merge(left->right, right);
		left->right = aux;
		return left;
	}
}

void insert(int val){
	node* n;
	n = new node();
	n->x = val;
	n->y = random();
	n->left = n->right = NULL;

	pair<node*, node*> aux;
	node* l, *r;
	aux = split(root, val);
	l = aux.first;
	r = aux.second;

	root = merge(merge(l, n), r);
}

void eraseNode(node* n){
	if(n==NULL) return;
	eraseNode(n->left);
	eraseNode(n->right);
	delete n;
}

void remove(int val){
	node *n;
	pair<node*, node*> aux;
	node* l, *m, *r;
	aux = split(root, val);
	l = aux.first;
	m = aux.second;
	aux = split(m, val+1);
	m = aux.first;
	r = aux.second;
	root = merge(l, r);
	eraseNode(m);
}

bool find(int val){
	node *n;
	pair<node*, node*> aux;
	node* l, *m, *r;
	aux = split(root, val);
	l = aux.first;
	m = aux.second;
	aux = split(m, val+1);
	m = aux.first;
	r = aux.second;
	
	bool ans = m != NULL;
	root = merge(merge(l, m), r);
	return ans;
}

//FINISH
//PROBLEM: n operations
//1 x -> insert value x
//2 x -> delete value x if it exists
//3 x -> check if value x exists

int main(){
	int n;
	cin>>n;

	for(int i = 0; i<n; i++){
		int z, x;
		cin>>z>>x;
		if(z==1){
			insert(x);
		}else if(z==2){
			remove(x);
		}else if(z==3){
			cout<<find(x)<<endl;
		}
	}
}
