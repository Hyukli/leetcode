#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n=fronts.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(fronts[i]==backs[i])
            {
                m[fronts[i]]++;
            }
        }
        int ans=3000;
        for(int i=0;i<n;i++)
        {
            if(fronts[i]<ans&&m.find(fronts[i])==m.end())
            {
                ans=fronts[i];
            }
            if(backs[i]<ans&&m.find(backs[i])==m.end())
            {
                ans=backs[i];
            }
        }
        return ans==3000?0:ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> f(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cout<<s.flipgame(f,b)<<endl;
    return 0;
}
