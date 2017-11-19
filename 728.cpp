#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right;i++)
        {
            if(isf(i))
            {
                v.push_back(i);
            }
        }
        return v;
    }
private:
    bool isf(int i)
    {
        int j=i;
        while(j!=0)
        {
            int k=j%10;
            if(k==0)
            {
                return false;
            }
            if(i%k!=0)
            {
                return false;
            }
            j/=10;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int l,r;
    cin>>l>>r;
    vector<int> v=s.selfDividingNumbers(l,r);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
