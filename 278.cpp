#include<iostream>
#include<string.h>
using namespace std;

int a[1000];

bool isBadVersion(int version)
{
    if(a[version]==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        int high=n;
        int mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(!isBadVersion(mid))
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};

int main()
{
    memset(a,0,sizeof(a));
    int n;
    cout<<"please input the num of product that is good:"<<endl;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        a[i]=1;
    }
    Solution s;
    cout<<s.firstBadVersion(999)<<endl;
    return 0;
}
