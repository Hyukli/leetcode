#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int flag=0;
        for(auto a:wordList)
        {
            if(a==endWord)
            {
                flag++;
                break;
            }
        }
        if(!flag)   return false;
        wordList.push_back(endWord);
        int n=wordList.size();
        map<string,int> m;
        m[beginWord]=1;
        vector<bool> v(n,0);
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            string s=q.front();
            int t=m[s];
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(!v[i]&&fun(s,wordList[i]))
                {
                    //cout<<s<<" "<<wordList[i]<<endl;
                    if(i==n-1)
                    {
                        return t+1;
                    }
                    q.push(wordList[i]);
                    v[i]=1;
                    m[wordList[i]]=t+1;
                    //cout<<wordList[i]<<" "<<t+1;
                }
            }
        }
        return 0;
    }
private:
    bool fun(string s1,string s2)
    {
        int n=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                n++;
            }
        }
        return n==1;
    }
};

int main()
{
    Solution s;
    string b,e;
    int n;
    cin>>b>>e>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.ladderLength(b,e,v)<<endl;
    return 0;
}
