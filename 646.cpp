#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    struct Node
    {
        int x,y;
    };
    bool cmp(const Node &a,const Node &b)
    {
        if(a.y!=b.y)
        {
            return a.y<b.y;
        }
        else
        {
            return a.x<b.x;
        }
    }

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        Node t[1005];
        for(int i=0;i<pairs.size();i++)
        {
            t[i].x=pairs[i][0];
            t[i].y=pairs[i][1];
        }
        sort(t,t+pairs.size(),cmp);
        int tmp=t[0].y;
        int ans=1;
        for(int i=1;i<pairs.size();i++)
        {
            if(t[i].x>tmp)
            {
                ans++;
                tmp=t[i].y;
            }
        }
        return ans;

    }
private:


};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int> > v(n);
    for(int i=0;i<n;i++)
    {
        int k,l;
        cin>>k>>l;
        v[i].push_back(k);
        v[i].push_back(l);
    }
    cout<<s.findLongestChain(v)<<endl;
    return 0;
}
