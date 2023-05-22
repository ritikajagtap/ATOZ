#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    Node* links[26];
    int cp = 0; //  count prefix
    int ew = 0; // count end with
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch){
        links[ch-'a'] = new Node();
    }
    void increaseEnd(){
        ew++;
    }
    void increasePrefix(){
        cp++;
    }
    void deleteEnd(){
        ew--;
    }
    void reducePrefix(){
        cp--;
    }
    int getEnd(){
        return ew;
    }
    int getPrefix(){
        return cp;
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
            node->increasePrefix();
        }
        node->increaseEnd();

    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else{
                return;
            }
        }
        node->deleteEnd();

    }
};

int main(){
    Trie T;
    T.insert("apple");
    T.insert("apple");
    T.insert("apps");
    T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.countWordsEqualTo(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.countWordsStartingWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.countWordsStartingWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.countWordsEqualTo(word1)<<endl;
  return 0;
}