#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v;
        for(int i=0;i<words.size();i++)
        {
            v.push_back(fun(words[i]));
        }
        int ma=0;
        for(int i=0;i<v.size();i++)
        {
            //cout<<v[i]<<endl;
            for(int j=i;j<v.size();j++)
            {
                if((v[i]&v[j])==0)
                {
                    int t=words[i].size()*words[j].size();
                    ma=max(ma,t);
                }
            }
        }
        return ma;
    }
private:
    int fun(string s)
    {
        int a[26];
        int ans=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i])
            {
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<string> ss(n);
    for(int i=0;i<n;i++)
    {
        cin>>ss[i];
    }
    cout<<s.maxProduct(ss)<<endl;
    return 0;
}
