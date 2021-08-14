#include<iostream>
#include"Dictionary.h"
#include<fstream>
using namespace std;

int main(){

	Dictionary my_dictionary;

	while(true){
		cout << "Enter any word (or q to quit): ";
		string str; cin >> str;
		if(str == "q") break;
		char *key = &str[0];
	   	Entry *entry_ptr = my_dictionary.get(key);
	   	
	   	if(entry_ptr == NULL){
	   		Entry entry;
	   		entry.word = key;
	   		entry.freq = 1;
	   		my_dictionary.put(entry);
	   		cout << " Frequency : " << 1 << endl;
		}else{
			entry_ptr->freq++;
			my_dictionary.put(*entry_ptr);
			cout << "Frequency : " << entry_ptr->freq << endl;
		}
	}

}
