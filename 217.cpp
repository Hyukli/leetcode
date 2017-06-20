#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size()>set<int>(nums.begin(),nums.end()).size();
    }
};

int main()
{
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
    cout<<(s.containsDuplicate(v)?"Yes":"No")<<endl;
    return 0;
}
