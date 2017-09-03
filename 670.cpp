#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        while(num)
        {
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        int i,j;
        int flag=0;
        for(i=0;i<v.size();i++)
        {

            for(j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    flag++;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(flag)
        {
            int tmp=i;
            int max=v[i];
            for(j=i+1;j<v.size();j++)
            {
                if(v[j]>=max)
                {
                    tmp=j;
                    max=v[j];
                }
            }
            v[tmp]^=v[i];
            v[i]^=v[tmp];
            v[tmp]^=v[i];
        }

        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans*=10;
            ans+=v[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.maximumSwap(n)<<endl;
    return 0;
}
