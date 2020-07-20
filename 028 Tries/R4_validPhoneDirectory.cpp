/*

Valid Phone Directory!

Problem Description

Given a phone directory in the form of string array A containing N numeric strings.

If any phone number is prefix of another phone number then phone directory is invalid else it is valid.

You need to check whether the given phone directory is valid or not if it is valid then return 1 else return 0.



Problem Constraints
2 <= N <= 105

1 <= |A[i]| <= 50

A[i] consists only of numeric digits.



Input Format
First and only argument is an string array A.



Output Format
Return 1 if the given phone directory is valid else return 0.



Example Input
Input 1:

 A = ["1234", "2342", "567"]
Input 2:

 A = ["00121", "001"]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 No number is prefix of any other number so phone directory is valid so we will return 1.
Explanation 2:

 "001" is prefix of "00121" so phone directory is invalid so we will return 0.



*/

struct TrieNode {
    struct TrieNode *children[10];
    bool isEnd;
};

struct TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode;
    pNode -> isEnd = false;
    for (int i = 0; i < 10; ++i)
        pNode -> children[i] = NULL;
        
    return pNode;
}

void insert(TrieNode *root, string key){
    TrieNode *curr = root;
    
    for (int i = 0; i < key.length(); ++i){
        int index = key[i] - '0';
        if (!curr->children[index])
            curr->children[index] = getNode();
            
        curr = curr->children[index];
    }
    
    curr->isEnd = true;
}

bool search(TrieNode *root, string key){
    TrieNode *curr = root;
    
    for (int i = 0; i < key.length(); ++i){
        int index = key[i] - '0';
        if (!curr->children[index])
            return false;
            
        curr = curr->children[index];
    }
    
    return true;
}


int Solution::solve(vector<string> &A) {
    
    TrieNode *root = getNode();
    int flag = 0;
    
    for (int i = 0; i < A.size(); ++i){
        if (search(root, A[i])){
            flag = 1;
            break;
        }
        insert(root, A[i]);
    }
    return 1 - flag;
}
