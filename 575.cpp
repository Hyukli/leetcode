#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(),candies.end());
        int sum=candies.size()/2;
        int ans=1;
        for(int i=1;i<candies.size();i++)
        {
            if(candies[i]!=candies[i-1])
            {
                ans++;
            }
        }
        if(ans>sum)
        {
            ans=sum;
        }
        return ans;
    }
};

int main()
{
    vector<int> v;
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.distributeCandies(v)<<endl;
    return 0;
}
