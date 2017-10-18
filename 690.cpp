#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans=0;
        queue<int> q;
        q.push(id);
        while(!q.empty())
        {
            int k=q.front();
            for(int i=0;i<employees.size();i++)
            {
                if(employees[i]->id==k)
                {
                    ans+=employees[i]->importance;
                    for(int j=0;j<employees[i]->subordinates.size();j++)
                    {
                        q.push(employees[i]->subordinates[j]);
                    }
                }
            }
            q.pop();
        }
        return ans;
    }
};

int main()
{
    int n,id;
    cin>>n>>id;
    vector<Employee*> v(n);
    for(int i=0;i<n;i++)
    {
        int k;
        Employee *e=new Employee();
        cin>>e->id>>e->importance>>k;
        for(int i=0;i<k;i++)
        {
            int t;
            cin>>t;
            e->subordinates.push_back(t);
        }
        v[i]=e;
    }
    Solution s;
    cout<<s.getImportance(v,id)<<endl;
    return 0;
}
