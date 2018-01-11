#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int to_int(string s)
{
    int flag=0;
    if(s[0]=='-')
    {
        flag=1;
        s=s.substr(1);
    }
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans*=10;
        ans+=(s[i]-'0');
    }
    if(flag)
    {
        ans=-ans;
    }
    return ans;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int a1=s.top();
                s.pop();
                int a2=s.top();
                s.pop();
                s.push(a1+a2);
            }
            else if(tokens[i]=="-")
            {
                int a1=s.top();
                s.pop();
                int a2=s.top();
                s.pop();
                s.push(a2-a1);
            }
            else if(tokens[i]=="*")
            {
                int a1=s.top();
                s.pop();
                int a2=s.top();
                s.pop();
                s.push(a1*a2);
            }
            else if(tokens[i]=="/")
            {
                int a1=s.top();
                s.pop();
                int a2=s.top();
                s.pop();
                s.push(a2/a1);
            }
            else
            {
                s.push(to_int(tokens[i]));
            }
        }
        return s.top();
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
    cout<<s.evalRPN(v)<<endl;

    return 0;
}
