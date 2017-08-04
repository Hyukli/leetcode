#include<iostream>
#include<sstream>
#include<map>
#include<vector>
#include<stdio.h>
using namespace std;

class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        map<string,vector<string> > m;
        vector<vector<string> > v;
        for(auto path:paths)
        {
            stringstream ss(path);
            string root;
            getline(ss,root,' ');
            string s;
            while(getline(ss,s,' '))
            {
                string filepath=root+'/'+s.substr(0,s.find('('));
                string filecont=s.substr(s.find('(')+1,s.find(')')-s.find('(')-1);
                m[filecont].push_back(filepath);
            }
        }
        for(auto i:m)
        {
            if(i.second.size()>1)
            {
                v.push_back(i.second);
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> p(n);
    getchar();
    for(int i=0;i<n;i++)
    {
        getline(cin,p[i]);
    }
    vector<vector<string> > ans;
    ans=s.findDuplicate(p);
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

