#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        vector<int> v;
        string s;
        if(num<0)
        {
            num=-num;
            s+='-';
        }
        else if(num==0)
        {
            s='0';
            return s;
        }

        while(num)
        {
            v.push_back(num%7);
            num/=7;
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            s+=(v[i]+'0');
        }
        return s;
    }
};

int main()
{

    int n;
    cin>>n;
    Solution s;
    cout<<s.convertToBase7(n)<<endl;
}
