#include "BinaryTree.h"
#include "PDF.h" 

using namespace std;

void func( const int& src )
  // A test function for the function-based 
{
  cout << src << " ";
}

int complete_tree_height( int n ) 
  // Returns the height of a complete binary tree having 'n' nodes
{
  int h = 0;
  // essentially, take the base-2 logarithm of 'n'
  while (n > 0) {
    n /= 2;
    h++;
  }
  return h;
}

void user_prompt(BinaryTree<int>& tree){
    string command = "\n"
                      "Choose the operation you want to perform: \n"
                     "1. Add a new node\n"
                     "2. Remove a node\n"
                     "3. Search for a node\n"
                     "4. Print the tree\n"
                     "5. Choose the traversal method\n"
                     "6. Check if the tree is empty\n"
                     "7. Count the number of node\n"
                     "8. Exit\n";
    
    int prompt = 0;
    while (prompt != 8){
        cout << command << endl;
        cout << "Enter a command: ";
        cin >> prompt;
        if (prompt == 1){
            int num;
            cout << "Enter a number you want to add: " << endl;
            cin >> num;
            tree.add(num);
            cout << "Added " << num << " to the tree" << endl;
        }
        else if (prompt == 2)
        {
            int num;
            cout << "Enter a number you want to remove: " << endl;
            cin >> num;
            tree.remove(num);
            cout << "Removed " << num << " from the tree" << endl;
        }
        else if (prompt == 3)
        {
            int num;
            cout << "Enter a number you want to search: " << endl;
            cin >> num;
            tree.contains(num);
            if (tree.contains(num) == true){
                cout << "The tree contains " << num << endl;
            }
            else{
                cout << "The tree does not contain " << num << endl;
            }
        }
        else if (prompt == 4)
        {
          PDF *pdf = new PDF("trees.pdf");

          ostringstream ostring;
          ostring << "Complete tree having " << tree.node_count() << " nodes";
          tree.display(pdf, ostring.str());
          pdf->finish();
          delete pdf;
          cout << "Printed the tree. Check the pdf file" << endl;
        }
        else if (prompt == 5)
        {
            cout << "Choose the traversal method: " << endl;
            cout << "1. Preorder" << endl;
            cout << "2. Inorder" << endl;
            cout << "3. Postorder" << endl;
            int num;
            cout << "Enter a method you want to traverse: " << endl;
            cin >> num;
            cout << "The tree is: " << endl;
            if (num == 1){
                tree.preorder(func);
            }
            else if (num == 2){
                tree.inorder(func);
            } 
            else if (num == 3){
                tree.postorder(func);
            }
            else{
                cout << "Invalid input" << endl;
            }
            
        }
        else if (prompt == 6)
        {
            tree.is_empty();
            if (tree.is_empty() == true){
                cout << "The tree is empty" << endl;
            }
            else{
                cout << "The tree is not empty" << endl;
            }
        }
        else if (prompt == 7)
        {
            cout << "The number of nodes in the tree is: " <<
            tree.node_count();
            cout << endl;
        }
        else if (prompt == 8)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
          cout << "Invalid input" << endl;
        }
    }
}

/********/
/* Main */
/********/

int main( int argc, char *argv[] )
{
    int max_nodes = 255;
    int elements[max_nodes + 1];
    for (int k = 1; k <= max_nodes; k++)
        elements[k] = k;
    elements[0] = 0;
    
    // Create a new binary tree, having 'n' elements
    int n = 13;  // <-- try changing the value of 'n'
    for (int i = 0; i < n; i++){
      cout << elements[i] << " ";
    }

    PDF *pdf = new PDF("trees.pdf");

    BinaryTree<int> tree(elements, n);
    user_prompt(tree);

    tree.add(96);
    tree.add(964);
    
    // Draw the tree
    ostringstream ostring;
    ostring << "Complete tree having " << n << " nodes";
    tree.display(pdf, ostring.str());
    pdf->finish();
    delete pdf;
}


/* The output should look like this:
  
tree output via << operator:
8 4 9 2 10 5 11 1 12 6 3 7 
Preorder traversal:
1 2 4 8 9 5 10 11 3 6 12 7 
Inorder traversal:
8 4 9 2 10 5 11 1 12 6 3 7 
Postorder traversal:
8 9 4 10 11 5 2 12 6 7 3 1 

*/
