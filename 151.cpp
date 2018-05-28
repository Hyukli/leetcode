#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseword(string &s,int i,int j)
    {
        while(i<j)
        {
            char t=s[i];
            s[i++]=s[j];
            s[j--]=t;
        }
    }

    void reverseWords(string &s) {
        int i=0,j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;

        while(true)
        {
            while(i<len&&s[i]==' ') i++;//�������пո�
            if(i==len)  break;
            if(wordcount)  s[j++]=' ';//��֤��һ����ĸǰ��û�ո�֮���ǰ�涼��
            l=j;//������ʼλ��
            while(i<len&&s[i]!=' ') {s[j++]=s[i++];}
            reverseword(s,l,j-1);
            wordcount++;
        }
        s.resize(j);
        reverseword(s,0,j-1);
    }
};

int main()
{
    Solution s;
    string ss;
    getline(cin,ss);
    s.reverseWords(ss);
    cout<<ss<<endl;
    return 0;
}
