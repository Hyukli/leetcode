#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        int a[1000000];
        a[0]=nums[0];
        a[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++)
        {
            a[i]=max(a[i-1],a[i-2]+nums[i]);
        }
        return a[nums.size()-1];
    }
};

int main() {
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
	cout<<s.rob(v)<<endl;
	return 0;
}
