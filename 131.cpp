#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.empty())
        {
            return ans;
        }
        vector<string> path;
        dfs(0,s,path,ans);
        return ans;
    }
private:
    int dfs(int index,string s,vector<string> path,vector<vector<string>>& ans)
    {
        if(index==s.size())
        {
            ans.push_back(path);
            return 0;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isP(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                dfs(i+1,s,path,ans);
                path.pop_back();
            }
        }
        return 0;
    }

    bool isP(string s,int begin,int end)
    {
        while(begin<=end)
        {
            if(s[begin++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    vector<vector<string>> v;
    v=s.partition(ss);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
