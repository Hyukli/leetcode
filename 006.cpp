#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        string ans="";
        int n=s.size();
        vector<vector<char>> v(numRows);
        int t=0;
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            v[t].push_back(s[i]);
            if(flag)
            {
                t++;
                if(t==numRows)
                {
                    t-=2;
                    flag^=1;
                }
            }
            else if(!flag)
            {
                t--;
                if(t<0)
                {
                    t+=2;
                    flag^=1;
                }
            }
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                ans+=v[i][j];
                //cout<<v[i][j]<<" ";
            }
            //cout<<endl;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    int n;
    cin>>ss>>n;
    cout<<s.convert(ss,n)<<endl;
    return 0;
}
