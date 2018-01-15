#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row)
    {
        int ans=0;
        for(int i=0;i<row.size();i+=2)
        {
            if(row[i]%2==0)
            {
                if(row[i+1]!=row[i]+1)
                {
                    for(int j=i+2;j<row.size();j++)
                    {
                        if(row[j]==row[i]+1)
                        {
                            swap(row[j],row[i+1]);
                            ans++;
                        }
                    }
                }
            }
            else
            {
                if(row[i+1]!=row[i]-1)
                {
                    for(int j=i+2;j<row.size();j++)
                    {
                        if(row[j]==row[i]-1)
                        {
                            swap(row[j],row[i+1]);
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
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
    cout<<s.minSwapsCouples(v)<<endl;
    return 0;
}
