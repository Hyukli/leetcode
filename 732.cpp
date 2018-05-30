#include<iostream>
#include<vector>
#include<map>
using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int k=0,ans=0;
        for(auto t: m)
        {
            k+=t.second;
            ans=max(k,ans);
        }
        return ans;
    }
private:
        map<int,int> m;
};

int main()
{
    MyCalendarThree mc=MyCalendarThree();
    int n;
    cin>>n;
    while(n--)
    {
        int s,e;
        cin>>s>>e;
        cout<<mc.book(s,e)<<endl;
    }
    return 0;
}
