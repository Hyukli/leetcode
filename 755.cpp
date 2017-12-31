#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n=heights.size();
        for(int ii=0;ii<V;ii++)
        {
            auto now=make_pair(heights[K],K);
            for(int i=K-1;i>=0;i--)
            {
                if(now.first>heights[i])
                {
                    now=make_pair(heights[i],i);
                }
                else if(now.first<heights[i])
                {
                    break;
                }
            }
            if(now.second==K)
            {
                for(int i=K+1;i<n;i++)
                {
                    if(now.first>heights[i])
                    {
                        now=make_pair(heights[i],i);
                    }
                    else if(now.first<heights[i])
                    {
                        break;
                    }
                }
            }
            heights[now.second]++;
        }
        return heights;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    int V,K;
    cin>>V>>K;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {

        cin>>v[i];
    }
    v=s.pourWater(v,V,K);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
