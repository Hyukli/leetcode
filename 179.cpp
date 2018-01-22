#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string to_string(int i)
{
    if(i==0)
    {
        return "0";
    }
    string ans="";
    while(i!=0)
    {
        char c=i%10+'0';
        ans=c+ans;
        i/=10;
    }
    return ans;
}
bool cmp(const string &s1,const string &s2)
{
    return s1+s2>s2+s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0)
        {
            return "";
        }
        vector<string> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(int i=0;i<nums.size();i++)
        {
            ans+=v[i];
        }
        if(ans[0]=='0')
        {
            return "0";
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.largestNumber(v)<<endl;
    return 0;
}
