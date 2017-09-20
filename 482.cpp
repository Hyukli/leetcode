#include<iostream>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]>='0'&&S[i]<='9')
            {
                s+=S[i];
            }
            else if(S[i]>='a'&&S[i]<='z')
            {
                s+=(S[i]+'A'-'a');
            }
            else if(S[i]>='A'&&S[i]<='Z')
            {
                s+=(S[i]);
            }
        }
        int k=0;
        int n=s.size();
        for(int i=n-1;i>0;i--)
        {
            k++;
            if(k==K)
            {
                s.insert(i,"-");
                k=0;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ss;
    int k;
    cin>>ss>>k;
    cout<<s.licenseKeyFormatting(ss,k)<<endl;
    return 0;
}
