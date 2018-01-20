#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")   return 0;
        int l=0,r=0;
        vector<int> v(200,0);
        v[s[0]]++;
        int ans=1;
        while(r<s.size())
        {
            r++;
            if(r==s.size())
            {
                break;
            }
            if(v[s[r]]==1)
            {
                while(s[l]!=s[r])
                {
                    v[s[l]]--;
                    l++;
                }
                v[s[l]]--;
                l++;
            }
            v[s[r]]++;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.lengthOfLongestSubstring(ss)<<endl;
    return 0;
}
