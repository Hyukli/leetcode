#include<iostream>
#include<vector>
using namespace std;

string to_string(int i)
{
    string ans="";
    if(i==0)
    {
        return "0";
    }
    while(i!=0)
    {
        char c=(i%10+'0');
        ans=c+ans;
        i/=10;
    }
    return ans;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)
        {
            return ans;
        }
        int t=nums[0];
        string tmp=to_string(t);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==t+1)
            {
                tmp+="->";
                tmp+=to_string(nums[i]);
                t=nums[i];
            }
            else
            {
                ans.push_back(f(tmp));
                tmp=to_string(nums[i]);
                t=nums[i];
            }
        }
        ans.push_back(f(tmp));
        return ans;
    }
private:
    string f(string s)
    {
        string s1="";
        string s2="";
        int i;
        for(i=s.size()-1;i>=0;i--)
        {
            if(s[i]!='>')
            {
                s2=s[i]+s2;
            }
            else
            {
                break;
            }
        }
        if(i<0)
        {
            return s;
        }
        for(i=0;i<s.size();i++)
        {
            if(s[i]!='>')
            {
                s1+=s[i];
            }
            else
            {
                break;
            }
        }
        s1+='>';
        s1+=s2;
        return s1;
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
    vector<string> ans;
    ans=s.summaryRanges(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
