#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if(path=="")
        {
            return "";
        }
        path+="/";
        int si=1;
        stack<string> s;
        for(int i=1;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                string tmp=path.substr(si,i-si);
                si=i+1;
                if(tmp==""||tmp==".")
                {
                    continue;
                }
                else if(tmp=="..")
                {
                    if(!s.empty())
                    {
                        s.pop();
                    }
                }
                else
                {
                    s.push(tmp);
                }
            }
        }
        string ans;
        while(!s.empty())
        {
            ans="/"+s.top()+ans;
            s.pop();
        }
        if(ans=="")
        {
            return "/";
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string p;
    cin>>p;
    cout<<s.simplifyPath(p)<<endl;
    return 0;
}
