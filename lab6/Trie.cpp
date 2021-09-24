#include<iostream>
#include<fstream>
#include"Trie.h"
using namespace std;

string S[100000];

Trie::Trie(){
	KeyLabel default_key;
	root = new Node(default_key);
}

void Trie::insert(Node *root, KeyLabel key){

	int ch_index = (S[key.index][key.strt] == '$') ? 0 : S[key.index][key.strt] - 'a' + 1;
	if(root->child[ch_index] == NULL){
		root->child[ch_index] = new Node(key);
	}
	else{
		int i = root->child[ch_index]->key.strt;
		int j = key.strt;
		while(S[root->child[ch_index]->key.index][i] == S[key.index][j] && i<= root->child[ch_index]->key.end){
			i++; 
			j++;
		}
		if(i<= root->child[ch_index]->key.end){

			KeyLabel common_key = {root->child[ch_index]->key.index,root->child[ch_index]->key.strt,i-1};
			KeyLabel uncommon_key_old = {root->child[ch_index]->key.index,i,root->child[ch_index]->key.end};
			KeyLabel uncommon_key_new = {key.index,j,key.end};
			
			root->child[ch_index]->key = common_key;
			struct Node* new_node = new Node(uncommon_key_old);
			new_node->external = root->child[ch_index]->external;
			for(int j=0;j<ALPHABET_SIZE;j++){
				new_node->child[j] = root->child[ch_index]->child[j];
				root->child[ch_index]->child[j] = NULL;
			}
			int ch_index_old = (S[uncommon_key_old.index][uncommon_key_old.strt] == '$') ? 0 : S[uncommon_key_old.index][uncommon_key_old.strt] - 'a' + 1;
			int ch_index_new = (S[uncommon_key_new.index][uncommon_key_new.strt] == '$') ? 0 : S[uncommon_key_new.index][uncommon_key_new.strt] - 'a' + 1;
			root->child[ch_index]->external = false;
			root->child[ch_index]->child[ch_index_old] = new_node;
			root->child[ch_index]->child[ch_index_new] = new Node(uncommon_key_new);
		}else{
			KeyLabel uncommon_key_new = {key.index,j,key.end};
			insert(root->child[ch_index],uncommon_key_new);
		}
	}
}

int Trie::find(Node *root, string key, int i){

	int ch_index = (key[i] == '$') ? 0 : key[i] - 'a' + 1;
	root = root->child[ch_index];
	int j = root->key.strt;
	char c = S[root->key.index][j];
	while(root!=NULL){
		ch_index = (key[i] == '$') ? 0 : key[i] - 'a' + 1;
		if(c == key[i] && j <= root->key.end){
			cout << c;
			i++;
			j++;
			if(j <= root->key.end){
				c = S[root->key.index][j];	
			} 
		}else{
			if(c != key[i-1]) return root->key.index;
			else{
				if(root->child[ch_index]==NULL) {
					return root->key.index;
				}
				root = root->child[ch_index];
				j = root->key.strt;
				c = S[root->key.index][j];
			}
		}
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	fstream file;
	string word, filename;
  
    // filename of the file
    filename = "input.txt";
  
    // opening file
    file.open(filename.c_str());
  
    Trie my_trie;

    // extracting words from the file
   	int i = 0;
    cout << "Words entered into the trie :" << endl;
    while (file >> word)
    {
    	S[i] = word.append("$");
    	cout << S[i] << endl;
    	int l = S[i].length()-1;
    	KeyLabel key = {i,0,l};
    	my_trie.insert(my_trie.root,key);
    	i++;
    }

    cout << endl;
    cout << "Longest prefix: ";
    string arg = argv[1];
    int index = my_trie.find(my_trie.root,arg.append("$"),0);
    cout << endl << "Found at index: " << index << endl;
    cout << "Word: " << S[index] <<endl;

	return 0;
}