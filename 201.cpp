#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=0;
        vector<int> v1=fun(m);
        vector<int> v2=fun(n);
        for(int i=0;i<v1.size()&&i<v2.size();i++)
        {
            if(v1[i]==v2[i])
            {
                ans+=v1[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
private:
    vector<int> fun(int i)
    {
        vector<int> ans;
        int t=2147483648/2;
        while(i!=0)
        {
            if(i>=t)
            {
                i-=t;
                ans.push_back(t);
                //cout<<t<<" "<<i<<endl;
            }
            t/=2;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    cout<<s.rangeBitwiseAnd(n,m)<<endl;
    return 0;
}
