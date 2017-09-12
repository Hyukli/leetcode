#include<iostream>
#include<vector>
#include<map>
using namespace std;

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
        map<string,int>::iterator mm=m.begin();
        for(;mm!=m.end();mm++)
        {
            if(mm->first.size()==word.size())
            {
                int t=0;
                for(int i=0;i<word.size();i++)
                {
                    if(mm->first[i]!=word[i])
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

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    MagicDictionary obj =  MagicDictionary();
    obj.buildDict(v);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string ss;
        cin>>ss;
        cout<<(obj.search(ss)?"Yes":"No")<<endl;
    }
    return 0;
}
