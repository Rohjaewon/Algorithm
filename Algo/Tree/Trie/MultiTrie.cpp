/*
 * MultiTrie.cpp
 *
 *  Created on: 2019. 3. 2.
 *      Author: harry
 */
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int ALPHABET = 26;
const int MAX = 100;
int tonum(char ch){
	return ch - 'A';
}

typedef struct trie{
	int terminal;
	trie* fail;
	string ch;
	trie* children[ALPHABET];
	vector<int> output;
	trie(): terminal(-1), fail(0), ch(0){
		memset(children, 0, sizeof(children));
	}
	~trie(){
		for(int i =0; i<ALPHABET; i++){
			if(children[i] != NULL)
				delete children[i];
		}
	}
	void insert(char* key, int num){
		if(*key == '\0')
			terminal = num;
		else {
			int next = tonum(*key);
			if (children[next] == NULL)
				children[next] = new trie();
			children[next]->ch = ch+*key;
			children[next]->insert(key + 1, num);
		}
	}
	trie* find(const char*key){
		if(*key == '\0') return this;
		int next = tonum(*key);
		if(children[next] == NULL)
			return NULL;
		return children[next]->find(key+1);
	}

	void ComputeFail(trie* root){
		queue<trie*> q;
		root->fail = root;
		q.push(root);
		while(!q.empty()){
			trie* here = q.front();
			q.pop();
			for(int i =0; i< ALPHABET; i++){
				trie* child = here->children[i];
				if(child == NULL) continue;
				if(here == root)
					child->fail = root;
				else{
					trie* t = here->fail;
					while(t != root && t->children[i] == NULL)
						t = t->fail;
					if(t->children[i] != NULL) t = t->children[i];
					child -> fail = t;
				}
				cout << child->ch << "->" << child->fail->ch<< endl;
				child->output = child->fail->output;
				if(child->terminal != -1){
					child->output.push_back(child->terminal);
					//cout << child->output.size() << endl;
				}
				q.push(child);
			}
		}
	}
	vector<pair<int,int> > aho(const string& s, trie* root){
		vector<pair<int, int>> ret;
		trie* state = root;
		for(int i =0; i< s.size(); i++){
			int chr = tonum(s[i]);
			while(state != root && state->children[chr] == NULL)
				state = state->fail;
			if(state->children[chr]) state = state->children[chr];
			//cout << state->output.size() << endl;
			for(int j =0; j < state->output.size(); j++){
				ret.push_back(make_pair(i, state->output[j]));
			}
		}
		return ret;
	}
} trie;


int main(){
	int n; cin >> n;
	vector<char*> arr(n);
	trie* root = new trie();
	cout << "바늘 문자열" << endl;
	for(int i =0; i<n; i++){
		arr[i] = new char[MAX];
		cin >> arr[i];
	}
//	for(int i =0; i<n; i++){
//		cout << strlen(arr[i]) << endl;
//	}
	for(int i =0; i<n; i++){
		root->insert(arr[i], i);
	}
	root->ComputeFail(root);
	cout << "짚더미 문자열" << endl;
	string s; cin >> s;
	vector<pair<int,int>> answer = root->aho(s, root);
	for(int i =0; i< answer.size(); i++)
		cout << answer[i].first << " " << answer[i].second << endl;
	return 0;
}
*/
