#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves.size()==0)
        {
            return true;
        }
        int a,b,c,d;
        a=b=c=d=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='R')
            {
                a++;
            }
            if(moves[i]=='L')
            {
                b++;
            }
            if(moves[i]=='U')
            {
                c++;
            }
            if(moves[i]=='D')
            {
                d++;
            }
        }
        if(a==b&&c==d)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string s;
    cin>>s;
    Solution ss;
    cout<<(ss.judgeCircle(s)?"Yes":"No")<<endl;
    return 0;
}
