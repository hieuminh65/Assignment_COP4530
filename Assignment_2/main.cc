#include "BinaryTree.h"
#include "PDF.h" 

using namespace std;

void func( const int& src )
  // A test function for the function-based 
{
  cout << src << " ";
}

void user_prompt(BinaryTree<int>& tree){
    string command = "\n"
                     "----------------------------------------\n"
                     "Choose the operation you want to perform: \n"
                     "1. Add a number of nodes\n"
                     "2. Add a new node\n"
                     "3. Remove a node\n"
                     "4. Search for a node\n"
                     "5. Print the tree\n"
                     "6. Choose the traversal method\n"
                     "7. Check if the tree is empty\n"
                     "8. Count the number of node\n"
                     "9. Count the number of leaves\n"
                     "10. Get the height of the tree\n"
                     "11. Exit\n";
    
    int prompt = 0;
    while (prompt != 11){
        cout << command << endl;
        cout << "Enter a command: ";
        cin >> prompt;
        if (prompt == 1)
        {
            int num_nodes;
            cout << "Enter the number of nodes you want to add: ";
            cin >> num_nodes;
            for (int i = 0; i < num_nodes; i++){
                int num;
                cout << "Enter a number you want to add: ";
                cin >> num;
                tree.add(num);
                cout << "Added " << num << " to the tree" << endl;
            }
        }
        
        else if (prompt == 2){
            int num;
            cout << "Enter a number you want to add: " ;
            cin >> num;
            tree.add(num);
            cout << "Added " << num << " to the tree" << endl;
        }
        else if (prompt == 3)
        {
            int num;
            cout << "Enter a number you want to remove: ";
            cin >> num;
            tree.remove(num);
            if (tree.remove(num) == false){
                cout << "The tree does not contain " << num << endl;
            }
            else{
                cout << "Removed " << num << " from the tree" << endl;
            }
        }
        else if (prompt == 4)
        {
            int num;
            cout << "Enter a number you want to search: ";
            cin >> num;
            tree.contains(num);
            if (tree.contains(num) == true){
                cout << "The tree contains " << num << endl;
            }
            else{
                cout << "The tree does not contain " << num << endl;
            }
        }
        else if (prompt == 5)
        {
          PDF *pdf = new PDF("trees.pdf");

          ostringstream ostring;
          ostring << "Complete tree having " << tree.node_count() << " nodes";
          tree.display(pdf, ostring.str());
          pdf->finish();
          delete pdf;
          cout << "Printed the tree. Check the pdf file" << endl;
        }
        else if (prompt == 6)
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
        else if (prompt == 7)
        {
            tree.is_empty();
            if (tree.is_empty() == true){
                cout << "The tree is empty" << endl;
            }
            else{
                cout << "The tree is not empty" << endl;
            }
        }
        else if (prompt == 8)
        {
            cout << "The number of nodes in the tree is: " <<
            tree.node_count();
            cout << endl;
        }
        else if (prompt == 9)
        {   
            cout << "The number of leaves in the tree is: ";
            cout << tree.leaf_count() << endl;
        }
        else if (prompt == 10)
        {   
            cout << "The height of the tree is: ";
            cout << tree.height() << endl;
        }
        else if (prompt == 11)
        {
            cout << "Exiting..." << endl;
        }
        else if (!(cin >> prompt)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
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
    // for (int k = 1; k <= max_nodes; k++)
    //     elements[k] = k;
    elements[0] = 0;

    // Create a new binary tree, having 'n' elements
    int n = 0;  // <-- try changing the value of 'n'
    

    PDF *pdf = new PDF("trees.pdf");

    BinaryTree<int> tree(elements, n);
    user_prompt(tree);
}

