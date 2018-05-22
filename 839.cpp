#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            dp[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isS(A[i],A[j]))  merge(i,j);
            }
        }
        set<int> s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s.count(findRoot(i))==0)
            {
                s.insert(findRoot(i));
                ans++;
            }
        }
        return ans;
    }
private:
    int dp[2002];
    bool isS(string s1,string s2)
    {
        int n=0;
        int t1,t2;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                n++;
                if(n==1)    t1=i;
                else    t2=i;
            }
        }
        if(n==2&&s1[t1]==s2[t2]&&s1[t2]==s2[t1])    return true;
        return false;
    }

    int findRoot(int i)
    {
        if(dp[i]==i)
        {
            return i;
        }
        return dp[i]=findRoot(dp[i]);
    }

    int merge(int i,int j)
    {
        dp[findRoot(j)]=findRoot(i);
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.numSimilarGroups(v)<<endl;
    return 0;
}
