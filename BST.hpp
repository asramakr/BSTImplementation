#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
      This is inlined because it is trivial.
   */
  BST() : root(nullptr), isize(0), heightVar(0) {}


  /** Default destructor.
      Delete every node in this BST.
  */
  ~BST();

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return a pair where the first element is an iterator 
   *  pointing to either the newly inserted element or the element 
   *  that was already in the BST, and the second element is true if the 
   *  element was newly inserted or false if it was already in the BST.
   * 
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** Return the height of the BST.
      height of a tree starts with root at height 0
   */ 
  unsigned int height() const;


  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const;

  /** Return an iterator pointing to the first (smallest) item in the BST.
   */ 
  iterator begin() const;

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;
  
  /** Number of maximum height of BST */
  unsigned int heightVar;

  /** Find the first element of the BST
   * Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);
 };


// ********** Function definitions ****************


/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BST<Data>::~BST() {
  deleteAll(root);
}


/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return a pair where the first element is an iterator pointing to either the newly inserted
 *  element or the element that was already in the BST, and the second element is true if the 
 *  element was newly inserted or false if it was already in the BST.
 * 
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  
 */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {
  // TODO
  // HINT: Copy code from your BSTInt class and change the return value
  // REPLACE THE LINE BELOW
//  return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(0), false);
 
 unsigned int localHeight = 0;
  
  //if there are no nodes in the tree, the first node entered becomes the root
  if (!root) {
    root = new BSTNode<Data>(item);
    ++isize; //size increases by one every time a node is added to the BST
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(root), true);
  }

  BSTNode<Data>* curr = root;

  if(root->data == item) {
    //checks if the data is already found in the tree
    BSTNode<Data>* newNode = new BSTNode<Data>(item);
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(newNode), 
        false);
  }
  
  // loops until it finds the correct spot for the node
  while (curr->left || curr->right) { 

    // insert as left child of current node if none exists
    if(!(curr->left) && item < curr->data){
      break;
    }

    // insert as right child of current node if none exists
    else if(!(curr->right) && curr->data < item){
      break;
    }

    // move down to left child of current node
    else if (item < curr->data) {
      localHeight++; // keep track of height of existing nodes when inserting
      curr = curr->left;
    }

    // move down to right child of current node
    else if (curr->data < item) {
      localHeight++;
      curr = curr->right;
    }

    else {
      return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(0), false);
    }

    if(item == curr->data) {
      return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(0), false); 
      //if the data is the same as another node, the insertion stops
    }

  }
  localHeight++; 
  //local height increases when it is placed under a node with no children
 
  // Ready to insert
  BSTNode<Data>* newNode = new BSTNode<Data>(item);

  // insert the node as left or right child
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
  }

  // if new height exceeds original height, update BST height
  if (heightVar < localHeight) {
   heightVar = localHeight;
  }
  ++isize;
  return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(newNode), true);
 
}


/** Find a Data item in the BST.
 *  Return an iterator pointing to the item, or pointing past
 *  the last node in the BST if not found.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
  // TODO
  // HINT: Copy code from your BSTInt class and change the return value
  
  BSTNode<Data>* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return BSTIterator<Data>(curr);
    }
  }
  return BSTIterator<Data>(nullptr);
}

  
/** Return the number of items currently in the BST.
 */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/** Return the height of the BST.
 */
template <typename Data> 
unsigned int BST<Data>::height() const
{
  // TODO
  // HINT: Copy code from your BSTInt class
  return heightVar;
  
}


/** Return true if the BST is empty, else false.
 */ 
template <typename Data>
bool BST<Data>::empty() const
{
  // TODO
  // HINT: Copy code form your BSTInt class
  
  // if the size is 0, the BST is empty
  if(isize == 0) {
    return true;
  }
  else {
    return false;
  }
}

/** Return an iterator pointing to the first (smallest) item in the BST.
 */ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/** Return an iterator pointing past the last item in the BST.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/** Find the first element of the BST
 * Helper function for the begin method above.
 */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  BSTNode<Data>* curr = root;
  if (!curr) {
    return nullptr;
  }
  else if (curr->left) {
    while (curr->left) {
      curr = curr->left;
    }
    return curr;
  }
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
  // TODO
  // HINT: Copy code from your BSTInt class.
  
  // set working node for traversal
  BSTNode<Data>* curr = n;

  // loop while nodes still exist
  while(curr){

    // loop through left child if it exists
    if(curr->left){
      curr = curr->left;
    }

    // loop through right child if it exists
    else if(curr->right){
      curr = curr->right;
    }

    // found leaf, traverse back up BST through the parent
    else if(curr->parent){

      curr = curr->parent;

      // delete leaf
      if(curr->left) {
        delete curr->left;
        curr->left = NULL;
      }
      else if(curr->right) {
        delete curr->right;
        curr->right = NULL;
      }
    }

    // delete last node
    else{
      delete curr;
      curr = NULL;
      break;
    } 
  }
}



#endif //BST_HPP
