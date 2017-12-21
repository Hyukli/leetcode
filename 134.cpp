#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start(0),total(0),tank(0);
        for(int i=0;i<gas.size();i++)
        {
            if((tank=tank+gas[i]-cost[i])<0)
            {
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        return (total+tank<0)?-1:start;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> gas(n),cost(n);
    for(int i=0;i<n;i++)
    {
        cin>>gas[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>cost[j];
    }
    cout<<s.canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
