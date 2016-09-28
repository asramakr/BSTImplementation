
#include "BSTInt.h"
#include <iostream>
using namespace std;

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
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  
  while (curr->left || curr->right) {
    if(!(curr->left) && item < curr->data){
      break;
    }
    else if(!(curr->right) && item > curr->data){
      break;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else if (curr->data < item) {
      curr = curr->right;
    }
    else {
      return false;
    }
  }

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else {
    curr->right = newNode;
    newNode->parent = curr;
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
  // TODO
  return 0;
}


/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  // TODO
  return false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  BSTNodeInt* curr = n;
  while(curr){
    if(curr->left){
      curr = curr->left;
    }

    else if(curr->right){
      curr = curr->right;
    }
    else if(curr->parent){
      curr = curr->parent;
      if(curr->left) {
        delete curr->left;
        curr->left = NULL;
        cout << "deleting left" << endl;
      }
      else if(curr->right) {
        delete curr->right;
        curr->right = NULL;
        cout << "deleting" << endl;
      }
    }
    else{
      delete curr;
      curr = NULL;
      break;
    } 
  }
}
