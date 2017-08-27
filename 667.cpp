#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int flag=1;
        int left=n-1;
        int right=1;
        ans.push_back(n);
        k--;
        for(int i=1;i<n;i++)
        {
            if(k!=0)
            {
                if(flag)
                {
                    ans.push_back(right++);
                }
                else
                {
                    ans.push_back(left--);
                }
                flag^=1;
                k--;
            }
            else if(flag)
            {
                ans.push_back(left--);
            }
            else
            {
                ans.push_back(right++);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    vector<int> v=s.constructArray(n,k);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
