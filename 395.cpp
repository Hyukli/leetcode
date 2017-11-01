#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int m[26]={0};
        for(int i=0;i<s.size();i++)
        {
            m[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]-'a']<k)
            {
                string ss=s.substr(0,i);
                string s2=s.substr(i+1);
                return max(longestSubstring(s2,k),longestSubstring(ss,k));
            }
        }
        return s.size();
    }
};

int main()
{
    Solution s;
    string ss;
    int k;
    cin>>ss>>k;
    cout<<s.longestSubstring(ss,k)<<endl;
    return 0;
}
