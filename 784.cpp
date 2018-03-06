#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        string s="";
        dfs(s,0,S);
        return v;
    }
private:
    vector<string> v;
    int dfs(string s,int n,string S)
    {
        if(n==S.size())
        {
            v.push_back(s);
            return 0;
        }
        if(S[n]>='a'&&S[n]<='z')
        {
            char c=S[n];
            string s1=s+c;
            dfs(s1,n+1,S);
            c-=('a'-'A');
            string s2=s+c;
            dfs(s2,n+1,S);
        }
        else if(S[n]>='A'&&S[n]<='Z')
        {
            char c=S[n];
            string s1=s+c;
            dfs(s1,n+1,S);
            c+=('a'-'A');
            string s2=s+c;
            dfs(s2,n+1,S);
        }
        else
        {
            char c=S[n];
            string s1=s+c;
            dfs(s1,n+1,S);
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    vector<string> v=s.letterCasePermutation(ss);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
