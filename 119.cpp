#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        for(int i=0;i<rowIndex;i++)
        {
            v.push_back(1);
            for(int j=v.size()-2;j>=1;j--)
            {
                v[j]=v[j]+v[j-1];
            }
        }
        return v;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> v;
    v=s.getRow(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
