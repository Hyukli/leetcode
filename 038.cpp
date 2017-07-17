#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        while(--n)
        {
            string ss="";
            int cnt=1;
            int tmp=s[0];
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==tmp)
                {
                    cnt++;
                }
                else
                {
                    ss+=(cnt+'0');
                    ss+=tmp;
                    cnt=1;
                    tmp=s[i];
                }
            }
            ss+=(cnt+'0');
            ss+=tmp;
            s=ss;
        }
        return s;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    cout<<s.countAndSay(n)<<endl;
    return 0;
}
