#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long ans=0;
        if(houses.size()==0)
        {
            return 0;
        }
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int j=1;
        for(int i=0;i<houses.size();i++)
        {
            int ml,mr;
            ml=-2000000000;
            mr=2000000000;
            for(j=0;j<heaters.size();j++)
            {
                if(heaters[j]<=houses[i])
                {
                    ml=heaters[j];
                }
                else
                {
                    mr=heaters[j];
                    break;
                }
            }
            long long t;
            long long h=houses[i];
            if(h-ml>mr-h)
            {
                t=mr-h;
            }
            else
            {
                t=h-ml;
            }
            if(t>ans)
            {
                ans=t;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n,m;
    vector<int> v1,v2;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v1.push_back(k);
    }
    for(int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        v2.push_back(k);
    }
    cout<<s.findRadius(v1,v2)<<endl;
    return 0;
}
