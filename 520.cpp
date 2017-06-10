#include<iostream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int ans=0;
        int tmp=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<'a'||word[i]>'z')
            {
                tmp++;
                break;
            }
        }
        if(!tmp)
        {
            ans++;
        }
        tmp=0;
        if(word[0]>='A'&&word[0]<='Z')
        {
            for(int i=1;i<word.size();i++)
            {
                if(word[i]<'a'||word[i]>'z')
                {
                    tmp++;
                    break;
                }
            }
            if(!tmp)
            {
                ans++;
            }
        }
        tmp=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]<'A'||word[i]>'Z')
            {
                tmp++;
                break;
            }
        }
        if(!tmp)
        {
            ans++;
        }
        if(ans>0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<(ss.detectCapitalUse(s)?"Yes":"No")<<endl;
    return 0;
}
