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
    cout<<"������Ҫִ�еĲ���������"<<endl;
    int n;
    cin>>n;
    while(n--)
    {
        cout<<"������Ҫִ�еĲ�������1�������أ�2��ˢ�����أ�3���ӹ�ע��4��ȡ�أ�"<<endl;
        int t;
        cin>>t;
        int i,j;
        switch(t)
        {
        case 1:
        {
            cout<<"���뷢�����˵ı�ţ�"<<endl;
            cin>>i;
            cout<<"���뷢�������ر�ţ�"<<endl;
            cin>>j;
            T.postTweet(i,j);
            break;
        }

        case 2:
        {
            cout<<"����ˢ�������˵ı�ţ�"<<endl;
            cin>>i;
            vector<int> ans=T.getNewsFeed(i);
            for(auto a:ans) cout<<a<<" ";
            cout<<endl;
            break;
        }

        case 3:
        {
            cout<<"���뷢���ע�˵ı�ţ�"<<endl;
            cin>>i;
            cout<<"���뱻��ע�˵ı�ţ�"<<endl;
            cin>>j;
            T.follow(i,j);
            break;
        }

        case 4:
        {
            cout<<"����ȡ����ע�˵ı�ţ�"<<endl;
            cin>>i;
            cout<<"���뱻ȡ����ע�˵ı�ţ�"<<endl;
            cin>>j;
            T.unfollow(i,j);
            break;
        }

        }
    }
    return 0;
}
