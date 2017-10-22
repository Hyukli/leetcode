#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0)
        {
            return 0;
        }
        vector<int> p2=prices;
        int sum=0;
        int pre;
        for(int i=0;i<p2.size();i++)
        {
            p2[i]-=fee;
        }
        int tmp=prices[0];
        for(int i=0;i<prices.size()-1;i++)
        {
            pre=p2[i+1];
            if(pre>tmp)
            {
                sum+=pre-tmp;
                tmp=p2[i+1];
            }
            else if(prices[i+1]<tmp)
            {
                tmp=prices[i+1];
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    int n,fee;
    cin>>n>>fee;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.maxProfit(v,fee)<<endl;
    return 0;
}
