#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m,en;
        for(auto n:nums)
        {
            m[n]++;
        }
        for(auto n:nums)
        {
            if(m[n]==0)
            {
                continue;
            }
            if(en[n-1])
            {
                en[n-1]--;
                m[n]--;
                en[n]++;
            }
            else if(m[n+1]&&m[n+2])
            {
                m[n]--;
                m[n+1]--;
                m[n+2]--;
                en[n+2]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<(s.isPossible(v)?"Yes":"No")<<endl;
    return 0;
}
