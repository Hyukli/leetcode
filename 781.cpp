#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v(1000,0);
        int ans=0;
        for(int i=0;i<answers.size();i++)
        {
            v[answers[i]]++;
        }
        for(int i=0;i<1000;i++)
        {
            ans+=(v[i]/(i+1))*(i+1);
            if(v[i]%(i+1)!=0)
            {
                ans+=(i+1);
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
    cout<<s.numRabbits(v)<<endl;
    return 0;
}
