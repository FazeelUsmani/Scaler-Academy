#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}; 
  
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 


void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root;   
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    pCrawl->isEndOfWord = true; 
} 
  

bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  

int main(){
    
    string movies[4] = {"ape", "appy", "apple", "apiapi"};
    TrieNode *root = getNode();

    for (auto x : movies)
        insert(root, x);

    cout<<search(root, "apiapi")<<endl ;
    cout<<search(root, "apiapa")<<endl ;
    cout<<search(root, "aple")<<endl ;
    

    return 0;
}



