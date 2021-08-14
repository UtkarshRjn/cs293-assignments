#include<bits/stdc++.h>
#include"Dictionary.h"
using namespace std;

char *thombstone = "-";
char *def = "0";

Dictionary::Dictionary(){

	A = new Entry[N];
	for(int i=0;i<N;i++){
		A[i].word = def;
		A[i].freq = INT_MAX;
	}
}

int Dictionary::hashValue(char* key){

	double x = 37;
	double F = (sqrt(5) - 1)/2;
	size_t n = strlen(key);
	double hash = (int)key[n-1];
	for(int i=n-2;i>=0;i--){
		hash = F*(x*hash + (int)key[i]) - floor(F*(x*hash + (int)key[i]));
	}
	return floor(N*hash);
}

int Dictionary::findFreeIndex(char* key){
	
	int i = hashValue(key);
	int hash = i;
	while(A[i].word != def && A[i].word != thombstone){
		i = (i+1)%N;
		if(i == hash) return -1;
	}
	return i;
}

Entry* Dictionary::get(char* key){
	int i = hashValue(key);
	cout << "HashValue: "<< i;
	int hash = i;
	while(true){
		if(A[i].word == def) return NULL;
		else if(A[i].word == key) return &A[i];
		i = (i+1)%N;
		if(i == hash) return NULL;
	}
}

bool Dictionary::put(struct Entry e){

	int index = findFreeIndex(e.word);
	if(index == -1) return false;
	else{
		A[index] = e;
		return true;
	}
}

bool Dictionary::remove(char *key){
	
	int i = hashValue(key);
	int hash = i;
	while(true){
		if(A[i].word == def) return false;
		else if(A[i].word == key){
			A[i].word = thombstone;
			A[i].freq = INT_MAX;
			return true;
		}
		i = (i+1)%N;
		if(i == hash) return false;
	}

}
