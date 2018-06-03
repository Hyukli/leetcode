#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1,s2;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]!='#')
            {
                s1.push(S[i]);
            }
            else
            {
                if(!s1.empty())
                {
                    s1.pop();
                }
            }
        }
        for(int i=0;i<T.size();i++)
        {
            if(T[i]!='#')
            {
                s2.push(T[i]);
            }
            else
            {
                if(!s2.empty())
                {
                    s2.pop();
                }
            }
        }
        while(!s1.empty()&&!s2.empty())
        {
            if(s1.top()!=s2.top())
            {
                return false;
            }
            s1.pop();
            s2.pop();
        }
        if(!s1.empty()||!s2.empty())    return false;
        return true;
    }
};

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    Solution s;
    cout<<(s.backspaceCompare(s1,s2)?"Yes":"No")<<endl;
    return 0;
}
