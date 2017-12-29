#include<iostream> 
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum1=(1+n)*n/2;
        long long sum2=0;
        for(int i=0;i<n;i++)
        {
            sum2+=nums[i];
        }
        return sum1-sum2;
    }
};

int main()
{
    int n;
    vector<int > v;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<s.missingNumber(v)<<endl;
    return 0;
}
