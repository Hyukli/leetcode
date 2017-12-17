#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> v(n+1);
        v[0]=cost[0];
        v[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            v[i]=min(v[i-2],v[i-1])+cost[i];
            //cout<<v[i]<<" ";
        }
        return min(v[n-1],v[n-2]);
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.minCostClimbingStairs(v)<<endl;
    return 0;
}
