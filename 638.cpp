#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<int,int> m;
        return fun(price,special,toint(needs),m);
    }
private:
    int toint(vector<int> v)
    {
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans*=10;
            ans+=v[i];
        }
        return ans;
    }
    
    int fun(vector<int>& price, vector<vector<int>>& special, int key,map<int,int>& m)
    {
        if(m.count(key))
        {
            return m[key];
        }
        int n=price.size();
        int ans=0;
        vector<int> v(n);
        for(int i=n-1;i>=0;i--)
        {
            v[i]=key%10;
            ans+=v[i]*price[i];
            //cout<<ans<<" "<<v[i]<<" "<<price[i]<<endl;
            key/=10;
        }
        //cout<<ans<<endl;
        for(int i=0;i<special.size();i++)
        {
            int k=0;
            vector<int> t=special[i];
            int j=0;
            while(j<n)
            {
                if(t[j]<=v[j])
                {
                    k*=10;
                    k+=(v[j]-t[j++]);
                }
                else
                {
                    break;
                }
            }
            if(j==n)
            {
                ans=min(ans,t[n]+fun(price,special,k,m));
            }
        }
        m[key]=ans;

        return ans;
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
