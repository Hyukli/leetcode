#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(int i=0;i<timePoints.size();i++)
        {
            int k=fun(timePoints[i]);
            v.push_back(k);
            v.push_back(k+24*60);
        }
        sort(v.begin(),v.end());
        int ans=v[1]-v[0];
        for(int i=2;i<v.size();i++)
        {
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
private:
    int fun(string s)
    {
        stringstream ss;
        ss<<s;
        int h,m;
        char c;
        ss>>h>>c>>m;
        return h*60+m;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    cout<<s.findMinDifference(v)<<endl;
    return 0;
}
