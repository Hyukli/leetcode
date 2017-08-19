#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s="";
        vector<string> qian={"","M", "MM", "MMM"};
        vector<string> bai={"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> shi={"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ge={"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return s+qian[num/1000]+bai[num%1000/100]+shi[num%100/10]+ge[num%10];

    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    cout<<s.intToRoman(n)<<endl;
    return 0;
}
