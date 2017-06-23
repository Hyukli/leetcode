#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector <pair <int, int> >& points) {
        int ans=0;
        vector<vector<int>> V;
        for(int i=0;i<points.size();i++)
        {
            vector<int> v;
            for(int j=0;j<points.size();j++)
            {
                v.push_back(dis(points[i],points[j]));
            }
            V.push_back(v);
        }

        for(int i=0;i<V.size();i++)
        {
            for(int j=0;j<V[i].size();j++)
            {
                for(int k=j+1;k<V[i].size();k++)
                {
                    if(V[i][j]==V[i][k])
                    {
                        ans++;
                    }
                }
            }
        }
        return 2*ans;
    }
private:
    int dis(pair<int,int> a,pair<int,int> b)
    {
        return pow((a.first-b.first),2)+pow((a.second-b.second),2);
    }
};

int main()
{
    vector<pair<int,int>> V;
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        typedef pair<int ,int > newpair;
        newpair p(a,b);
        V.push_back(p);
    }
    Solution s;
    cout<<s.numberOfBoomerangs(V)<<endl;
    return 0;
}
