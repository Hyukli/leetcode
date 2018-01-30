#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n=A.size();
        if(n==1||n==2)
        {
            return true;
        }
        int m=A[0];
        for(int i=2;i<n;i++)
        {
            if(A[i]<m)
            {
                return false;
            }
            m=max(m,A[i-1]);
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<(s.isIdealPermutation(v)?"Yes":"No")<<endl;
    return 0;
}
