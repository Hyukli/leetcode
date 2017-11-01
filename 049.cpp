#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,int> m;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(m.find(tmp)==m.end())
            {
                m[tmp]=ans.size();
                vector<string> v;
                v.push_back(strs[i]);
                ans.push_back(v);
            }
            else
            {
                ans[m[tmp]].push_back(strs[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
    vector<vector<string>> v=s.groupAnagrams(strs);
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
