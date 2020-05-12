// A memory optimized CPP implementation of trie 
// using unordered_map 
#include <iostream> 
#include <unordered_map> 
using namespace std; 

struct Trie { 

	// isEndOfWord is true if the node 
	// represents end of a word 
	bool isEndOfWord; 

	/* nodes store a map to child node */
	unordered_map<char, Trie*> map; 
}; 

/*function to make a new trie*/
Trie* getNewTrieNode() 
{ 
	Trie* node = new Trie; 
	node->isEndOfWord = false; 
	return node; 
} 

/*function to insert in trie*/
void insert(Trie*& root, const string& str) 
{ 
	if (root == nullptr) 
		root = getNewTrieNode(); 

	Trie* temp = root; 
	for (int i = 0; i < str.length(); i++) { 
		char x = str[i]; 

		/* make a new node if there is no path */
		if (temp->map.find(x) == temp->map.end()) 
			temp->map[x] = getNewTrieNode(); 

		temp = temp->map[x]; 
	} 

	temp->isEndOfWord = true; 
} 

/*function to search in trie*/
bool search(Trie* root, const string& str) 
{ 
	/*return false if Trie is empty*/
	if (root == nullptr) 
		return false; 

	Trie* temp = root; 
	for (int i = 0; i < str.length(); i++) { 

		/* go to next node*/
		temp = temp->map[str[i]]; 

		if (temp == nullptr) 
			return false; 
	} 

	return temp->isEndOfWord; 
} 

/*Driver function*/
int main() 
{ 
	Trie* root = nullptr; 

	insert(root, "geeks"); 
	cout << search(root, "geeks") << " "; 

	insert(root, "for"); 
	cout << search(root, "for") << " "; 

	cout << search(root, "geekk") << " "; 

	insert(root, "gee"); 
	cout << search(root, "gee") << " "; 

	insert(root, "science"); 
	cout << search(root, "science") << endl; 

	return 0; 
} 
