#include<iostream>
using namespace std;

const int ALPHABET_SIZE = 27;

struct KeyLabel{
	int index,strt,end;

	KeyLabel(){
		this->index = -1;
		this->strt = -1;
		this->end = -1;
	}

	KeyLabel(int index, int strt,int end){
		this->index = index;
		this->strt = strt;
		this->end = end;
	}
};

struct Node{

	KeyLabel key;

	struct Node *child[ALPHABET_SIZE];
	bool external; 
	Node(KeyLabel key){
		external = true;
		for(int i=0;i<ALPHABET_SIZE;i++)
			child[i] = NULL;
		this->key = key;
	}
};

class Trie{
	private:
	public:
		struct Node* root;
		Trie();

  		// Insert the given node in the Trie; return true if success; false if already exists (don't insert duplicates)	
		void insert(Node* root, KeyLabel key);
		// Returns True if the string search is successfull else return False.
		int find(Node* root, string key, int i);
};