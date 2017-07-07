#include<iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int t1,t2,i;
        t1=t2=i=0;
        int j=s.size()-1;
        while(i<j)
        {
            for(;i<j;i++)
            {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                {
                    t1++;
                    break;
                }
            }
            for(;j>i;j--)
            {
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')
                {
                    t2++;
                    break;
                }
            }
            if(t1&&t2)
            {
                char tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
                t1=t2=0;
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};

int main()
{
    string s;
    Solution ss;
    cin>>s;
    cout<<ss.reverseVowels(s)<<endl;
    return 0;
}
