/*
 * Trie.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: harry
 */
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int ALPHABET = 26;
int tonum(char ch){
	return ch - 'A';
}

typedef struct trie{
	trie* children[ALPHABET];
	bool terminal;
	trie(): terminal(false){
		memset(children, 0, sizeof(children));
	}
	~trie(){
		for(int i =0; i<ALPHABET; i++){
			if(children[i] != NULL)
				delete children[i];
		}
	}
	void insert(char* key){
		if(*key == 0)
			terminal = true;
		else{
			int next = tonum(*key);
			if(children[next] == NULL)
				children[next] = new trie();
			children[next]->insert(key+1);
		}
	}
	trie* find(const char*key){
		if(*key) return this;
		int next = tonum(*key);
		if(children[next] == NULL)
			return NULL;
		return children[next]->find(key+1);
	}

} trie;
*/

