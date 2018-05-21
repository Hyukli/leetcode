#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> flag(n,0);
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]!='.')
            {
                flag[i]=1;
            }
            if(dominoes[i]=='L')
            {
                v[i]=-100005;
            }
            if(dominoes[i]=='R')
            {
                v[i]=100005;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='R')
            {
                int j=i+1;
                int k=v[i];
                while(j<n&&!flag[j])
                {
                    v[j]+=(k--);
                    j++;
                }
            }
            if(dominoes[i]=='L')
            {
                int j=i-1;
                int k=v[i];
                while(j>=0&&!flag[j])
                {
                    v[j]+=(k++);
                    j--;
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                ans+=".";
            }
            else if(v[i]>0)
            {
                ans+="R";
            }
            else
            {
                ans+="L";
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.pushDominoes(ss)<<endl;
    return 0;
}
