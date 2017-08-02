#include<iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,k;
        for(int i=0;i<s.size();i++)
        {
            k=0;
            while(i+k<s.size()&&i-k>=0&&s[i+k]==s[i-k])
            {
                ans++;
                k++;
            }
            k=0;
            while(i+k+1<s.size()&&i-k>=0&&s[i+k+1]==s[i-k])
            {
                ans++;
                k++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.countSubstrings(ss)<<endl;
    return 0;
}
