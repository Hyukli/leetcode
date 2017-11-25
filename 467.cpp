#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0;i<p.size();)
        {
            char c=p[i];
            int k=1;
            while(i+1<p.size()&&(p[i+1]+26-p[i])%26==1)
            {
                i++;
                k++;
            }
            for(int j=0;j<k;j++)
            {
                int t=c-'a'+j;
                t%=26;
                a[t]=max(a[t],k-j);
            }
            i++;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=a[i];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.findSubstringInWraproundString(ss)<<endl;
    return 0;
}
