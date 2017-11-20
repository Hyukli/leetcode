#include<iostream>
#include<vector>
using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int,int>> v1,v2;
public:
    MyCalendarTwo() {
        v1.clear();
        v2.clear();
    }

    bool book(int start, int end) {
        for(int i=0;i<v2.size();i++)
        {
            if(!(end<=v2[i].first||start>=v2[i].second))
            {
                return false;
            }
        }
        for(int i=0;i<v1.size();i++)
        {
            if(!(end<=v1[i].first||start>=v1[i].second))
            {
                v2.push_back(make_pair(max(v1[i].first,start),min(v1[i].second,end)));
            }
        }
        v1.push_back(make_pair(start,end));
        return true;
    }
};


int main()
{
    MyCalendarTwo obj =  MyCalendarTwo();
    int n;
    cin>>n;
    while(n--)
    {
        int s,t;
        cin>>s>>t;
        cout<<(obj.book(s,t)?"Yes":"No")<<endl;
    }
    return 0;
}

