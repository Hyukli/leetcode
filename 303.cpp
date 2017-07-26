#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        if(nums.size()==0)
        {
            return;
        }
        sum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            sum.push_back(sum[i-1]+nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i==0)
        {
            return sum[j];
        }
        else
        {
            return sum[j]-sum[i-1];
        }
    }
private:
    vector<int> sum;
};

int main()
{
    int n,i,j;
    cin>>n>>i>>j;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    NumArray obj = NumArray(v);
    int param_1 = obj.sumRange(i,j);
    cout<<param_1<<endl;
    return 0;
}
