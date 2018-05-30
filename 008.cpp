#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while(i<str.size()&&str[i]==' ')
        {
            i++;
        }
        if(i==str.size())   return 0;
        str=str.substr(i);
        //cout<<str<<endl;
        long long ans=0;
        if(str[0]=='-')
        {
            for(int j=1;j<str.size();j++)
            {
                //cout<<ans<<endl;
                if(str[j]<'0'||str[j]>'9')  break;
                else
                {
                    ans*=10;
                    ans-=(str[j]-'0');
                    if(ans<=-2147483648)
                    {
                        return -2147483648;
                    }
                }
            }
            return ans;
        }
        if(str[0]=='+') str=str.substr(1);
        for(int j=0;j<str.size();j++)
        {
            if(str[j]<'0'||str[j]>'9')  break;
            else
            {
                ans*=10;
                ans+=(str[j]-'0');
                //cout<<ans<<endl;
                if(ans>2147483647)
                {
                    return 2147483647;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    getline(cin,ss);
    cout<<s.myAtoi(ss)<<endl;
    return 0;
}
