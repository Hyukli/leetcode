#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while(n)
        {
            v.insert(v.begin(),n%10);
            n/=10;
        }
        if(!next_permutation(v.begin(),v.end()))
        {
            return -1;
        }
        long long ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans*=10;ans+=v[i];
        }
        int k=INT_MAX;
        if(ans<=k)
        {
            return ans;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.nextGreaterElement(n)<<endl;
    return 0;
}
