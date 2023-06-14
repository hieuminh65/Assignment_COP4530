// #include "BinaryTree.h"
// #include "PDF.h"


using namespace std;

/*
 * Input/Output
 * ------------
 *
 * Unlike certain kinds of specific binary trees, there is no natural
 * method of inserting elements incrementally into a general binary
 * tree.  Most often they are built up from subtrees.  That makes it
 * difficult to define a constructor that constructs a binary tree
 * all at once from a collection of elements, e.g., an array.  So
 * array-based construction works assuming the tree is a complete
 * binary tree.
 *
 * Recall that a *perfect* (or full) binary tree has all the levels
 * completely filled.  A *complete* binary tree has all the levels
 * full, except that a segment of leaves at the right may be missing.
 * There is exactly one complete binary tree structure having n elements.
 * The sequence of complete binary trees looks like this:
 *
 *          1
 *      
 *
 *          1       1     
 *         /       / \   
 *        2       2   3  
 *                           
 *			     
 *          1                 1                 1                 1        
 *        /   \             /   \    	      /   \             /   \    
 *      2       3         2       3  	    2       3         2       3  
 *     /                 / \         	   / \     /   	     / \     / \ 
 *    4                 4   5        	  4   5   6    	    4   5   6   7
 *
 *
 * The nodes of a complete binary tree thus have a natural linear order;
 * in fact, a complete binary tree is suited for representation in a
 * flat array:
 *
 *            1
 *          /   \                +---+---+---+---+---+---+---+---+- -
 *        2       3        -->   | X | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
 *       / \     / \             +---+---+---+---+---+---+---+---+- -
 *      4   5   6   7              0   1   2   3   4   5   6   7   
 *
 * For computational convenience, the root element is stored at index 1
 * in the array (the cell at index 0 is unused).  In this arrangement
 * the index of the children and parents of the node at index 'i'
 * have clean formulas:
 *
 *   parent of node i:       i/2  (rounding down, as usual)
 *   left child of node i:   2*i
 *   right child of node i:  2*i + 1
 *
 * Of course, in the present implementation the tree is stored as
 * linked nodes rather than a flat array.  However, the flat array
 * interpretation is useful for input and output: a tree is constructed
 * from an array assuming it is a complete tree with elements given
 * by the array in the natural complete-tree ordering.
 *
 * NOTE:  For consistency, this code assumes that the element at index 0
 *        is unused, so if there are 'n' elements, the array has 'n + 1'
 *        cells.
 */



/****************************************************************************/
/***                    Implementation of BinaryTree			  ***/
/****************************************************************************/


/****************/
/* Construction */
/****************/

template<class T>
BinaryTree<T>::BinaryTree( T *elements, int n_elements )
  // Constructs this tree to have elements 'elements[1]', 'elements[2]' ...
  // as a complete binary tree (see above); 'element[0]' is ignored,
  // so the total number of cells if 'elements' is 'n_elements + 1'
{
  root = NULL;
  init_complete(elements, n_elements);
}

template<class T>
void BinaryTree<T>::init_complete( T *elements, int n_elements )
  // Initializes this tree, regarding it as a complete binary tree
  // having elements 'elements[1]', 'elements[2]', ... (see above)
{
  // call the helper function starting at the root index (1)
  root = init_complete(elements, n_elements, 1);
}

template<class T>
BTNode<T>* BinaryTree<T>::init_complete( T *elements, int n_elements,
					 int index )
  // Initializes this tree, regarding it as a complete binary tree,
  // starting at the array node at 'index'
{
  // check for the end of the array 
  if (index > n_elements)
    return NULL;

  // create a new node, with left and right children assigned by
  // the recursive call
  return new BTNode<T>(elements[index],
		       init_complete(elements, n_elements, 2*index),
		       init_complete(elements, n_elements, 2*index + 1));
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree& src) {
  root = clone(src.root);
}

template <class T>
BTNode<T>* BinaryTree<T>::clone(BTNode<T>* node) {
  if (node == nullptr)
    return nullptr;

  BTNode<T>* new_node = new BTNode<T>(node->elem);
  new_node->left = clone(node->left);
  new_node->right = clone(node->right);

  return new_node;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const BTNode<T>& src) {
  out << src.elem << " ";
  return out;
}

/********************/
/* Access and Tests */
/********************/
template<class T>
bool BinaryTree<T>::is_empty() const {
  return root == nullptr;
}

template <class T>
int BinaryTree<T>::height(BTNode<T>* node) const {
  if (node == nullptr) {
    return 0; 
  } else {
    return node->height;
  }
}

template<class T>
int BinaryTree<T>::node_count( BTNode<T> *node ) const
{
  if (node == NULL)
    return 0;
  return 1 + node_count(node->left) + node_count(node->right);
}

template <class T>
int BinaryTree<T>::balance_factor(BTNode<T>* node) const
{
  int left_height = (node->left != nullptr) ? node->left->height : -1;
  int right_height = (node->right != nullptr) ? node->right->height : -1;

  return right_height - left_height;
}

template <class T>
void BinaryTree<T>::update_bf(BTNode<T>* node) {
  int left_height = (node->left != nullptr) ? node->left->height : -1;
  int right_height = (node->right != nullptr) ? node->right->height : -1;

  node->height = max(left_height, right_height) + 1;

  node->bf = right_height - left_height;
}

template <class T>
int BinaryTree<T>::leaf_count(BTNode<T>* node) const
{
  if (node == nullptr)
    return 0;

  if (node->left == nullptr && node->right == nullptr)
    return 1;

  int count = 0;
  if (node->left != nullptr)
    count += leaf_count(node->left);
  if (node->right != nullptr)
    count += leaf_count(node->right);

  return count;
}

template <class T>
bool BinaryTree<T>::contains( BTNode<T>* node, const T& value ){
  if (node == NULL)
    return false;
  if (node->elem == value)
    return true;
  return contains(node->left, value) || contains(node->right, value);
}


/********************/
/* Balanced Functions */
/********************/
template <class T>
BTNode<T>* BinaryTree<T>::balanceTree(BTNode<T>* node) {
  // Check if the tree is a complete binary tree
  if (node->bf <= -2) {
    if (node->left->bf <= 0) {
      return leftLeftCase(node);
    }
    else {
      return leftRightCase(node);
    }
  } else if (node->bf >= 2) {
    if (node->right->bf >= 0) {
      return rightRightCase(node);
    }
    else {
      return rightLeftCase(node);
    }
  }
  return node;
}

template <class T>
BTNode<T>* BinaryTree<T>::leftLeftCase(BTNode<T>* node) {
  return rotateRight(node);
}

template <class T>
BTNode<T>* BinaryTree<T>::leftRightCase(BTNode<T>* node) {
  node->left = rotateLeft(node->left);
  return leftLeftCase(node);
}

template <class T>
BTNode<T>* BinaryTree<T>::rightRightCase(BTNode<T>* node) {
  return rotateLeft(node);
}

template <class T>
BTNode<T>* BinaryTree<T>::rightLeftCase(BTNode<T>* node) {
  node->right = rotateRight(node->right);
  return rightRightCase(node);
}

template <class T>
BTNode<T>* BinaryTree<T>::rotateLeft(BTNode<T>* node) {
  BTNode<T>* newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;
  update_bf(node);
  update_bf(newRoot);
  return newRoot;
}

template <class T>
BTNode<T>* BinaryTree<T>::rotateRight(BTNode<T>* node) {
  BTNode<T>* newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;
  update_bf(node);
  update_bf(newRoot);
  return newRoot;
}

/*************/
/* Traversal */
/*************/

template<class T>
void BinaryTree<T>::preorder( void (*f)(const T&), BTNode<T> *node ) const
{
  if (!node)
    return;
  f(node->elem);
  preorder(f, node->left);
  preorder(f, node->right);
}

template<class T>
void BinaryTree<T>::inorder( void (*f)(const T&), BTNode<T> *node ) const
{
  if (!node)
    return;
  inorder(f, node->left);
  f(node->elem);
  inorder(f, node->right);
}

template<class T>
void BinaryTree<T>::postorder( void (*f)(const T&), BTNode<T> *node ) const
{
  if (!node)
    return;
  postorder(f, node->left);
  postorder(f, node->right);
  f(node->elem);
}


/************************/
/* Mutator */
/************************/

template<class T>
void BinaryTree<T>::empty(BTNode<T> *node) const
{
  if (!node)
    return;
  empty(node->left);
  empty(node->right);
  delete node;
}

template<class T>
BTNode<T>* BinaryTree<T>::add(BTNode<T>* node, const T& value) {
    if (node == nullptr) {
        return new BTNode<T>(value);
    }
    if (value <= node->elem) {
        node->left = add(node->left, value);
    } else {
        node->right = add(node->right, value);
    }

    update_bf(node);

    return balanceTree(node);
    
}

template<class T>
bool BinaryTree<T>::remove(const T& value) {
  if (contains(value)) {
    root = remove(root, value);
    return true;
  }
  return false;
}

template<class T>
BTNode<T>* BinaryTree<T>::remove(BTNode<T>* node, const T& value) {
  if (node == nullptr) {
    return nullptr;
  }
  if (value < node->elem) {
    node->left = remove(node->left, value);
  } else if (value > node->elem) {
    node->right = remove(node->right, value);
  } else {
    if (node->left == nullptr) {
      BTNode<T>* rightChild = node->right;
      delete node;
      return rightChild;
    } else if (node->right == nullptr) {
      BTNode<T>* leftChild = node->left;
      delete node;
      return leftChild;
    } else {
      BTNode<T>* minNode = findMin(node->right);
      node->elem = minNode->elem;
      node->right = remove(node->right, minNode->elem);
    }
  }

  update_bf(node);

  return balanceTree(node);
}

template<class T>
BTNode<T>* BinaryTree<T>::findMin(BTNode<T>* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

/************************/
/* Conversion to Arrays */
/************************/

template<class T>
int BinaryTree<T>::to_flat_array( T *elements, int max ) const
  // PRE: This is a complete binary tree
  // Copies the elements contained in the nodes of this tree to
  // 'elements' in complete-tree order (see above).  At most
  // 'max' elements are actually copied; the return value is
  // the total number of nodes.
  // The elements are copied starting at 'elements[1]' (see above)
  // so 'elements' must have at least 'max + 1' cells available
{
  // call the helper
  int max_index = 1;
  return to_flat_array(elements, max, root, 1, max_index);
}

template<class T>
int BinaryTree<T>::to_flat_array( T *elements, int max, BTNode<T> *node,
				  int index, int& max_index ) const
  // PRE: this is a complete binary tree
  // Helper function for the 'to_flat_array' function above
  // 'node' is the current node, 'index' is the index of the node
  // in the flat array (complete tree array) representation, and
  // 'max_index' is the largest index yet encountered; it is updated
  // accordingly by this call
  
{
  // skip a NULL node
  if (node == NULL)
    return 0;

  // update the maximum index
  if (index > max_index)
    max_index = index;

  // as long as we're not past the maximum number of cells,
  // (and the node is not NULL) the code can be copied
  if (index < max)
    elements[index] = node->elem;

  // make a recursive call, even if we're already past the max
  // (in order to keep the 'max_index' updated)
  to_flat_array(elements, max, node->left, 2*index, max_index);
  to_flat_array(elements, max, node->right, 2*index + 1, max_index);

  return max_index;
}


/**************************/
/* Input/Output Operators */
/**************************/

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree<T>& src) const
{
  // Compare the root nodes using the overloaded operator==
  return (root == src.root);
}

template<class T>
bool BinaryTree<T>::operator!=(const BinaryTree<T>& src) const
{
  // Negate the result of the operator==
  return !(*this == src);
}

template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& src)
{
  if (this == &src)
    return *this;

  // Empty the current tree
  empty_this();

  // Clone the root node of the source tree
  root = clone(src.root);

  return *this;
}

template<class T>
ostream& operator<<( ostream& out, const BinaryTree<T>& src )
  // Writes the elements contained in the nodes of this tree,
  // by way of an inorder traversal
{
  // make a call to the recursive helper function
  out << src.root;
  return out;
}

template<class T>
ostream& operator<<( ostream& out, const BTNode<T>* node )
  // Helper for the 'operator<<' above
{
  // don't write a NULL node
  if (!node)
    return out;
  
  // write, using an inorder traversal  
  out << node->left;  // (recursive)
  out << node->elem;  // (nonrecursive)
  out << " ";
  out << node->right; // (recursive)

  return out;
}

/***********/
/* Display */
/***********/

static const double font_scale = 20;
static const double level_sep = 90;
static const double node_sep = 30;
static const double node_box_margin = 6;
static const double node_box_r = 6;

template<class T>
void BinaryTree<T>::display( PDF *pdf, const string& annotation ) const
{
  double scale = 1;

  // the overall scale is based on the height of the tree
  int h = height();
  if (h >= 4) 
    scale = 16.0/double(1<<h);

  // start a new page
  pdf->new_page(annotation.c_str());
  
  // regardless of the scale, place the root node at the center
  // of the page, one inch below the top margin
  double x = pdf->get_width()/2;
  double y = pdf->get_height() - 72;

  // set the font to Helvetica, 12 point (times the scale)
  pdf->selectfont(Helvetica, font_scale*scale);
  // set the non-stroke color to light gray
  pdf->setcolor_nonstroke(PDFColor(0.75));
  pdf->setlinewidth(scale);

  // run the "helper"
  display(pdf, root, h - 1, x, y, scale);
}

template<class T>
void BinaryTree<T>::display( PDF *pdf, BTNode<T> *node, int leaf_dist,
			     double x, double y, double scale ) const
{
  // don't draw a NULL node
  if (node == NULL)
    return;

  // if there is a left node, add a line to it and make a recursive call
  if (node->left) {
    double x_left = x - (1<<leaf_dist)*node_sep*scale/2;
    double y_left = y - level_sep*scale;
    pdf->moveto(x, y);
    pdf->lineto(x_left, y_left);
    pdf->stroke();
    display(pdf, node->left, leaf_dist - 1, x_left, y_left, scale);
  }

  // if there is a right node, add a line to it and make a recursive call
  if (node->right) {
    double x_right = x + (1<<leaf_dist)*node_sep*scale/2;
    double y_right = y - level_sep*scale;
    pdf->moveto(x, y);
    pdf->lineto(x_right, y_right);
    pdf->stroke();    
    display(pdf, node->right, leaf_dist - 1, x_right, y_right, scale);
  }

  // Now draw 'node' at (x, y)
  // This is done last so that the box covers the line
  // A text representation is obtained by converting the element to a
  // C-style stringusing an 'ostringstream' instance
  ostringstream str;
  str << node->elem;
  pdf->text_box(str.str().c_str(), x, y,
		scale*node_box_margin, scale*node_box_r,
		0, scale*font_scale);  
}
