#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        vector<int> v;
        int tmp=0;
        for(int i=0;i<arr.size();i++)
        {
            tmp=max(tmp,arr[i]);
            if(tmp==i)
            {
                ans++;
                tmp=0;
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
