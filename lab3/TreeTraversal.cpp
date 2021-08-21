#include<iostream>
#include"TreeTraversal.h"
#include<cassert>
#include<bits/stdc++.h>

int search(char *arr, char elem, int N){
	int i;
	for(i=0;i<N;i++){
		if(arr[i] == elem) return i;
	}
	return -1;
}

Tree::Tree(){
	root = NULL;
}

struct Node* Tree::deduce_tree(char *pre_order, char *in_order, int N){

	static int preIndex = 0;
	
	if(N <= 0) return NULL;

	Node* root = new Node(pre_order[preIndex++]);
	if(N == 1) return root;

	int inIndex = search(in_order,root->data,N);
	if(inIndex == -1 || inIndex >=N) {
		this-> root = NULL;
		return NULL;
	}
	root->left = deduce_tree(pre_order, in_order, inIndex);
	root->right = deduce_tree(pre_order, in_order+inIndex+1, N-inIndex-1 );

	return root;
}

void Tree::traverse(TraversalType_e tt, Node* node){
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL){
		external(tt,node);
	}
	else{
		if(tt == PRE_ORDER) left(tt,node);
		traverse(tt, node->left);
		if(tt == IN_ORDER) below(tt, node);
		traverse(tt, node->right);
		if(tt == POST_ORDER) right(tt, node);
	}
}

void Tree::below(TraversalType_e tt, Node *node){cout << node->data;}
void Tree::left(TraversalType_e tt, Node *node) {cout << node->data;}
void Tree::right(TraversalType_e tt, Node *node) {cout << node->data;}
void Tree::external(TraversalType_e tt, Node *node) {cout << node->data;}

int main(){

	string pre_order,in_order;
	cout << "Enter Preorder traverseal: ";
	cin >> pre_order;
	cout << "Enter Inorder traversal: ";
	cin >> in_order;

	assert(pre_order.length() == in_order.length());
	
	Tree my_tree;
	Node* root = my_tree.deduce_tree(&pre_order[0], &in_order[0], in_order.length());
	cout << "Postorder traversal is: ";
	my_tree.traverse(POST_ORDER, root);
	cout << endl;
}