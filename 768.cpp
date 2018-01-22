#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> flag(arr.size(),0);
        vector<int> v=arr;
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(!flag[j]&&v[j]==arr[i])
                {
                    flag[j]=1;
                    break;
                }
            }
            int s=0;
            for(int j=0;j<=i;j++)
            {
                if(flag[j]==0)
                {
                    s=1;
                    break;
                }
            }
            if(s==0)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.maxChunksToSorted(v)<<endl;
    return 0;
}
