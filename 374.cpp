#include<iostream>
using namespace std;

int ans;

int guess(int num)
{
    if(num==ans)
    {
        return 0;
    }
    else if(num>ans)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        while(1)
        {
            int mid=(high-low)/2+low;
            int t=guess(mid);
            if(t==0)
            {
                return mid;
            }
            else if(t==-1)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
};

int main()
{
    cin>>ans;
    int n=100000000;
    Solution s;
    cout<<s.guessNumber(n)<<endl;
    return 0;
}
