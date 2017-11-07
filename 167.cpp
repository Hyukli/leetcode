#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        vector<int>::iterator en =numbers.end();
        for(int i=0;numbers[i]*2<=target;i++)
        {
            en=lower_bound(numbers.begin()+i+1,en,target-numbers[i]);
            if(numbers[i]+*en==target)
            {
                v.push_back(i+1);
                v.push_back(en-numbers.begin()+1);
                break;
            }
        }
        return v;
    }
};

int main()
{
    Solution s;
    vector<int> v,ans;
    int target,n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cin>>target;
    ans=s.twoSum(v,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
} 
