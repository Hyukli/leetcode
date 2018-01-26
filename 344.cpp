#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<ss.reverseString(s)<<endl;
    return 0;
} 
