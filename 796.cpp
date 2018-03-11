#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        int n=A.size();
        int m=B.size();
        if(n!=m)
        {
            return false;
        }
        A=A+A;
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int k=0;k<n;k++)
            {
                if(A[i+k]!=B[k])
                {
                    flag=1;
                    break;
                   }
            }
            if(!flag)
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
    string s1,s2;
    cin>>s1>>s2;
    cout<<(s.rotateString(s1,s2)?"Yes":"No")<<endl;
    return 0;
}
