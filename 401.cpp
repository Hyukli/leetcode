#include<iostream>
#include<vector>
#include<strstream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        Node nn(0,0);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    for(int l=0;l<2;l++)
                    {
                        for(int m=0;m<2;m++)
                        {
                            for(int n=0;n<2;n++)
                            {
                                for(int o=0;o<2;o++)
                                {
                                    for(int p=0;p<2;p++)
                                    {
                                        for(int q=0;q<2;q++)
                                        {
                                            for(int r=0;r<2;r++)
                                            {
                                                if(i+j+k+l+m+n+o+p+q+r==num)
                                                {
                                                    nn.h=(i*8+j*4+k*2+l*1);
                                                    nn.m=(m*32+n*16+o*8+p*4+q*2+r*1);
                                                    if(isTime(nn))
                                                    {
                                                        v.push_back(tostr(nn));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return v;
    }
private:
        struct Node
    {
        int h,m;
        Node(int x,int y):h(x),m(y){};
    };

    bool isTime(Node s)
    {
        if(s.h<12&&s.m<60)
        {
            return true;
        }
        return false;
    }
    string tostr(Node s)
    {
        string ans1,ans2;
        strstream ss;
        ss<<s.h;
        ss>>ans1;
        ans1+=':';
        int a=s.m/10;
        int b=s.m%10;
        ans1+=(a+'0');
        ans1+=(b+'0');
        return ans1;
    }
};

int main()
{
    int n;
    vector<string> v;
    cin>>n;
    Solution s;
    v=s.readBinaryWatch(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
