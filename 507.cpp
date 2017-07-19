#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1)
        {
            return false;
        }
        vector<int> v;
        v.push_back(1);
        int n=sqrt(num);
        for(int i=2;i<=n;i++)
        {
            if(num%i==0)
            {
                v.push_back(i);
                if(i!=num/i)
                {
                    v.push_back(num/i);
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            num-=v[i];
        }
        if(num==0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<(s.checkPerfectNumber(n)?"Yes":"No")<<endl;
    return 0;
}
