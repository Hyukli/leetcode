#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<char> v;
        preorder+=",";
        for(int i=0;i<preorder.size();i++)
        {
            if(preorder[i]==','&&preorder[i-1]=='#')
            {
                v.push_back('#');
            }
            else if(preorder[i]==','&&preorder[i-1]!='#')
            {
                v.push_back('*');
            }
        }
        stack<int> s;
        if(v.size()==1&&v[0]=='#')
        {
            return true;
        }
        if(v[0]=='#')
        {
            return false;
        }
        s.push(1);
        s.push(1);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]=='#')
            {
                if(s.empty())
                {
                    return false;
                }
                s.pop();
            }
            if(v[i]=='*')
            {
                if(s.empty())
                {
                    return false;
                }
                s.push(1);
            }
        }
        if(!s.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<(s.isValidSerialization(ss)?"Yes":"No")<<endl;
    return 0;
}
