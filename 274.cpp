#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> v(n+1,0);
        for(auto c:citations)
        {
            if(c>=n)
            {
                v[n]++;
            }
            else
            {
                v[c]++;
            }
        }
        int total=0;
        for(int i=n;i>=0;i--)
        {
            total+=v[i];
            if(total>=i)
            {
                return i;
            }
        }
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<s.hIndex(v)<<endl;
    return 0;
}
