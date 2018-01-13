#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution():m(1<<20,0){};
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int M=maxChoosableInteger,T=desiredTotal;
        int S=M*(M+1)/2;
        return T<2?true:S<T?false:S==T?M%2:dfs(M,T,0);
    }

    bool dfs(int M,int T,int k)
    {
        if(T<=0||m[k])  return T>0&&m[k]>0;
        for(int i=0;i<M;i++)
        {
            if(!(k&1<<i)&&!dfs(M,T-i-1,k|1<<i)) return m[k]=1;
        }
        return !(m[k]=-1);
    }
private:
    vector<int> m;
};

int main()
{
    Solution s;
    int m,d;
    cin>>m>>d;
    cout<<(s.canIWin(m,d)?"Yes":"No")<<endl;
    return 0;
}
