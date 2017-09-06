#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        map<int,int> m;
        return fun(price,special,m,get_key(needs));
    }
private:
    int fun(vector<int> &price,vector<vector<int> >& special,map<int,int> &m,int k)
    {
        if(m.count(k))
        {
            return m[k];
        }
        int n=price.size(),ans=0;
        vector<int> pows(n,1);
        for(int i=n-2;i>=0;i--)
        {
            pows[i]=pows[i+1]*10;
        }
        for(int i=0;i<n;i++)
        {
            ans+=((k/pows[i])%10)*price[i];
        }
        for(int j=0;j<special.size();j++)
        {
            vector<int> spe=special[j];
            int key=0,i=0;
            while(i<n)
            {
                int t=(k/pows[i])%10;
                if(t>=spe[i]){
                    key = key*10+(t-spe[i++]);
                }
                else
                {
                    break;
                }
            }
            if(i==n)
            {
                ans=min(ans,spe[n]+fun(price,special,m,key));
            }
        }
        m[k]=ans;
        return ans;
    }
    int get_key(vector<int>& needs)
    {
        int n=needs.size(),key=0;
        for(int i=n-1,p=1;i>=0;i--,p*=10)
        {
            key+=needs[i]*p;
        }
        return key;
    }
};

int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;
    vector<int> prices(n),buy(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    vector<vector<int> > V;
    for(int i=0;i<m;i++)
    {
        vector<int> v(n+1);
        for(int j=0;j<=n;j++)
        {
            cin>>v[j];
        }
        V.push_back(v);
    }
    for(int i=0;i<n;i++)
    {
        cin>>buy[i];
    }
    cout<<s.shoppingOffers(prices,V,buy)<<endl;
    return 0;
}
