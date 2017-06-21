#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        ans+=fun(s[s.size()-1]);
        for(int i=s.size()-2;i>=0;i--)
        {
            if(fun(s[i])<fun(s[i+1]))
            {
                ans-=fun(s[i]);
            }
            else
            {
                ans+=fun(s[i]);
            }
        }
        return ans;
    }
private:
    int fun(char c)
    {
        if(c=='I')  return 1;
        if(c=='V')  return 5;
        if(c=='X')  return 10;
        if(c=='L')  return 50;
        if(c=='C')  return 100;
        if(c=='D')  return 500;
        if(c=='M')  return 1000;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.romanToInt(s)<<endl;
    return 0;
}
