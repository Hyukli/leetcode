#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==val)
            {
                nums.erase(nums.begin()+i);
            }
            else
            {
                i++;
            }
        } 
        return nums.size();
    }
};

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> v;
	while(n--)
	{
		int k;
		cin>>k;
		v.push_back(k);
	}
	Solution s;
	cout<<s.removeElement(v,m)<<endl;
	return 0;
}
