#include<iostream>
#include<vector>
using namespace std;

//class Solution
//{
//public:
//    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
//    {
//        int m = nums.size(), n = nums[0].size();
//        if (m * n != r * c)
//        {
//            return nums;
//        }
//
//        vector<vector<int>> res(r, vector<int>(c, 0));
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                int k = i * n + j;
//                res[k / c][k % c] = nums[i][j];
//            }
//        }
//
//        return res;
//    }
//};

class Solution
{
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c)
    {
        vector<int> tmp;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                tmp.push_back(nums[i][j]);
            }
        }
        if(tmp.size()==r*c)
        {
            int t=0;
            vector<vector<int> > ans;
            for(int i=0; i<r; i++)
            {
                vector<int> x;
                for(int j=0; j<c; j++)
                {
                    x.push_back(tmp[t++]);
                }
                ans.push_back(x);
            }
            return ans;
        }
        else
        {
            return nums;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > v;
    vector<vector<int> > ans;
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    for(int i=0;i<n;i++)
    {
        vector<int > t;
        for(int j=0;j<m;j++)
        {
            int tmp;
            cin>>tmp;
            t.push_back(tmp);
        }
        v.push_back(t);
    }
    ans=s.matrixReshape(v,r,c);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
