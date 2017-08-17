#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int i=2;
        while(s.size()<n)
        {
            s+=string(s[i++]-'0',s.back()^3);
        }
        cout<<s<<endl;
        return count(s.begin(),s.begin()+n,'1');
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.magicalString(n)<<endl;
    return 0;
}
