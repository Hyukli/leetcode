#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty())   return 1;
        int k=b[b.size()-1];
        b.pop_back();
        return pow(superPow(a,b),10)*pow(a,k)%base;
    }
private:
    const int base=1337;
    int pow(int a,int k)
    {
        a%=base;
        int result=1;
        for(int i=0;i<k;i++)
        {
            result*=a;
            result%=base;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int a,n;
    cin>>a>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.superPow(a,v)<<endl;
    return 0;
}
