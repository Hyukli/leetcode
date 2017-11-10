#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<vector<char>> v(8,vector<char>());
        v[0]={'a','b','c'};
        v[1]={'d','e','f'};
        v[2]={'g','h','i'};
        v[3]={'j','k','l'};
        v[4]={'m','n','o'};
        v[5]={'p','q','r','s'};
        v[6]={'t','u','v'};
        v[7]={'w','x','y','z'};
        dfs(digits,v,0,"");
        return ans;
    }
private:
    vector<string> ans;
    int dfs(string digits,vector<vector<char>> v,int index,string s)
    {
        if(index==digits.size())
        {
            if(s.size()!=0)
            {
                ans.push_back(s);
            }
            return 0;
        }
        else
        {
            for(int i=0;i<v[digits[index]-2-'0'].size();i++)
            {
                char c=v[digits[index]-2-'0'][i];
                s+=c;
                dfs(digits,v,index+1,s);
                s=s.substr(0,s.size()-1);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    vector<string> ans;
    ans=s.letterCombinations(ss);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
