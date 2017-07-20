#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                s1.push('(');
            }
            else if(s[i]=='{')
            {
                s1.push('{');
            }
            else if(s[i]=='[')
            {
                s1.push('[');
            }
            else if(s[i]==')'&&!s1.empty()&&s1.top()=='(')
            {
                s1.pop();
            }
            else if(s[i]==']'&&!s1.empty()&&s1.top()=='[')
            {
                s1.pop();
            }
            else if(s[i]=='}'&&!s1.empty()&&s1.top()=='{')
            {
                s1.pop();
            }
            else
            {
                return false;
            }
        }
        if(s1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<(ss.isValid(s)?"Yes":"No")<<endl;
    return 0;
}
