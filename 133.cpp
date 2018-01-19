/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
        {
            return NULL;
        }
        int be=node->label;
        map<int,UndirectedGraphNode*> m;
        UndirectedGraphNode *ans;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        int flag=0;
        while(!q.empty())
        {
            UndirectedGraphNode* k=q.front();

            q.pop();
            if(m.find(k->label)==m.end())
            {
                UndirectedGraphNode* p=new UndirectedGraphNode(k->label);
                if(flag==0)
                {
                    flag=1;
                    ans=p;
                }
                m[p->label]=p;
                for(int i=0;i<(k->neighbors).size();i++)
                {
                    q.push((k->neighbors)[i]);
                }
            }
        }
        q.push(node);
        map<int,int> mm;
        while(!q.empty())
        {
            UndirectedGraphNode* c=q.front();
            q.pop();
            if(mm.find(c->label)==mm.end())
            {
                mm[c->label]=1;
                for(int i=0;i<c->neighbors.size();i++)
                {
                    m[c->label]->neighbors.push_back(m[c->neighbors[i]->label]);
                    q.push(c->neighbors[i]);
                }
            }
        }
        return ans;
    }
};
