#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n1=num1.size();
        int n2=num2.size();
        if(n1<n2)
        {
            while(num1.size()<num2.size())
            {
                num1+='0';
            }
        }
        if(n1>n2)
        {
            while(num1.size()>num2.size())
            {
                num2+='0';
            }
        }
        int tmp=0;
        string ans;
        for(int i=0;i<max(n1,n2);i++)
        {
            char c=num1[i]+num2[i]+tmp-'0';
            tmp=0;
            if(c>'9')
            {
                c-=10;
                tmp=1;
            }
            ans+=c;
        }
        if(tmp==1)
        {
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.addStrings(s1,s2)<<endl;
    return 0;
}
