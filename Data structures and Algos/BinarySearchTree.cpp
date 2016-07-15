// Left child < node
// Right child > node
// Fast insertion/retrieval of sorted data
// Perfectly balanced tree -> each node has 2 node children

// Avg Search time -> log (base 2) n
// Inserting 1 node -> log (base 2) n

/*
Operations :
- Insert a new node in BST
- Search for an integer in BST
- Count nodes
*/


struct Node
{
	int val;
	Node * left, * right;
}

struct Node createNewNode(int val)
{
	Node newNode;
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

// Call insert(root, val)
void insert(struct Node * leaf, int val)
{
	if (leaf)
	{
		if (val < leaf->val)
		{	
			if (leaf->left)	// If left child exists
				insert(leaf->left, val);
			else
				leaf->left = createNewNode(val);
		}

		else
		{	if (leaf->right)	// If right child exists
				insert(leaf->right, val);
			else
				leaf->right = createNewNode(val); 
		}
	}

	else // Root node
		leaf = createNewNode(val);
	
}

struct node * search( struct node * leaf, int val)
{
	if (leaf)	// If leaf exists
	{
		if (leaf->val == val)
			return leaf;

		else if (val < leaf->val)
			return search(leaf->left, val);

		else 
			return search(leaf->right, val);
	}

	else return NULL;
}

int countNodes(struct node * root)
{
	if (root == NULL) return 0;

	int c = 0;

	c += countNodes(root->left);
	c += countNodes(root-> right);

	return c;

}