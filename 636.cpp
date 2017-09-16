#include<iostream>
#include<cstdlib>
#include<sstream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct Node
{
    int num;
    bool flag;
    int time;
};

int stoi(string s)
{
    int n=0;
    for(int i=0;i<s.size();i++)
    {
        n*=10;
        n+=s[i]-'0';
    }
    return n;
}

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int kk;
        stack<pair<int,int>> sk;
        vector<int> ans(n,0);
        vector<Node> v;
        for(int i=0;i<logs.size();i++)
        {
            char c;
            int num;
            string s;
            stringstream ss(logs[i]);
            ss>>num>>c>>s;
            Node node;
            node.num=num;
            if(s[0]=='s')
            {
                s=s.substr(6);
                node.flag=0;
                node.time=stoi(s);
            }
            else
            {
                s=s.substr(4);
                node.flag=1;
                node.time=stoi(s);
            }
            cout<<node.num<<"!"<<node.flag<<"!"<<node.time<<endl;
            v.push_back(node);
            if(v[i].flag==0)
            {
                sk.push({v[i].num,v[i].time});
            }
            else
            {
                ans[v[i].num]+=(v[i].time-sk.top().second+1);
                kk=v[i].time-sk.top().second+1;
                sk.pop();
                if(!sk.empty())
                {
                    ans[sk.top().first]-=kk;
                }
            }
        }
        cout<<"$$$"<<endl;
        return ans;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    vector<int> ans;
    Solution s;
    ans=s.exclusiveTime(n,v);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
