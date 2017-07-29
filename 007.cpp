#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long n=pow(2,31)-1;
        long long m=-pow(2,31);
        vector<int> v;
        int flag=x>0?0:1;
        x=x>0?x:-x;
        while(x)
        {
            v.push_back(x%10);
            x/=10;
        }
        long long ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans*=10;
            ans+=v[i];
        }
        ans=flag?-ans:ans;
        if(ans>n||ans<m)
        {
            return 0;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.reverse(n)<<endl;
    return 0;
}
