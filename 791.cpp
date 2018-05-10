#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> v(26,0);
        for(int i=0;i<T.size();i++)
        {
            v[T[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<S.size();i++)
        {
            while(v[S[i]-'a']>0)
            {
                ans+=S[i];
                v[S[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++)
        {
            while(v[i]--)
            {
                ans+=('a'+i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution ss;
    int n;
    string s,t;
    cin>>s>>t;
    cout<<ss.customSortString(s,t)<<endl;
    return 0;
}
