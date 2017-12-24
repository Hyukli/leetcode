#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int stoi(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> dp(10000,0);
        map<int,int> m;
        for(int i=0;i<deadends.size();i++)
        {
            m[stoi(deadends[i])]=1;
        }
        int an=stoi(target);
        int step=0;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            vector<int> v;
            while(!q.empty())
            {
                v.push_back(q.front());
                q.pop();
            }
            for(int i=0;i<v.size();i++)
            {
                int t;
            int k=v[i];
            if(m.find(k)==m.end()&&!dp[k])
            {
                dp[k]=step;
                //cout<<k<<" "<<dp[k]<<endl;
                int a1,a2,a3,a4;
                a1=k%10;
                a2=k/10%10;
                a3=k/100%10;
                a4=k/1000;
                if(a1!=9)
                {
                    t=k+1;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k-9;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a1!=0)
                {
                    t=k-1;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k+9;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a2!=9)
                {
                    t=k+10;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k-90;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a2!=0)
                {
                    t=k-10;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k+90;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a3!=9)
                {
                    t=k+100;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k-900;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a3!=0)
                {
                    t=k-100;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k+900;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a4!=9)
                {
                    t=k+1000;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k-9000;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                if(a4!=0)
                {
                    t=k-1000;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
                else
                {
                    t=k+9000;
                    if(!dp[t])
                    {
                        q.push(t);
                    }
                }
            }
            }
            step++;
        }
        //cout<<an<<endl;
        if(dp[an])
        {
            return dp[an];
        }
        return -1;
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
    string target;
    cin>>target;
    cout<<s.openLock(v,target)<<endl;
    return 0;
}
