#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m+1,vector<int> (n+1,0));
        int n0,n1;
        for(auto str:strs)
        {
            n0=n1=0;
            for(auto c:str)
            {
                if(c=='0')
                {
                    n0++;
                }
                else if(c=='1')
                {
                    n1++;
                }
            }
            for(int i=m;i>=n0;i--)
            {
                for(int j=n;j>=n1;j--)
                {
                    memo[i][j]=max(memo[i][j],memo[i-n0][j-n1]+1);
                }
            }
        }
        return memo[m][n];
    }
};

int main()
{
    Solution s;
    int k,n,m;
    cin>>k>>m>>n;
    vector<string> v(k);
    for(int i=0;i<k;i++)
    {
        cin>>v[i];
    }
    cout<<s.findMaxForm(v,m,n)<<endl;
    return 0;
}
