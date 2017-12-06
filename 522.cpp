#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                else
                {
                    if(isSubstr(strs,i,j))
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
            {
                ans=max(ans,int(strs[i].size()));
            }
        }
        return ans;
    }
private:
    bool isSubstr(vector<string> v,int i,int j)
    {
        string s1=v[i];
        string s2=v[j];
        if(s1.size()>s2.size())
        {
            return false;
        }
        i=0,j=0;
        while(i<s1.size()&&j<s2.size())
        {
            if(s1[i]==s2[j])
            {
                i++;
            }
            j++;
        }
        if(i==s1.size())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.findLUSlength(v)<<endl;
    return 0;
}
