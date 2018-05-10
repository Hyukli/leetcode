#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int t=abs(target[0])+abs(target[1]);
        for(int i=0;i<ghosts.size();i++)
        {
            if(abs(ghosts[i][0]-target[0])+abs(ghosts[i][1]-target[1])<=t)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> target(2);
    vector<vector<int>> v(n,vector<int> (2));
    for(int i=0;i<n;i++)
    {
        cin>>v[i][0]>>v[i][1];
    }
    cin>>target[0]>>target[1];
    cout<<(s.escapeGhosts(v,target)?"Yes":"No")<<endl;
    return 0;
}
