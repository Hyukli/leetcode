#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tmp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                tmp++;
                if(tmp==3)
                {
                    nums.erase(nums.begin()+i);
                    i--;
                    tmp--;
                }
            }
            else
            {
                tmp=1;
            }
        }
        return nums.size();
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    s.removeDuplicates(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
