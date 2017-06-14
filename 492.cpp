#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w=sqrt(area);
        int l;
        vector<int> ans;
        for(w;w>0;w--)
        {
            if(area%w==0)
            {
                l=area/w;
                break;
            }
        }
        ans.push_back(l);
        ans.push_back(w);
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution s;
    vector<int> v;
    v=s.constructRectangle(n);
    cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}
