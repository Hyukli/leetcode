#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx=0;
        int n=height.size();
        for(int i=0,j=n-1;i<j;)
        {
            maxx=max(maxx,min(height[i],height[j])*(j-i));
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxx;
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
    cout<<s.maxArea(v)<<endl;
    return 0;
}
