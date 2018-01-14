#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int> m;
        for(int i=0;i<S.size();i++)
        {
            m[S[i]]=i;
        }
        vector<int> ans;
        int t=m[S[0]];
        for(int i=0;i<S.size();i++)
        {
            t=max(m[S[i]],t);
            if(t==i)
            {
                ans.push_back(i+1);
                t=0;
            }
        }
        for(int i=ans.size()-1;i>0;i--)
        {
            ans[i]-=ans[i-1];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string S;
    cin>>S;
    vector<int> ans=s.partitionLabels(S);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
