#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        if(links[ch-'a']!=NULL){
            return true;
        }
        return false;
    }
    void put(char ch){
        links[ch-'a'] = new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
private: Node* root;
public: 
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }


};

int main(){
    int n = 5;
	// vector<string> value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	trie.insert("hello");
	cout<<trie.startsWith("hell");
	return 0;
}