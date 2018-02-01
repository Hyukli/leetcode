#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> v(6);
        for(int i=0;i<5;i++)
        {
            v[i]=1+i;
        }
        v[5]=0;
        bfs(v);
        int t=0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                t*=10;
                t+=board[i][j];
            }
        }
        if(m.find(t)==m.end())
        {
            return -1;
        }
        return m[t];
    }
private:
    map<int,int> m;
    int d[4]={1,-1,3,-3};
    int bfs(vector<int> v)
    {
        queue<vector<int>> q;
        v.push_back(0);
        q.push(v);
        while(!q.empty())
        {
            vector<int> vt=q.front();
            q.pop();
            int ans=0;
            for(int i=0;i<6;i++)
            {
                ans*=10;
                ans+=vt[i];
            }
            if(m.find(ans)==m.end())
            {
                m[ans]=vt[6];
                vt[6]++;
                for(int i=0;i<6;i++)
                {
                    if(vt[i]==0)
                    {
                        for(int j=0;j<4;j++)
                        {
                            int p=d[j]+i;
                            if((!(d[j]==1&&i==2))&&(!(d[j]==-1&&i==3))&&p>=0&&p<6)
                            {
                                swap(vt[i],vt[p]);
                                q.push(vt);
                                swap(vt[i],vt[p]);
                            }
                        }
                        break;
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v(2,vector<int> (3));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<s.slidingPuzzle(v)<<endl;
    return 0;
}
