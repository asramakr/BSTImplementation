/**
 * Filename: BSTInt.cpp
 * Author(s): Alexis Atianzar & Arun Ramakrishnan
 * Date: 9/29/2016
 * Description: Contains the implementations for the BSTInt class, which is
 * a version of a Binary Search Tree. This particular BST does not allow
 * the same data points to be present within the tree, and has multiple
 * functions, such as: insert, a destructor, find, size, height, empty, and
 * deleteAll.
 */

#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  //Local Height is a var to keep track of new nodes to see if they change
  //the height BST
  unsigned int localHeight = 0;
  
  //if there are no nodes in the tree, the first node entered becomes the root
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize; //size increases by one every time a node is added to the BST
    return true;
  }

  BSTNodeInt* curr = root;

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
      return false;
    }
  }
  localHeight++; 
  //local height increases when it is placed under a node with no children
 
  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);

  // insert the node as left or right child
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else if (curr->data < item) {
    curr->right = newNode;
    newNode->parent = curr;
  }
  else{
    return false;
  }

  // if new height exceeds original height, update BST height
  if (heightVar < localHeight) {
   heightVar = localHeight;
  }
  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
unsigned int BSTInt::height() const
{
  return heightVar;
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{

  // if the size is 0, the BST is empty
  if(isize == 0) {
    return true;
  }
  else {
    return false;
  }
}


/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{ 
  
  // set working node for traversal
  BSTNodeInt* curr = n;

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
