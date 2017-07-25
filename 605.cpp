#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1)
        {
            if(n==0)
            {
                return true;
            }
            else if(n==1&&flowerbed[0]==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(flowerbed.size()==2)
        {
            if(n==0)
            {
                return true;
            }
            else if(n==1&&flowerbed[0]==0&&flowerbed[1]==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int ans=0;
        if(flowerbed[0]==0&&flowerbed[1]==0)
        {
            flowerbed[0]=1;
            ans++;
        }
        for(int i=1;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i-1]==0&&flowerbed[i+1]==0&&flowerbed[i]==0)
            {
                ans++;
                flowerbed[i]=1;
            }
        }
        if(flowerbed[flowerbed.size()-2]==0&&flowerbed[flowerbed.size()-1]==0)
        {
            flowerbed[flowerbed.size()-1]=1;
            ans++;
        }
        return n<=ans;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    Solution s;
    cout<<(s.canPlaceFlowers(v,m)?"Yes":"No")<<endl;
    return 0;
}
