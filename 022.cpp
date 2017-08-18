#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s="(";
        fun(n,1,0,s,result);
        return result;
    }
private:
    int fun(int n,int left,int right,string s,vector<string> &result)
    {
        if(n==left&&n==right)
        {
            result.push_back(s);
        }
        else if(left!=n)
        {
            if(right<left)
            {
                string tmp=s;
                s+=")";
                fun(n,left,right+1,s,result);
                s=tmp;
                s+="(";
                fun(n,left+1,right,s,result);
            }
            else
            {
                s+="(";
                fun(n,left+1,right,s,result);
            }
        }
        else
        {
            s+=")";
            fun(n,left,right+1,s,result);
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<string> v;
    int n;
    cin>>n;
    v=s.generateParenthesis(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
