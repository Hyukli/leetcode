#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(9);
        v[0]=1;
        for(int i=1;i<9;i++)
        {
            v[i]=v[i-1]*i;
        }
        vector<int> v1;
        vector<int> num;
        for(int i=1;i<=n;i++)
        {
            num.push_back(i);
        }
        k--;
        for(int i=n-1;i>0;i--)
        {
            v1.push_back(k/v[i]);
            k%=v[i];
        }
        v1.push_back(0);
        string s="";
        for(int i=0;i<v1.size();i++)
        {
            char c=('0'+num[v1[i]]);
            s+=c;
            num.erase(num.begin()+v1[i]);
        }
        return s;
    }
};

int main()
{
    Solution s;
    int n,k;
    cin>>n>>k;
    cout<<s.getPermutation(n,k)<<endl;
    return 0;
}
