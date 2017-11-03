#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

vector<vector<int>> v(1001,vector<int>(1001,0));

class Solution {
public:
    int getMoneyAmount(int n) {
        return dp(1,n);
    }
private:

    int dp(int s,int e)
    {
        if(s>=e)
        {
            return 0;
        }
        if(v[s][e]!=0)
        {
            return v[s][e];
        }
        v[s][e]=INT_MAX;
        for(int i=s;i<=e;i++)
        {
            v[s][e]=min(v[s][e],i+max(dp(s,i-1),dp(i+1,e)));
        }
        return v[s][e];
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.getMoneyAmount(n)<<endl;
    return 0;
}
