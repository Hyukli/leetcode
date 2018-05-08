#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            if(i%2==1)
            {
                if(N%i==0)
                {
                    int k=N/i;
                    if(k-(i-1)/2<=0)
                    {
                        break;
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
            else
            {
                if(N%i==i/2)
                {
                    int k=N/i;
                    if(k-(i-1)/2<=0)
                    {
                        break;
                    }
                    else
                    {
                        ans++;
                    }
                }
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
    cout<<s.consecutiveNumbersSum(n)<<endl;
    return 0;
}
