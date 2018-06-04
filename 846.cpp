#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> m;
        for(auto h:hand)
        {
            m[h]++;
        }
        int k=hand.size()%W;
        if(k)   return false;
        k=hand.size()/W;
        while(k--)
        {
            int be=(*m.begin()).first;
            for(int i=0;i<W;i++)
            {
                if(m.find(be+i)==m.end())   return false;
                m[be+i]--;
                if(!m[be+i])    m.erase(be+i);
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int n,w;
    cin>>n>>w;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<(s.isNStraightHand(v,w)?"Yes":"No")<<endl;
    return 0;
}
