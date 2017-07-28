#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
            {
                v.push_back(s[i]);
            }
            if(s[i]>='A'&&s[i]<='Z')
            {
                v.push_back(s[i]-'A'+'a');
            }
        }
        if(v.size()==0||v.size()==1)
        {
            return true;
        }
        for(int i=0,j=v.size()-1;i<=j;i++,j--)
        {
            if(v[i]!=v[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<(ss.isPalindrome(s)?"Yes":"No")<<endl;
    return 0;
}
