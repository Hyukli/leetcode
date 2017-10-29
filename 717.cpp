#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i;
        for(i=0;i<bits.size()-1;)
        {
            if(bits[i]==0)
            {
                i++;
            }
            else
            {
                i+=2;
            }
        }
        if(i==bits.size()-1)
        {
            return true;
        }
        return false;
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
    cout<<(s.isOneBitCharacter(v)?"Yes":"No")<<endl;
    return 0;
}
