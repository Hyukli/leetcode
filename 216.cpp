#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        com(k,n,0,1,path,result);
        return result;
    }
private:
    int com(int k,int n,int tmp,int beg,vector<int> &path,vector<vector<int>> &result)
    {
        if(tmp==n&&k==0)
        {
            result.push_back(path);
            return 0;
        }
        else if(tmp>n||k<0)
        {
            return 0;
        }
        for(int i=beg;i<=9;i++)
        {
            path.push_back(i);
            com(k-1,n,tmp+i,i+1,path,result);
            path.pop_back();
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int k,n;
    cin>>k>>n;
    vector<vector<int> > V;
    V=s.combinationSum3(k,n);
    for(int i=0;i<V.size();i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
