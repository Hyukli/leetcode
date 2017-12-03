#include<iostream>
#include<vector>
#include<string.h>
#include<limits.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n);
        int a[102];
        memset(a,0,sizeof(a));
        for(int i=n-1;i>=0;i--)
        {
            int tmp=INT_MAX;
            a[temperatures[i]]=i;
            for(int j=100;j>temperatures[i];j--)
            {
                if(a[j]!=0)
                {
                    tmp=min(tmp,a[j]-i);
                }
            }
            if(tmp==INT_MAX)
            {
                tmp=0;
            }
            ans[i]=tmp;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n),ans;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ans=s.dailyTemperatures(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
