#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> flag(n,0);
        queue<int> q;
        q.push(0);
        flag[0]=1;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(int i=0;i<rooms[t].size();i++)
            {
                if(!flag[rooms[t][i]])
                {
                    flag[rooms[t][i]]=1;
                    q.push(rooms[t][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!flag[i])
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
    vector<vector<int>> v(n);
    int m;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        while(m--)
        {
            int t;
            cin>>t;
            v[i].push_back(t);
        }
    }
    cout<<(s.canVisitAllRooms(v)?"Yes":"No")<<endl;
    return 0;
}
