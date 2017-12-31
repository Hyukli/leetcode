#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        if(target<0)
        {
            target=-target;
        }
        long long i=1;
        long long sum=0;
        while(1)
        {
            sum+=i;
            if(sum-target>=0&&(sum-target)%2==0)
            {
                break;
            }
            i++;
        }
        return i;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.reachNumber(n)<<endl;
    return 0;
}
