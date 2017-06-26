#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        long long max=pow(2,32);
        if(num==0)
        {
            return "0";
        }
        long long n;
        if(num<0)
        {
            n=num+max;
        }
        else
        {
            n=num;
        }
        string ans;
        while(n)
        {
            ans+=fun(n%16);
            n/=16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    char fun(int n)
    {
        if(n>=0&&n<=9)
        {
            return n+='0';
        }
        else
        {
            return n+'a'-10;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.toHex(n)<<endl;
    return 0;
}
