#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
        {
            return 0;
        }
        int tmp=0;
        int min=prices[0];
        int max=0;

        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
            }
            else if(prices[i]-min>tmp)
            {
                tmp=prices[i]-min;
            }
        }
        return tmp;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v;
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
