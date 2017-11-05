#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> v(1005);
        int m=accounts.size();
        for(int i=0;i<m;i++)
        {
            v[i].push_back(accounts[i][0]);
        }
        for(int i=0;i<m;i++)
        {
            flag[i]=i;
        }
        map<string,int> mp;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp[accounts[i][j]]=i;
                }
                else
                {
                    mer(mp[accounts[i][j]],i);
                }
            }
        }
        for(auto mm:mp)
        {
            mm.second=findr(mm.second);
            v[mm.second].push_back(mm.first);
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size()<2)
            {
                v.erase(v.begin()+i);
                i--;
            }
        }
        return v;
    }
private:
    int flag[1005];
    int findr(int i)
    {
        if(flag[i]==i)
        {
            return i;
        }
        return flag[i]=findr(flag[i]);
    }
    int mer(int i,int j)
    {
        flag[findr(i)]=findr(j);
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<string>> V;
    while(n--)
    {
        vector<string> v;
        int m;
        cin>>m;
        while(m--)
        {
            string ss;
            cin>>ss;
            v.push_back(ss);
        }
        V.push_back(v);
    }
    vector<vector<string>> ans=s.accountsMerge(V);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
