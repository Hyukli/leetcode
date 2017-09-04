#include<iostream>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0)
        {
            return 0;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans=max(ans,fun(s,k,'A'+i));
        }
        return ans;
    }
private:
    int fun(string s,int k,char c)
    {
        int begin=0,end=0,res=0,usedk=0;
        while(end<s.size())
        {
            if(s[end]==c||usedk<k)
            {
                if(s[end]!=c)
                {
                    usedk++;
                }
                end++;
                res=max(res,end-begin);
            }
            else
            {
                if(s[begin]!=c)
                {
                    usedk--;
                }
                begin++;
            }
        }
        return res;
    }
};

int main()
{
    Solution ss;
    string s;
    int k;
    cin>>s>>k;
    cout<<ss.characterReplacement(s,k)<<endl;
    return 0;
}
