#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

struct Node
{
    int t;
    int p;
};

bool cmp(const Node& a,const Node& b)
{
    return a.t>b.t;
}

class Twitter
{
public:
    /** Initialize your data structure here. */

    Twitter()
    {
        for(int i=0; i<10005; i++)
        {
            set<int> s;
            s.insert(i);
            fl.push_back(s);
            vector<Node> vv;
            v.push_back(vv);
        }
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        Node n;
        n.t=k++;
        n.p=tweetId;
        v[userId].push_back(n);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<Node> no;
        for(auto f:fl[userId])
        {
            for(auto ff:v[f])
            {
                no.push_back(ff);
            }
        }
        sort(no.begin(),no.end(),cmp);
        vector<int> ans;
        for(int i=0; i<no.size()&&i<10; i++)
        {
            ans.push_back(no[i].p);
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        fl[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if(followerId!=followeeId)
        {
            fl[followerId].erase(followeeId);
        }
    }
private:
    vector<set<int>> fl;
    vector<vector<Node>> v;
    int k=0;
};

int main()
{
    Twitter T;
    Twitter();
    cout<<"输入你要执行的操作个数："<<endl;
    int n;
    cin>>n;
    while(n--)
    {
        cout<<"输入你要执行的操作：（1：发推特，2：刷新推特，3：加关注，4：取关）"<<endl;
        int t;
        cin>>t;
        int i,j;
        switch(t)
        {
        case 1:
        {
            cout<<"输入发推特人的编号："<<endl;
            cin>>i;
            cout<<"输入发布的推特编号："<<endl;
            cin>>j;
            T.postTweet(i,j);
            break;
        }

        case 2:
        {
            cout<<"输入刷新推特人的编号："<<endl;
            cin>>i;
            vector<int> ans=T.getNewsFeed(i);
            for(auto a:ans) cout<<a<<" ";
            cout<<endl;
            break;
        }

        case 3:
        {
            cout<<"输入发起关注人的编号："<<endl;
            cin>>i;
            cout<<"输入被关注人的编号："<<endl;
            cin>>j;
            T.follow(i,j);
            break;
        }

        case 4:
        {
            cout<<"输入取消关注人的编号："<<endl;
            cin>>i;
            cout<<"输入被取消关注人的编号："<<endl;
            cin>>j;
            T.unfollow(i,j);
            break;
        }

        }
    }
    return 0;
}
