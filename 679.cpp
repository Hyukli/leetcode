#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        do
        {
            if(valid(nums)) return true;
        }while(next_permutation(nums.begin(),nums.end()));
        return false;
    }
private:
    bool valid(double a,double b)
    {
        if(abs(a+b-24.0)<0.0001||abs(a-b-24.0)<0.0001||abs(a*b-24.0)<0.0001||b&&abs(a/b-24.0)<0.0001)  return true;
        return false;
    }

    bool valid(double a,double b, double c)
    {
        if(valid(a+b,c)||valid(a-b,c)||valid(a*b,c)||b&&valid(a/b,c))  return true;
        if(valid(a,b+c)||valid(a,b-c)||valid(a,b*c)||c&&valid(a,b/c))  return true;
        return false;
    }

    bool valid(vector<int>& nums)
    {
        double a=nums[0],b=nums[1],c=nums[2],d=nums[3];
        if(valid(a+b,c,d)||valid(a-b,c,d)||valid(a*b,c,d)||b&&valid(a/b,c,d))  return true;
        if(valid(a,b+c,d)||valid(a,b-c,d)||valid(a,b*c,d)||c&&valid(a,b/c,d))  return true;
        if(valid(a,b,c+d)||valid(a,b,c-d)||valid(a,b,c*d)||d&&valid(a,b,c/d))  return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v(4);
    for(int i=0;i<4;i++)
    {
        cin>>v[i];
    }
    cout<<(s.judgePoint24(v)?"Yes":"No")<<endl;
    return 0;
}
