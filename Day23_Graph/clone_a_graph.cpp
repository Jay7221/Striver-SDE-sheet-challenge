#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
	map<graphNode*, graphNode*> cloneNode;
	map<graphNode*, bool> vis;
	function<void(graphNode*)> dfs;
	dfs = [&](graphNode *node){
		if(cloneNode[node] == NULL){
			cloneNode[node] = new graphNode(node -> data);
		}
		vis[node] = true;
		for(auto neighbour : node -> neighbours){
			if(!vis[neighbour]){
				dfs(neighbour);
			}
			cloneNode[node] -> neighbours.push_back(cloneNode[neighbour]);
		}
	};
	dfs(node);
	return cloneNode[node];
}
