struct Node{
    map<char, Node*> children;
    int childCount;
};

Node * getNewNode(){
    Node * a = new Node;
    map<char, Node*> r;
    a->children = r;
    a->childCount = 0;
    return a;
}

void insert(Node * head, string name){
    
    Node * root = head;
    for (int i = 0; i<name.size(); i++)
    {   // if character does not exist in children. create a new node
        if (root->children.find(name[i])==root->children.end()) {
            root->children[name[i]] = getNewNode(name[i]);    
        }
        
        root = root->children[name[i]];
        root->childCount++;
    }
}

int search(Node * head, string sub){
    Node * root = head;
    for (int i = 0; i<sub.size();i++)
    {
        if (root->children.find(sub[i]) != root->children.end()) {
            root = root->children[sub[i]];
        } 
        else return 0;
    }
    return root->childCount;
}

int main(){
    int n;
    cin >> n;
 
    Node * head = getNewNode();

    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        
        if (op.compare("add") == 0) insert(head, contact);
        else cout << search(head, contact) << endl;

    }
    return 0;
}
