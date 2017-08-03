#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> v;
        for(int i=0;i<=N;i++)
        {
            v.push_back(0);
        }
        dfs(N,v);
        return ans;
    }
private:
    int ans=0;
    int dfs(int N,vector<int> v)
    {
        if(N==1)
        {
            ans++;
            return 0;
        }
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==0&&(N%i==0||i%N==0))
            {
                v[i]=1;
                dfs(N-1,v);
                v[i]=0;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.countArrangement(n)<<endl;
    return 0;
}
