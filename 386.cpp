#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        fun(0,n);
        return ans;
    }
private:
    vector<int> ans;
    int fun(int k,int n)
    {
        for(int i=0;i<=9;i++)
        {
            if(k+i<=n)
            {
                if(k+i!=0)
                {
                    ans.push_back(k+i);
                    fun(10*(k+i),n);
                }
            }
            else
            {
                break;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<int> v(n);
    v=s.lexicalOrder(n);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
