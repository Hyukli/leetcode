#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        int n=numRows;
        vector<vector<int> > V;
        if(n==0)
        {
        }
        else
        {
            vector<int> v;
            v.push_back(1);
            V.push_back(v);
            for(int i=2;i<=n;i++)
            {
                vector<int> v;
                v.push_back(1);
                for(int j=2;j<i;j++)
                {
                    v.push_back(V[i-2][j-2]+V[i-2][j-1]);
                }
                v.push_back(1);
                V.push_back(v);
            }
        }
        return V;
    }
};

int main()
{
    int n;
    vector<vector<int> > V;
    cin>>n;
    Solution s;
    V=s.generate(n);
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
