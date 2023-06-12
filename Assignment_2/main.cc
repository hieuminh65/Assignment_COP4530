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


/********/
/* Main */
/********/

int main( int argc, char *argv[] )
{
    int max_nodes = 255;
    int elements[max_nodes + 1];
    for (int k = 1; k <= max_nodes; k++)
        elements[k] = k;

    // Construct a PDF object to write the tree output
    // PDF *pdf = new PDF("trees.pdf");
    
    // Create a new binary tree, having 'n' elements
    int n = 12;  // <-- try changing the value of 'n'
    for (int i = 0; i < n; i++){
      cout << elements[i] << " ";
    }

    PDF *pdf = new PDF("trees.pdf");

    BinaryTree<int> tree(elements, n);
    tree.add(5);
    // Output the tree
    cout << "tree output via << operator:\n" << tree << "\n";
    
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
