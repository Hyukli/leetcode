#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int a[20002];
        int max=0;
        map<int,int> m;
        memset(a,0,sizeof(a));
        for(int i=0;i<nums.size();i++)
        {
            m.clear();
            int tmp=0;
            if(a[i]==0)
            {
                int k=i;
                a[k]=1;
                while(m.find(k)==m.end())
                {
                    m[k]=1;
                    a[k]=1;
                    tmp++;
                    k=nums[k];
                }
                if(tmp>max)
                {
                    max=tmp;
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
    cout<<s.arrayNesting(v)<<endl;
    return 0;
}
