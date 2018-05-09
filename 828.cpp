#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string S) {
        long long ans=0;
        int n=S.size();
        for(int i=0;i<n;i++)
        {
            int l=i-1;
            for(;l>=0&&S[l]!=S[i];l--);
            int k=i+1;
            for(;k<n&&S[k]!=S[i];k++);
            ans+=(i-l)*(k-i);
            ans%=1000000007;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.uniqueLetterString(ss)<<endl;
    return 0;
}
