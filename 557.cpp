#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<char> k;
        vector<char> v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                k.push(s[i]);
            }
            else
            {
                while(!k.empty())
                {
                    v.push_back(k.top());
                    k.pop();
                }
                v.push_back(' ');
            }
        }
        while(!k.empty())
        {
            v.push_back(k.top());
            k.pop();
        }
        string ss="";
        for(vector<char>::iterator i=v.begin();i<v.end();i++)
        {
            ss+=*i;
        }
        return ss;
    }
    ///第二种方法
    string reverseWords2(string s) {
        stack<char> k;
        string ss="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                k.push(s[i]);
            }
            else
            {
                while(!k.empty())
                {
                    ss+=(k.top());
                    k.pop();
                }
               ss+=' ';
            }
        }
        while(!k.empty())
        {
            ss+=(k.top());
            k.pop();
        }
        return ss;
    }
};

int main()
{
    string s;
    getline(cin,s);
    Solution ss;
    cout<<ss.reverseWords(s)<<endl;
    //cout<<ss.reverseWords2(s)<<endl;
    return 0;
}
