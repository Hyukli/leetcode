#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        int n=senate.size();
        for(int i=0;i<senate.size();i++)
        {
            (senate[i]=='R')?q1.push(i):q2.push(i);
        }
        while(!q1.empty()&&!q2.empty())
        {
            int r=q1.front(),d=q2.front();
            q1.pop();
            q2.pop();
            if(r<d)
            {
                q1.push(r+n);
            }
            else
            {
                q2.push(d+n);
            }
        }
        return q1.size()==0?"Dire":"Radiant";
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.predictPartyVictory(ss)<<endl;
    return 0;
}
