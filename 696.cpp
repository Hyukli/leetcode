#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        int ans=0;
        if(s.size()==0)
        {
            return 0;
        }
        char tmp=s[0];
        int l=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==tmp)
            {
                l++;
            }
            else
            {
                v.push_back(l);
                tmp=s[i];
                l=1;
            }
        }
        v.push_back(l);
        for(int i=1;i<v.size();i++)
        {
            ans+=min(v[i-1],v[i]);
        }
        return ans;
    }
};

int main()
{
    string ss;
    cin>>ss;
    Solution s;
    cout<<s.countBinarySubstrings(ss)<<endl;
    return 0;
}
