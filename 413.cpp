#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int curr=0,sum=0;
        for(int i=2;i<A.size();i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                curr++;
                sum+=curr;
            }
            else
            {
                curr=0;
            }
        }
        return sum;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<s.numberOfArithmeticSlices(v)<<endl;
    return 0;
}
