#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n=S.size();
        vector<int> v(n,n+1);
        for(int i=0;i<n;i++)
        {
            if(S[i]==C)
            {
                v[i]=0;
                for(int j=1;i-j>=0;j++)
                {
                    if(v[i-j]>j)
                    {
                        v[i-j]=j;
                    }
                    else
                    {
                        break;
                    }
                }
                for(int j=1;i+j<n;j++)
                {
                    if(S[i+j]!=C)
                    {
                        v[i+j]=j;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    string ss;
    char c;
    cin>>ss>>c;
    vector<int> ans=s.shortestToChar(ss,c);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
