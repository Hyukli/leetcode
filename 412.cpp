#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int i=1;i<=n;i++)
        {
            if(i%3&&i%5)
            {
                stringstream ss;
                string str;
                ss<<i;
                ss>>str;
                v.push_back(str);
            }
            else if(i%3==0&&i%5)
            {
                v.push_back("Fizz");
            }
            else if(i%5==0&&i%3)
            {
                v.push_back("Buzz");
            }
            else
            {
                v.push_back("FizzBuzz");
            }
        }
        return v;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<string> v=s.fizzBuzz(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<"\""<<v[i]<<"\"";
        if(i!=v.size()-1)
        {
            cout<<","<<endl;
        }
    }
    return 0;
}
