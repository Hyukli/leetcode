#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
    {
        int a,b;
    };
    bool cmp(const Node& p,const Node& q)
    {
        return p.b<q.b;
    }

class Solution {
private:

public:
    int maximumProduct(vector<int>& nums) {
        vector<Node> nc;
        for(int i=0;i<nums.size();i++)
        {
            Node nn;
            nn.a=nums[i];
            nn.b=nums[i]>0?nums[i]:-nums[i];
            nc.push_back(nn);
        }
        sort(nc.begin(),nc.end(),cmp);
        int m1,m2,m3;
        sort(nums.begin(),nums.end());
        if(nums.size()==3)
        {
            return nums[0]*nums[1]*nums[2];
        }
        else
        {
            if(nums[nums.size()-1]>0)
            {
                if(nums[nums.size()-3]>0)
                {
                    if(nums[1]>=0)
                    {
                        return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
                    }
                    else
                    {
                        if(nums[1]*nums[0]>nums[nums.size()-2]*nums[nums.size()-3])
                        {
                            return nums[nums.size()-1]*nums[1]*nums[0];
                        }
                        else
                        {
                            return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
                        }
                    }
                }
                else
                {
                    if(nums[0]*nums[1]>0)
                    {
                        return nums[nums.size()-1]*nums[0]*nums[1];
                    }
                    else
                    {
                        return nc[0].a*nc[1].a*nc[2].a;
                    }
                }
            }
            else
            {
                return nc[0].a*nc[1].a*nc[2].a;
            }
        }
    }
};

class Solution2
{
public:
     int maximumProduct(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         return max(nums[0]*nums[1]*nums[nums.size()-1],nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
     }
};

int main()
{
    Solution s;
    int n;
    vector<int> v;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<s.maximumProduct(v)<<endl;
    return 0;
}
