#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        if(n==1)
        {
            return true;
        }
        vector<int> v;
        while(n)
        {
            v.push_back(n%2);
            n/=2;
            if(v.size()>1&&v[v.size()-1]==v[v.size()-2])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<(s.hasAlternatingBits(n)?"Yes":"No")<<endl;
    return 0;
}
