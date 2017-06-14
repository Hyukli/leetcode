#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minm,minn;
        minm=m;
        minn=n;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i][0]<minm)
            {
                minm=ops[i][0];
            }
            if(ops[i][1]<minn)
            {
                minn=ops[i][1];
            }
        }
        return minn*minm;
    }
};

int main()
{
    int m,n,t;
    cin>>m>>n>>t;
    vector<vector<int>> v;
    while(t--)
    {
        int t1,t2;
        cin>>t1>>t2;
        vector<int> v1;
        v1.push_back(t1);
        v1.push_back(t2);
        v.push_back(v1);
    }
    Solution s;
    cout<<s.maxCount(m,n,v)<<endl;
    return 0;
}
