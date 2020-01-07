/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> answer;
    vector<int> levelNodes;
    queue<Node*> cue;
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return answer;
        }
        
        cue.push(root);
        cue.push(NULL);
        
        while(cue.size() > 1)
        {
            Node* curr = cue.front();
            cue.pop();
            levelNodes.push_back(curr->val);
            
            while(curr != NULL)
            {
                for(auto child : curr->children)
                {
                    cue.push(child);
                }
                curr = cue.front();
                if(curr != NULL)
                    levelNodes.push_back(curr->val);
                cue.pop();
            }
            cue.push(NULL);
            if(curr == NULL)
            {
                answer.push_back(levelNodes);
                levelNodes.clear();
            }
        }
        return answer;
    }
};
