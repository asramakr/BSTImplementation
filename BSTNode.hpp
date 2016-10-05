/**
 * Filename: BSTNode.hpp
 * Author(s): Alexis Atianzar & Arun Ramakrishnan
 * Date: 10/5/2016
 * Description: Contains the implementations for the BSTNode class, which is
 * used for the inserted nodes of a Binary Search Tree. This has multiple
 * functions, such as: successor.
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>

/** Starter code for PA1, CSE 100 2016
 * Authors: Christine Alvarado, based on code by Paul Kube 
 * Authors: Alexis Atianzar & Arun Ramakrishnan
 */

template<typename Data>
class BSTNode {

public:

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d);


  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor(); 

}; 


// Function definitions
// For a templated class it's easiest to just put them in the same file as the class declaration

template <typename Data>
BSTNode<Data>::BSTNode(const Data & d) : left(0), right(0), parent(0), data(d) {}

/* Return a pointer to the BSTNode that contains the item that is sequentially next 
 * in the tree */
template <typename Data>
BSTNode<Data>* BSTNode<Data>::successor()
{

  // successor would be right child
  if (right) {
    BSTNode<Data>* localLeft = right;

    // check if right child has smaller left children
    while(localLeft->left){
      localLeft = localLeft->left;
    }
    return localLeft;
  }

  // if parent is > curr
  else if (parent != NULL) {

    // if parent is instantly successor, return parent
    if (this->data < (parent)->data){
      return parent;
    }

    // if parent is < curr
    else if ((parent)->data < this->data) {
      BSTNode<Data>* localParent = parent;

      // go up the tree through parents to find successor
      while (localParent) {
        if ((localParent)->data < this->data) {
          localParent =  (localParent)->parent;
        }

        else if((localParent)->data > this->data){
          return localParent;
        }
      }
    }
  }
  return 0;
}

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
