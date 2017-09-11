class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();i++)
        {
            m[dict[i]]++;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto mm:m)
        {
            if(mm.first.size()==word.size())
            {
                int t=0;
                for(int i=0;i<word.size();i++)
                {
                    if(mm.first[i]!=word[i])
                    {
                        t++;
                    }
                }
                if(t==1)
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
    map<string,int> m;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
