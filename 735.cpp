#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> q;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++)
        {
            if(q.empty())
            {
                if(asteroids[i]<0)
                {
                    ans.push_back(asteroids[i]);
                }
                else
                {
                    q.push(asteroids[i]);
                }
            }
            else
            {
                if(asteroids[i]>0)
                {
                    q.push(asteroids[i]);
                }
                else
                {
                    int t=0;
                    while(!q.empty())
                    {
                        if(q.top()<-asteroids[i])
                        {
                            q.pop();
                        }
                        else if(q.top()==-asteroids[i])
                        {
                            q.pop();
                            t=1;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(q.empty())
                    {
                        if(!t)
                        {
                            ans.push_back(asteroids[i]);
                        }
                    }
                }
            }
        }
        int k=ans.size();
        while(!q.empty())
        {
            ans.insert(ans.begin()+k,q.top());
            q.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> ans=s.asteroidCollision(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
