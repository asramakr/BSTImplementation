#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    /* Create an instance of BST holding int */
    BSTInt b;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }


    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /*Our test 1*/
    vector<int> testOfInts1;
    testOfInts1.push_back(3);
    testOfInts1.push_back(5);
    testOfInts1.push_back(1);
    testOfInts1.push_back(2);
    testOfInts1.push_back(4);

    /* Create an instance of BST holding int */
    BSTInt b2;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts1) {
        bool pr = b2.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }


    /* Test size. */
    cout << "Size is: " << b2.size() << endl;
    if(b2.size() != testOfInts1.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts1) {
        if(!b2.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Test to find return value. */
    /* Test items that are not in the tree */
    if(b2.find(6) == false) {
        cout << "Correctly found that 6 does not exist in the vector" << endl;
       // return 1;
    } 

    /*Our test 2*/
    vector<int> testOfInts2;
    testOfInts2.push_back(5);
    testOfInts2.push_back(4);
    testOfInts2.push_back(3);

    /* Create an instance of BST holding int */
    BSTInt b3;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts2) {
        bool pr = b3.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }


    /* Test size. */
    cout << "Size is: " << b3.size() << endl;
    if(b3.size() != testOfInts2.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 1 in vector */
    if (b3.find(4) == true) {
        cout << "found 4 in vector" << endl;
    }
    else {
	cout << "could not find 4 in vector" << endl;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts2) {
        if(!b3.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }


    /*Our test 3*/
    vector<int> testOfInts3;
    testOfInts3.push_back(1);
    testOfInts3.push_back(2);
    testOfInts3.push_back(3);

    /* Create an instance of BST holding int */
    BSTInt b4;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts3) {
        bool pr = b4.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }


    /* Test size. */
    cout << "Size is: " << b4.size() << endl;
    if(b4.size() != testOfInts3.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 1 in vector */
    if (b4.find(2) == true) {
        cout << "found 2 in vector" << endl;
    }
    else {
	cout << "could not find 2 in vector" << endl;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts3) {
        if(!b4.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    /*
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    */

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    cout << "All tests passed!" << endl;
    return 0;
}
