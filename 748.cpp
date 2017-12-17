#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> v(26,0);
        for(int i=0;i<licensePlate.size();i++)
        {
            if(licensePlate[i]>='a'&&licensePlate[i]<='z')
            {
                v[licensePlate[i]-'a']++;
            }
            if(licensePlate[i]>='A'&&licensePlate[i]<='Z')
            {
                v[licensePlate[i]-'A']++;
            }
        }
        int aa[26];
        int minl=1005;
        string ans;
        for(int i=0;i<words.size();i++)
        {
            memset(aa,0,sizeof(aa));
            int flag=0;
            for(int j=0;j<words[i].size();j++)
            {
                if(words[i][j]>='a'&&words[i][j]<='z')
                {
                    aa[words[i][j]-'a']++;
                }
                if(words[i][j]>='A'&&words[i][j]<='Z')
                {
                    aa[words[i][j]-'A']++;
                }
            }
            for(int j=0;j<26;j++)
            {
                if(aa[j]<v[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                continue;
            }
            else if(words[i].size()<minl)
            {
                ans=words[i];
                minl=words[i].size();
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1;
    cin>>s1;
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.shortestCompletingWord(s1,v)<<endl;
    return 0;
}
