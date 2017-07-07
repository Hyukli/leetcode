#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        vector<int> v;
        int mark=1;
        for(int i=0;i<digits.size();i++)
        {
            int t=digits[i]+mark;
            if(t>9)
            {
                t-=10;
                mark=1;
            }
            else
            {
                mark=0;
            }
            v.push_back(t);
        }
        if(mark)
        {
            v.push_back(1);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

int main()
{
    string s;
    cin>>s;
    vector<int> v,ans;
    for(int i=0;i<s.size();i++)
    {
        v.push_back(s[i]-'0');
    }
    Solution ss;
    ans=ss.plusOne(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
