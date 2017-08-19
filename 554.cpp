#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> m;
        for(int i=0;i<wall.size();i++)
        {
            for(int j=1;j<wall[i].size();j++)
            {
                wall[i][j]=wall[i][j]+wall[i][j-1];
                m[wall[i][j-1]]++;
            }
        }
        int ma=0;
        for(auto mm:m)
        {
            ma=max(ma,mm.second);
        }
        return wall.size()-ma;
    }
};

int main()
{
    Solution s;
    int m;
    cin>>m;
    vector<vector<int>> V;
    for(int i=0;i<m;i++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int j=0;j<n;j++)
        {
            cin>>v[j];
        }
        V.push_back(v);
    }
    cout<<s.leastBricks(V)<<endl;
    return 0;
}
