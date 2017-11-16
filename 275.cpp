#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,n=citations.size(),r=n-1,mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(citations[mid]>=(n-mid))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return n-l;
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
    cout<<s.hIndex(v)<<endl;
    return 0;
}
