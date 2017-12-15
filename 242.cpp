#include<iostream>
#include<string.h>
using namespace std;
 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            a[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<(s.isAnagram(s1,s2)?"Yes":"No")<<endl;
    return 0;
}
