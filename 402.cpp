#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        for(int i=0;i<k;i++)
        {
            char c=num[0];
            int t=0;
            for(int j=1;j<num.size();j++)
            {
                if(num[j]<c)
                {
                    break;
                }
                else
                {
                    c=num[j];
                    t=j;
                }
            }
            string s1=num.substr(0,t);
            string s2=num.substr(t+1);
            num=s1+s2;
        }
        while(num.size()!=0&&num[0]=='0')
        {
            num.erase(num.begin());
        }
        if(num.size()==0)
        {
            num="0";
        }
        return num;
    }
};

int main()
{
    Solution s;
    string ss;
    int k;
    cin>>ss>>k;
    cout<<s.removeKdigits(ss,k)<<endl;
    return 0;
}
