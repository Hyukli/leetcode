#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool mark=0;
        int ans=0;
        int tmp;
        if(prices.size()==0)
        {
            return 0;
        }
        for(int i=0;i<prices.size()-1;i++)
        {
            if(!mark)
            {
                if(prices[i]<prices[i+1])
                {
                    tmp=prices[i];
                    mark^=1;
                }
            }
            else
            {
                if(prices[i]>prices[i+1])
                {
                    ans+=(prices[i]-tmp);
                    mark^=1;
                }
            }
        }
        if(mark&&prices[prices.size()-1]>tmp)
        {
            ans+=prices[prices.size()-1]-tmp;
        }
        return ans;
    }
};

int main()
{
    int n;
    vector<int> v;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.maxProfit(v)<<endl;
    return 0;
}
