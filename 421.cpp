#include<iostream>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max=0,mask=0;
        for(int i=31;i>=0;i--)
        {
            mask=mask|(1<<i);
            map<int,int> m;
            for(int num:nums)
            {
                m[num&mask]++;
            }
            int tmp=max|(1<<i);
            for(auto x:m)
            {
                if(m.find(x.first^tmp)!=m.end())
                {
                    max=tmp;
                    break;
                }
            }
        }
        return max;
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
    cout<<s.findMaximumXOR(v)<<endl;
    return 0;
}
