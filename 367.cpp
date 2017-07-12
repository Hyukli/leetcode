#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=0;
        int j=46340;
        if(num<0)
        {
            return 0;
        }
        else
        {
            return hal(i,j,num);
        }
    }
private:
    bool hal(int i,int j,int num)
    {
        if(i*i==num||j*j==num)
        {
            return true;
        }
        else if(j-1==i||i==j)
        {
            return false;
        }
        else
        {
            int m=(i+j)/2;
            if(m*m==num)
            {
                return true;
            }
            else if(m*m>num)
            {
                return hal(i,m-1,num);
            }
            else
            {
                return hal(m+1,j,num);
            }
        }
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<(s.isPerfectSquare(n)?"Yes":"No")<<endl;
    return 0;
}
