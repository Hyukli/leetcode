#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0)
        {
            return 0;
        }
        int j=s.size()-1;
        while(s[j]==' ')
        {
            s=s.substr(0,j--);
        }
        int tmp=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                tmp=0;
            }
            else
            {
                tmp++;
            }
        }
        return tmp;
    }
};

int main()
{
    string str;
    getline(cin,str);
    Solution s;
    cout<<s.lengthOfLastWord(str)<<endl;
    return 0;
}
