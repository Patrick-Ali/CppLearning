class BST
{
    private:
        struct node
        {
            int key;
            node *left;
            node *right;
        };
        
        node *root;
        
        void addLeafPrivate(int key, node *parent);
        void printInOrderPrivate(node *current);
        node* returnNodePrivate(int key, node *data);
        int findSmallestPrivate(node *small);
        void removeNodePrivate(int key, node *parent);
        void removeRootMatch();
        void removeNodeMatch(node *parent, node *match, bool left);
    
    public:
    
        BST();
        node* createLeaf(int key);
        void addLeaf(int key);
        void printInOrder();
        node* returnNode(int key);
        int returnRoot();
        void printChildren(int key);
        int findSmallest();
        void removeNode(int key);
};