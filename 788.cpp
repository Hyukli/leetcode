#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool isd(int k)
    {
        vector<int> v;
        while(k)
        {
            v.push_back(k%10);
            k/=10;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==3||v[i]==4||v[i]==7)
            {
                return false;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==2||v[i]==5||v[i]==6||v[i]==9)
            {
                return true;
            }
        }
        return false;
    }

public:
    int rotatedDigits(int N) {
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            if(isd(i))
            {
                ans++;
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
    cout<<s.rotatedDigits(n)<<endl;
    return 0;
}
