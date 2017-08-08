#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]]=1;
            }
            else
            {
                m[s[i]]++;
            }
        }
        vector<int> v;
        for(auto mm:m)
        {
            int flag=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==mm.second)
                {
                    flag++;
                }
            }
            if(!flag)
            {
                v.push_back(mm.second);
            }
        }
        string ss="";
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--)
        {
            for(auto mm:m)
            {
                if(mm.second==v[i])
                {
                    for(int j=0;j<v[i];j++)
                    {
                        ss+=mm.first;
                    }
                }
            }
        }
        return ss;
    }
};

int main()
{
    Solution ss;
    string s;
    cin>>s;
    cout<<ss.frequencySort(s)<<endl;
    return 0;
}
