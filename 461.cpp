#include<iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x!=0||y!=0)
        {
            if(x%2!=y%2)
            {
                ans++;
            }
            x/=2;
            y/=2;
        }
        return ans;
    }
};

int main()
{
    int x,y;
    cin>>x>>y;
    Solution s;
    int ans=s.hammingDistance(x,y);
    cout<<ans;
}
