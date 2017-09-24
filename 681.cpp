#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        string ans=time;
        int min=24*60;
        int a[4];
        a[0]=time[0]-'0';
        a[1]=time[1]-'0';
        a[2]=time[3]-'0';
        a[3]=time[4]-'0';
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    for(int l=0;l<4;l++)
                    {
                        int t=a[i]*1000+a[j]*100+a[k]*10+a[l];
                        if(isc(t))
                        {
                            if(sub(t,time)<min)
                            {
                                //cout<<min<<" ";
                                ans=tos(t);
                                min=sub(t,time);
                                //cout<<min<<endl;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
private:
    bool isc(int s)
    {
        int a1=s/100;
        int a3=s%100;
        if(a1<24&&a3<60)
        {
            return true;
        }
        return false;
    }
    int sub(int t,string time)
    {
        int a1=t/100;
        int a2=t%100;
        int k=a1*60+a2+1440;
        int a,b,c,d;
        a=time[0]-'0';
        b=time[1]-'0';
        c=time[3]-'0';
        d=time[4]-'0';
        int k2=(a*10+b)*60+c*10+d;
        int ans=(k-k2)%1440;
        //cout<<k<<" "<<k2<<" "<<ans<<endl;
        if(ans==0)
        {
            ans=1440;
        }
        return ans;
    }
    string tos(int t)
    {
        string ans;
        int a=t/1000;
        int b=t/100%10;
        int c=t/10%10;
        int d=t%10;
        ans+=(a+'0');
        ans+=(b+'0');
        ans+=":";
        ans+=(c+'0');
        ans+=(d+'0');
        return ans;
    }
};

int main()
{
    Solution s;
    string ss;
    cin>>ss;
    cout<<s.nextClosestTime(ss)<<endl;
    return 0;
}
