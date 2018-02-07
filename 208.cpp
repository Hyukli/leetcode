#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class TrieNode
{
public:
    TrieNode* next[26];
    bool is_word;
    TrieNode()
    {
        is_word=false;
        memset(next,0,sizeof(next));
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;

    Trie() {
        root=new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p=root;
        for(int i=0;i<word.size();i++)
        {
            if(p->next[word[i]-'a']==NULL)
            {
                p->next[word[i]-'a']=new TrieNode;
            }
            p=p->next[word[i]-'a'];
        }
        p->is_word=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p=find(word);
        return p!=NULL&&p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p=find(prefix);
        return p!=NULL;
    }

    TrieNode *find(string s)
    {
        TrieNode* p=root;
        for(int i=0;i<s.size()&&p!=NULL;i++)
        {
            p=p->next[s[i]-'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    Trie obj = Trie();
    obj.insert(s1);
    cout<<(obj.search(s2)?"Yes":"No")<<endl;
    cout<<(obj.startsWith(s3)?"Yes":"No")<<endl;
    return 0;
}
