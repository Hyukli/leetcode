#include<iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int an,ln,lt;
        an=ln=lt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A')
            {
                an++;
                if(an==2)
                {
                    return false;
                }
            }
            if(s[i]=='L')
            {
                lt++;
                if(lt==3)
                {
                    return false;
                }
            }
            else
            {
                lt=0;
            }
        }
        return true;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<(ss.checkRecord(s)?"True":"False")<<endl;
    return 0;
}
