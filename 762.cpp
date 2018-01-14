#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        vector<int> p={2,3,5,7,11,13,17,19,23,29,31};
        int ans=0;
        for(int i=L;i<=R;i++)
        {
            if(isp(p,i))
            {
                ans++;
            }
        }
        return ans;
    }
private:
    bool isp(vector<int> p,int k)
    {
        int t=0;
        while(k!=0)
        {
            t+=(k%2);
            k/=2;
        }
        for(int i=0;i<p.size();i++)
        {
            if(t==p[i])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int l,r;
    cin>>l>>r;
    cout<<s.countPrimeSetBits(l,r)<<endl;
    return 0;
}
