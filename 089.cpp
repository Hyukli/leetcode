#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0;i<1<<n;i++)
        {
            ans.push_back(i^i>>1);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v;
    v=s.grayCode(n);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
