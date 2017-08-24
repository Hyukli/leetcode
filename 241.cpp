#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    map<string,vector<int>> m;
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i=0;i<input.size();i++)
        {
            vector<int> left,right;
            if(input[i]=='+'||input[i]=='-'||input[i]=='*')
            {
                if(m.find(input.substr(0,i))==m.end())
                {
                    left=diffWaysToCompute(input.substr(0,i));
                    m[input.substr(0,i)]=left;
                }
                else
                {
                    left=m[input.substr(0,i)];
                }
                if(m.find(input.substr(i+1))==m.end())
                {
                    right=diffWaysToCompute(input.substr(i+1));
                    m[input.substr(i+1)]=right;
                }
                else
                {
                    right=m[input.substr(i+1)];
                }
                for(int j=0;j<left.size();j++)
                {
                    for(int k=0;k<right.size();k++)
                    {
                        if(input[i]=='-')
                        {
                            ans.push_back(left[j]-right[k]);
                        }
                        if(input[i]=='+')
                        {
                            ans.push_back(left[j]+right[k]);
                        }
                        if(input[i]=='*')
                        {
                            ans.push_back(left[j]*right[k]);
                        }
                    }
                }
            }
        }
        if(ans.empty())
        {
            ans.push_back(atoi(input.c_str()));
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string input;
    cin>>input;
    vector<int> ans;
    ans=s.diffWaysToCompute(input);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
