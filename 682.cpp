#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
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
    int calPoints(vector<string>& ops) {
        stack<long long> s;
        int sum=0;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="D")
            {
                long long t=2*s.top();
                s.push(t);
                sum+=s.top();
            }
            else if(ops[i]=="C")
            {
                long long t=s.top();
                sum-=t;
                s.pop();
            }
            else if(ops[i]=="+")
            {
                int t1=s.top();
                s.pop();
                int t2=s.top();
                int k=t1+t2;
                s.push(t1);
                s.push(k);
                sum+=k;
            }
            else
            {
                int t=stoi(ops[i]);
                sum+=t;
                s.push(t);
            }
        }
        return sum;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.calPoints(v)<<endl;
    return 0;
}
