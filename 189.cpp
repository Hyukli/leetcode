#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0)
        {
            return ;
        }
        int i=nums.size()-1;
        for(int j=0;j<k;j++)
        {
            nums.insert(nums.begin(),nums[i]);
            nums.erase(nums.end()-1);
        }
        return;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<int> v;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    s.rotate(v,m);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
