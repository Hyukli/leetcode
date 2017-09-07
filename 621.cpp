#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k=tasks.size();
        if(k==0)
        {
            return 0;
        }
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0;i<tasks.size();i++)
        {
            a[tasks[i]-'A']++;
        }
        int maxx=0;
        int maxt=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]>maxx)
            {
                maxx=a[i];
                maxt=1;
            }
            else if(a[i]==maxx)
            {
                maxt++;
            }
        }
        int ans=max(k,(maxx-1)*(n+1)+maxt);
        return ans;
    }
};

int main()
{
    Solution s;
    int m;
    int n;
    cin>>m>>n;
    vector<char> t(m);
    for(int i=0;i<m;i++)
    {
        cin>>t[i];
    }
    cout<<s.leastInterval(t,n)<<endl;
    return 0;
}
