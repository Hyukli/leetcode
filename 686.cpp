#include<iostream>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n=A.size();
        int m=B.size();
        int k=m/n;
        int ans=-1;
        string tmp="";
        for(int i=0;i<k;i++)
        {
            tmp+=A;
        }
        if(tmp.find(B)!=-1)
        {
            ans=k;
        }
        else
        {
            tmp+=A;
            if(tmp.find(B)!=-1)
            {
                ans=k+1;
            }
            else
            {
                tmp+=A;
                if(tmp.find(B)!=-1)
                {
                    ans=k+2;
                }
                else
                {
                    ans=-1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string a,b;
    cin>>a>>b;
    cout<<s.repeatedStringMatch(a,b)<<endl;
    return 0;
}
