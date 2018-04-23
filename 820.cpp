#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const string &a,const string &b)
{
    return a.size()>b.size();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        map<string,int> m;
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<words.size();i++)
        {
            if(m.find(words[i])==m.end())
            {
                ans++;
                ans+=words[i].size();
                for(int j=0;j<words[i].size();j++)
                {
                    m[words[i].substr(j)]++;
                }
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
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.minimumLengthEncoding(v)<<endl;
    return 0;
}
