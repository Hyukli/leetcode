#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N==0)
        {
            return 0;
        }
        vector<int> v;
        while(N)
        {
            v.insert(v.begin(),N%10);
            N/=10;
        }
        int n=v.size();
        int i;
        int flag=0;
        for(i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            v[i]-=1;
        }
        for(i;i>=1;i--)
        {
            if(v[i]<v[i-1])
            {
                v[i-1]--;
            }
            else
            {
                break;
            }
        }
        for(int j=i+1;j<n;j++)
        {
            v[j]=9;
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            ans*=10;
            ans+=v[j];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.monotoneIncreasingDigits(n)<<endl;
    return 0;
}
