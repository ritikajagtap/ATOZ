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
};

class Trie{
private: Node* root;
public: 
    Trie(){
        root = new Node();
    }
    int countDistinctSubstrings(string word){
        int cnt=0;
        for(int i=0; i<word.size(); i++){
            Node* node = root;
            for(int j=i; j<word.size(); j++){

                if(!node->containsKey(word[j])){
                    node->put(word[j]);
                    cnt++;
                }
                node = node->get(word[j]);
            }
        }
        return cnt+1;
    }


};

int main(){
    int n = 5;
	// vector<string> value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	cout<<trie.countDistinctSubstrings("abab");
	
	return 0;
}