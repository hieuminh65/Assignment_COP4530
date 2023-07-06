//the following is pseudocode for the problem 
createNode(value){
    node = new node;
    node->value = value;
    node->child = nullptr;
    node->sibling = nullptr;
    return node;
}

insert(root,value){
    newNode = createNode(value);
    root = union(root,Newnode);
}

union(root1, root2){
    if (root1->alue > root2->value)
        swap(root1, root2)
    root2->sibling = root1->child;
    root1->child = root2;
    root1->degree += 1;
    return root1;
}

