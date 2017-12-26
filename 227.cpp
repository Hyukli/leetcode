#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stringstream in('+'+s+'+');
        long long total=0,term=0,n;
        char op;
        while(in>>op)
        {
            if(op=='+'||op=='-')
            {
                total+=term;
                in>>term;
                term*=44-op;
            }
            else
            {
                in>>n;
                if(op=='*')
                {
                    term*=n;
                }
                else
                {
                    term/=n;
                }
            }
        }
        return total;
    }
};

int main()
{
    Solution ss;
    string s;
    getline(cin,s);
    cout<<ss.calculate(s)<<endl;
    return 0;
}
