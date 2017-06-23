#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int ss=s.size();
        for(int i=0;i<ss;)
        {
            if(i+k<=ss)
            {
                reverse(s.begin()+i,s.begin()+i+k);
                i+=k;
                if(i==ss)
                {
                    break;
                }
                else if(i+k<=ss)
                {
                    i+=k;
                }
                else
                {
                    break;
                }
            }
            else if(i+k>ss)
            {
                reverse(s.begin()+i,s.end());
                break;
            }
        }
        return s;
    }
};

int main()
{
    int n;
    string s;
    cin>>s>>n;
    Solution ss;
    cout<<ss.reverseStr(s,n)<<endl;
    return 0;
}
