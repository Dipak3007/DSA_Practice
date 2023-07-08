#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    vector<TrieNode*> children;
    bool terminal;
public:
    //default constructor not required, can be provided by compiler
    TrieNode(){
        children=vector<TrieNode*> (26,nullptr);
        terminal=false;
    }
    bool hasChar(char c){
        return (children[c-'a']!=nullptr);
    }
    void putChar(char c){
        children[c-'a']=new TrieNode();
    }
    TrieNode* nextChild(char c){
        return children[c-'a'];
    }
    void setTerminal(){
        terminal=true;
    }
    bool getTerminal(){
        return terminal;
    }
};

class Trie{
    TrieNode *root;
public:
    Trie(){
        root=new TrieNode;
    }

    void insert(string word){
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            if(!temp->hasChar(word[i]))
                temp->putChar(word[i]);
            temp=temp->nextChild(word[i]);
        }
        temp->setTerminal();
    }

    bool search(string word){
        TrieNode *temp=root;
        for(int i=0;i<word.length();i++){
            if(!temp->hasChar(word[i]))
                return false;
            temp=temp->nextChild(word[i]);
        }
        return temp->getTerminal();
    }

    bool hasPrefix(string prefix){
        TrieNode *temp=root;
        for(int i=0;i<prefix.length();i++){
            if(!temp->hasChar(prefix[i]))
                return false;
            temp=temp->nextChild(prefix[i]);
        }
        return true;
    }

    //for deletion in Trie, search the word and set its terminal to false
};

int main(){
    vector<string> words={"apple","code","app","coder","codehelp"};
    Trie t;
    for(int i=0;i<words.size();i++)
        t.insert(words[i]);
    
    cout<<t.hasPrefix("ap")<<"\n";
    cout<<t.hasPrefix("code")<<"\n";
    cout<<t.search("ap")<<"\n";
    cout<<t.search("app")<<"\n";
    cout<<t.search("code")<<"\n";
    cout<<t.search("coder")<<"\n";
    return 0;
}