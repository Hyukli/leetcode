#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        auto p_mid=nums.begin()+n/2;
        nth_element(nums.begin(),p_mid,nums.end());
        int mid=*p_mid;

        #define A(i) nums[(1+(i*2))%(n|1)]

        int i=0,j=0,k=n-1;
        while(j<=k)
        {
            cout<<i<<" "<<j<<" "<<k<<endl;
            if(A(j)>mid)
                swap(A(i++),A(j++));
            else if(A(j)<mid)
            {
                swap(A(j),A(k--));
            }
            else
            {
                j++;
            }
            for(auto a:nums)
            {
                cout<<a<<" ";
            }
            cout<<endl;
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
    s.wiggleSort(v);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
