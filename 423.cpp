#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        string ans="";
        //string w[10]={"/zero","one","two","/three","/four","/five","/six","/seven","/eight","/nine"};
        map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        vector<int> a(10);
        for(int i=0;i<10;i++)
        {
            a[i]=0;
        }
        a[0]+=m['z'];
        m['e']-=m['z'];
        m['r']-=m['z'];
        m['o']-=m['z'];
        m['z']=0;
        a[4]+=m['u'];
        m['f']-=m['u'];
        m['o']-=m['u'];
        m['r']-=m['u'];
        m['u']=0;
        a[5]+=m['f'];
        m['v']-=m['f'];
        m['i']-=m['f'];
        m['e']-=m['f'];
        m['f']=0;
        a[6]+=m['x'];
        m['s']-=m['x'];
        m['i']-=m['x'];
        s['x']=0;
        a[7]+=m['s'];
        m['e']-=(2*m['s']);
        m['v']-=m['s'];
        m['n']-=m['s'];
        m['s']=0;
        a[8]+=m['g'];
        m['e']-=m['g'];
        m['i']-=m['g'];
        m['h']-=m['g'];
        m['t']-=m['g'];
        m['g']=0;
        a[9]+=m['i'];
        m['n']-=2*m['i'];
        m['e']-=m['i'];
        m['i']=0;
        a[3]+=m['h'];
        m['t']-=m['h'];
        m['r']-=m['h'];
        m['e']-=2*m['h'];
        a[2]=m['t'];
        a[1]=m['n'];
        for(int i=0;i<10;i++)
        {
            while(a[i]>0)
            {
                ans+=(i+'0');
                a[i]--; 
            }
        }
        return ans;
    }
};

int main()
{
    Solution ss;
    string s;
    cin>>s;
    cout<<ss.originalDigits(s)<<endl;
    return 0;
}
