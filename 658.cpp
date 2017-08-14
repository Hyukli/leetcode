#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
    int x,cha;
};

bool cmp(const Node& a,const Node& b)
{
    if(a.cha!=b.cha)
    {
        return a.cha<b.cha;
    }
    return a.x<b.x;
}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<Node> v;
        for(int i=0;i<arr.size();i++)
        {
            Node n;
            n.x=arr[i];
            n.cha=abs(n.x-x);
            v.push_back(n);
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution ss;
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> v(n),ans(k);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    Solution s;
    ans=s.findClosestElements(v,k,x);
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
