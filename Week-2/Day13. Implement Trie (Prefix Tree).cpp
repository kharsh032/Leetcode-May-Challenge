Problem Link :- https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/

/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

//Solution

class Trie 
{
       
public:
    Trie()
    {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
    }
    Trie* next[26] = {};
    bool isword = false;
    void insert(string word) 
    {
        Trie* node = this;
        for (char ch : word) 
        {
            if (node->next[ch-'a']==nullptr) 
            { 
                node->next[ch-'a'] = new Trie(); 
            }
            node = node->next[ch-'a'];
        }
        node->isword = true;
    }
    bool search(string word) 
    {
        Trie* node = this;
        for (char ch : word) 
        {
            if (node->next[ch-'a']==nullptr)
              return false; 
            node = node->next[ch-'a'];
        }
        return node->isword;
 
    }
    bool startsWith(string prefix) 
    {
        Trie* node = this;
        for (char ch : prefix) {
            if (node->next[ch-'a']==nullptr)
               return false;
            node = node->next[ch-'a'];
        }
        return true;
    }
};
