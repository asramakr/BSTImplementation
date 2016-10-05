/**
 * Filename: BST.hpp
 * Author(s): Alexis Atianzar & Arun Ramakrishnan
 * Date: 10/5/2016
 * Description: Contains the implementations for the BST class, which is
 * a version of a Binary Search Tree. This particular BST does not allow
 * the same data points to be present within the tree, and has multiple
 * functions, such as: insert, a destructor, find, size, height, empty, and
 * deleteAll.
 */

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
 
  unsigned int localHeight = 0;
  
  //if there are no nodes in the tree, the first node entered becomes the root
  if (!root) {
    root = new BSTNode<Data>(item);
    ++isize; //size increases by one every time a node is added to the BST
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(root), true);
  }

  BSTNode<Data>* curr = root;

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
      // if item same as current node, return false
      return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(nullptr), 
          false);
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
  else if(curr->data < item){
    curr->right = newNode;
    newNode->parent = curr;
  }
  else {
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(nullptr), 
        false);
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
  
  // create a working node to search through the tree
  BSTNode<Data>* curr = root;

  // loop through nodes until null nodes
  while (curr) {

    // search under right child
    if (curr->data < item) {
      curr = curr->right;
    }

    // search under left child
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {

      // found item in tree
      return BSTIterator<Data>(curr);
    }
  }

  // return not found
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
  return heightVar;
  
}


/** Return true if the BST is empty, else false.
 */ 
template <typename Data>
bool BST<Data>::empty() const
{
  
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
  if (!root) {
    return NULL;
  }
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

  // create working node to search through tree
  BSTNode<Data>* curr = root;

  // if no node in tree at all, return null
  if (!curr) {
    return nullptr;
  } 

  // smallest (first) item in tree would be on the left
  if (curr->left) {

    // keep looping through the left child for smallest item
    while (curr->left) {
      curr = curr->left;
    }
    return curr;
  }
  else {
    return curr;
  }
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
  
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
