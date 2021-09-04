#include <iostream>
#include <string.h>
#include <fstream>
#include"BST.h"
using namespace std;

#define MAX_TREE_SIZE int(1e5)

BST::BST(){
	root = NULL;
}

void BST::traverse(TraversalType_e tt,struct Node* node){
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL){
		external(tt,node);
	}
	else{
		left(tt,node);
		traverse(tt, node->left);
		below(tt, node);
		traverse(tt, node->right);
		right(tt, node);
	}
}

void BST::below(TraversalType_e tt,struct Node *node){
	if(tt == IN_ORDER) cout << node->data << " height: " << node-> height << endl;	
}
void BST::left(TraversalType_e tt,struct Node *node){
	if(tt == PRE_ORDER) cout << node->data <<  " height: " << node-> height << endl;	
}
void BST::right(TraversalType_e tt,struct Node *node){
	if(tt == POST_ORDER) cout << node->data <<  " height: " << node-> height << endl;	
}
void BST::external(TraversalType_e tt,struct Node *node) {cout << node->data << " height: " << node-> height << endl;}

Node* BST::min(Node* x){

	while(x->left != NULL && x != NULL){
		x = x->left;
	}
	return x;
}

Node* BST::max(Node* x){

	while(x->right != NULL && x != NULL){
		x = x->right;
	}
	return x;
}

Node* BST::search(struct Node* node, char* s){
	
	if(node == NULL) return NULL;
	if(strcmp(s,node->data)==0) return node;
	
	return (strcmp(s,node->data)<0) ? search(node->left,s) : search(node->right,s);
}

void update_height(Node* node){

	if(node->left == NULL) node->height = node->right->height + 1;
	else if(node->right == NULL) node->height = node->left->height + 1;
	else node->height = std::max(node->left->height, node->right->height) + 1;
}

bool BST::insert(struct Node* &node,struct Node* parent, struct Node* n){
	
	// Initially the height of node n is initialized to 1
	if(node == NULL) {
		node = new Node(n->data);
		node->parent = parent;
		return true;
	}
	else if(strcmp(node->data,n->data)==0) return false;
	else (strcmp(n->data,node->data)>0) ? insert(node->right,node, n) : insert(node->left,node, n);

	update_height(node);
	return true;
}

void copy(Node* node1, Node* node2){
	node1->data = node2->data;
	node1->left = node2->left;
	node1->right = node2->right;
	node1->height = node2->height;
}

bool BST::remove(Node* node, char *s){
	
	if(node == NULL) return false;
	char* x = node->data;
	if(strcmp(s,node->data)<0){
		if(remove(node->left,s)) update_height(node);
	}
	else if(strcmp(s, node->data)>0){
		if(remove(node->right, s)) update_height(node);	
	}
	else{
		if(node->left == NULL && node->right != NULL){
			copy(node,node->right);
			delete node->right;
		}
		else if(node->left != NULL && node->right == NULL){
			copy(node,node->left);
			delete node->left;
		}
		else{
			struct Node* pre = predecessor(node);
			node->data = pre->data;
			remove(node->left, node->data);
		}
	}
	return true;

}

struct Node* BST::successor(struct Node *n){
	if(n->right != NULL) return min(n->right);
	struct Node* y = n-> parent;
	while(y!= NULL){
		if(n != y->right) break;
		n = y;
		y = n->parent;
	}
	return y;
}

struct Node* BST::predecessor(struct Node *n){
	if(n->left != NULL) return max(n->left);
	struct Node* y = n->parent;
	while(y!= NULL){
		if(n != y->left) break;
		n = y;
		y = n->parent;
	}
	return y;
}

int main(){

	srand(time(0));
	BST my_tree;

	Node* root_parent = NULL;

	cout << "Enter number of nodes in your BST (atleast 5): ";
	int N;cin >> N;
	cout << "Input Sequence: " << endl;
	string s[N];
	for(int i=0;i<N;i++){
		s[i] = to_string(rand());
		cout << s[i] << endl;
		Node* n = new Node(&s[i][0]);
		my_tree.insert(my_tree.root,root_parent,n);
		delete n;
	}
	cout << endl;
	cout << "Inorder sequence: " << endl;
	my_tree.traverse(IN_ORDER,my_tree.root);
	cout << endl;

	cout << "Max element of the tree: " << my_tree.max(my_tree.root)->data << endl;	
	cout << "Min element of the tree: " << my_tree.min(my_tree.root)->data << endl;	
	
	cout << "Predecessor of 3rd input element: " << my_tree.predecessor(my_tree.search(my_tree.root, &s[2][0]))->data << endl;
	cout << "Successor of 4th input element: " << my_tree.successor(my_tree.search(my_tree.root, &s[3][0]))->data << endl;

	// my_tree.remove(my_tree.root, &s[2][0]);
	// cout << endl;
	// cout << "Inorder sequence obtained after removal of 3rd and 5th element: " << endl;
	// my_tree.traverse(IN_ORDER,my_tree.root);

	// -------------------------------Graph part of the code------------------------------ //	
	/*
	ofstream Myfile("BST.csv");
	clock_t tStart = clock();	

	string s[MAX_TREE_SIZE];
	for(int i=0;i<MAX_TREE_SIZE;i++){
		s[i] = to_string(rand());
		Node* n = new Node(&s[i][0]);
		my_tree.insert(my_tree.root,n);
		delete n;
		if(i%1000==0){
			Myfile << i << "," <<  (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
		}
	}
	*/


}