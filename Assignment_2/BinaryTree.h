#ifndef __BinaryTree_H
#define __BinaryTree_H

#include <iostream>
#include <sstream>


#include "PDF.h" 

using namespace std;

/* A lightweight structure implementing a general binary tree node */
template <class T>
struct BTNode {
  T       elem;  // element contained in the node
  BTNode *left;  // pointer to the left child (can be NULL)
  BTNode *right; // pointer to the right child (can be NULL)
  int height;
  int bf;

  // Constructors
  BTNode() { left = right = NULL; }
  BTNode( T elem, BTNode* left = NULL, BTNode* right = NULL, int height = 1 ) {
    this->elem = elem;
    this->left = left;
    this->right = right;
    this->height = height;
    this->bf = 0;
  }
  BTNode( const BTNode& src ) {
    this->elem = src.elem;
    this->left = src.left;
    this->right = src.right;
    this->height = src.height;
    this->bf = src.bf;
  }
  
  // Simple tests
  bool is_leaf() const { return (left == NULL && right == NULL); }
};


/**************************************************************************** 
 * 
 * CLASS:  BinaryTree
 * 
 ****************************************************************************/

/* A 'BinaryTree' class implements a basic binary tree.  It serves
 * as a superclass for more specific types of binary trees, such as
 * a binary search tree.
 */

template <class T>
class BinaryTree {
 public:

  /* Construction */
  BinaryTree() { root = NULL; }
  BinaryTree( T *elements, int n_elements );
  BinaryTree( const BinaryTree& src );
  ~BinaryTree() { empty_this(); }

  /* Access and Tests */
  bool is_empty() const;
  int height() const         { return height(root); }
  int node_count() const     { return node_count(root); }
  int leaf_count() const     { return leaf_count(root); }
  BTNode<T>* getRoot() const { return root; }

  /* Mutators, and other Initialization */
  bool empty_this() { empty(root); root = NULL; return true; }
  void init_complete( T *elements, int n_elements );
  int to_flat_array( T* elements, int max ) const;
  void add( const T& value ) { root = add(root, value); }
  void remove(const T& value);

  /* Balanced functions */
  BTNode<T>* balanceTree(BTNode<T>* node);

  /* Traversal */
  void preorder( void (*f)(const T&) )  const { return preorder(f, root); }
  void inorder( void (*f)(const T&) )   const { return inorder(f, root); }
  void postorder( void (*f)(const T&) ) const { return postorder(f, root); }
               
  /* Operators */
  bool operator==( const BinaryTree& src ) const;
  bool operator!=( const BinaryTree& src ) const;
  BinaryTree& operator=( const BinaryTree& src );

  /* Input/Output */
  template<class S>
  friend ostream& operator<<( ostream& out, const BinaryTree<S>& src );

  /* Display */
  void display( PDF* pdf, const string& annotation = "" ) const;


 protected:
  BTNode<T> *root;  // Root node (NULL if the tree is empty)

  /* "Helper" functions for the basic operations */
  BTNode<T> *clone( BTNode<T> *node );
  
  int height( BTNode<T>* node ) const;
  int balance_factor( BTNode<T>* node ) const;
  int node_count( BTNode<T>* node ) const;
  int leaf_count( BTNode<T>* node ) const;
  void update_bf(BTNode<T>* node);

  BTNode<T>* leftLeftCase(BTNode<T>* node);
  BTNode<T>* leftRightCase(BTNode<T>* node);
  BTNode<T>* rightRightCase(BTNode<T>* node);
  BTNode<T>* rightLeftCase(BTNode<T>* node);

  BTNode<T>* rotateLeft(BTNode<T>* node);
  BTNode<T>* rotateRight(BTNode<T>* node);

  void preorder( void (*f)(const T&), BTNode<T> *node ) const;
  void inorder( void (*f)(const T&), BTNode<T> *node ) const;
  void postorder( void (*f)(const T&), BTNode<T> *node ) const;

  BTNode<T>* add(BTNode<T>* node, const T& value);

  void empty( BTNode<T>* node ) const; 

  BTNode<T>* init_complete( T *elements, int n_elements, int index );
  
  int to_flat_array( T *elements, int max, BTNode<T> *node, int index,
                     int& max_index ) const;
  void display( PDF *pdf, BTNode<T>* node, int leaf_dist,
		double x, double y, double scale ) const;

  template<class S>
  friend ostream& operator<<( ostream& out, const BTNode<S>& src );

}; 

#include "BinaryTree.cpp"

#endif
