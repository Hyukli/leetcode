#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++)
        {
            ans[i]=ans[i&(i-1)]+1;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> v;
    v=s.countBits(n);
    for(int i=0;i<=n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
