#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> m1,m2;
        int ans=0;
        for(auto a:A)
        {
            for(auto b:B)
            {
                m1[a+b]++;
            }
        }
        for(auto c:C)
        {
            for(auto d:D)
            {
                m2[c+d]++;
            }
        }
        for(auto M1:m1)
        {
            if(m2.find(-(M1.first))!=m2.end())
            {
                ans+=M1.second*m2[-(M1.first)];
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
    vector<int> A(n),B(n),C(n),D(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>D[i];
    }
    cout<<s.fourSumCount(A,B,C,D)<<endl;
    return 0;
}
