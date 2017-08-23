#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix,int k)
    {
        priority_queue<int> q;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(q.size()<k)
                {
                    q.push(matrix[i][j]);
                }
                else
                {
                    if(matrix[i][j]>q.top())
                    {
                        break;
                    }
                    else
                    {
                        q.push(matrix[i][j]);
                        q.pop();
                    }
                }
            }
        }
        return q.top();
    }
};

int main()
{
    Solution s;
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>> matrix;
    for(int i=0;i<m;i++)
    {
        vector<int> v(n);
        for(int j=0;j<n;j++)
        {
            cin>>v[j];
        }
        matrix.push_back(v);
    }
    cout<<s.kthSmallest(matrix,k)<<endl;
    return 0;
}
