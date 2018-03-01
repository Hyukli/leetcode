#include<iostream> 
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++)
        {
            if(a[s[i]-'a']++);
        }
        int tmp=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]==1)
            {
                tmp++;
            }
        }
        if(!tmp)
        {
            return -1;
        }
        else
        {
            for(int i=0;i<s.size();i++)
            {
                if(a[s[i]-'a']==1)
                {
                    return i;
                }
            }
        }
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.firstUniqChar(s)<<endl;
    return 0;
}
