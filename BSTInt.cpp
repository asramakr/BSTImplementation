
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

  unsigned int localHeight = 0;
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  if(root->data == item) {
    return false;
  }
  
  while (curr->left || curr->right) {
    if(!(curr->left) && item < curr->data){
      break;
    }
    else if(!(curr->right) && curr->data < item){
      break;
    }
    else if (item < curr->data) {
      localHeight++;
      curr = curr->left;
    }
    else if (curr->data < item) {
      localHeight++;
      curr = curr->right;
    }
    else {
      return false;
    }

    if(item == curr->data) {
      return false;
    }

  }
  localHeight++;
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
      }
      else if(curr->right) {
        delete curr->right;
        curr->right = NULL;
      }
    }
    else{
      delete curr;
      curr = NULL;
      break;
    } 
  }
}
