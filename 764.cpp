#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> v(N,vector<int> (N,1));
        for(int i=0;i<mines.size();i++)
        {
            v[mines[i][0]][mines[i][1]]=0;
        }
        int ans=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(v[i][j])
                {
                    int l1=min(1+i,N-i);
                    int l2=min(1+j,N-j);
                    int l=min(l1,l2);
                    if(l<=ans)
                    {
                        continue;
                    }
                    int t=0;
                    for(int d=0;d<l;d++)
                    {
                        if(v[i][j+d]&&v[i+d][j]&&v[i-d][j]&&v[i][j-d])
                        {
                            t++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    ans=max(t,ans);
                }
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
    int m;
    cin>>m;
    vector<vector<int>> v(n,vector<int> (2));
    for(int i=0;i<m;i++)
    {
        cin>>v[i][0]>>v[i][1];
    }
    cout<<s.orderOfLargestPlusSign(n,v)<<endl;
    return 0;
}
