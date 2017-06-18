#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int tmp=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            ans+=(s[i]-'A'+1)*pow(26,tmp++);
        }
        return ans;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.titleToNumber(s)<<endl;
    return 0;
}
