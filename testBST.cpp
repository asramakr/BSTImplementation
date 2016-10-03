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
 * Author: Christine Alvarado and Arun Ramakrishnan and Alexis Atianzar
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

    /* Test size. */
    cout << "Height is: " << b.height() << endl;
    if(b.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test empty() return value. */
    if(b.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
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

    /* Test height. */
    cout << "Height is: " << b2.height() << endl;
    if(b2.height() != 2) {
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
    if(b2.find(6)) {
        cout << "Incorrect return value when finding 6" << endl;
        return -1;
    } 

    /* Test empty() return value. */
    if(b2.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
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

    /* Test height. */
    cout << "Height is: " << b3.height() << endl;
    if(b3.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test find return value. */
    /* Test if can find 4 in vector */
    if (!b3.find(4)) {
        cout << "Incorrect return value when finding 4" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts2) {
        if(!b3.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Test empty() return value. */
    if(b3.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
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

    /* Test height. */
    cout << "Height is: " << b4.height() << endl;
    if(b4.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test find return value. */
    /* Test if can find 2 in vector */
    if (!b4.find(2)) {
        cout << "Incorrect return value when finding 2" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts3) {
        if(!b4.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Test empty() return value. */
    if(b4.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }


    /*Our test 4*/
    vector<int> testOfInts4;

    /* Create an instance of BST holding int */
    BSTInt b5;

    /* Test size. */
    cout << "Size is: " << b5.size() << endl;
    if(b5.size() != testOfInts4.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b5.height() << endl;
    if(b5.height() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test find return value. */
    // Test the items that are not in tree
    if(b5.find(1)) {
        cout << "Incorrect return value when finding 1" << endl;
        return -1;
    }
    
    /* Test empty() return value. */
    if(b5.empty() != true) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }


    /*Our test 5*/
    vector<int> testOfInts5;
    testOfInts5.push_back(5);
    testOfInts5.push_back(2);
    testOfInts5.push_back(8);
    testOfInts5.push_back(0);
    testOfInts5.push_back(10);
    testOfInts5.push_back(6);
    testOfInts5.push_back(4);

    /* Create an instance of BST holding int */
    BSTInt b6;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts5) {
        bool pr = b6.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test size. */
    cout << "Size is: " << b6.size() << endl;
    if(b6.size() != testOfInts5.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b6.height() << endl;
    if(b6.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (b6.find(3)) {
        cout << "Incorrect return value when finding 3" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts5) {
        if(!b6.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
   
    /* Test empty() return value. */
    if(b6.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }
 
    /*Our test 6*/
    vector<int> testOfInts6;
    testOfInts6.push_back(5);
    testOfInts6.push_back(2);

    /* Create an instance of BST holding int */
    BSTInt b7;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts6) {
        bool pr = b7.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test duplicate insertion */
    if(b7.insert(5) != false) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test duplicate insertion */
    if(b7.insert(2) != false) {
        cout << "Incorrect insertion of duplicate" << endl;
    }


    /* Test size. */
    cout << "Size is: " << b7.size() << endl;
    if(b7.size() != testOfInts6.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b7.height() << endl;
    if(b7.height() != 1) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (b7.find(3)) {
        cout << "Incorrect return value when finding 3" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts6) {
        if(!b7.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
   
    /* Test empty() return value. */
    if(b7.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }

    /*Our test 7*/
    vector<int> testOfInts7;
    testOfInts7.push_back(5);

    /* Create an instance of BST holding int */
    BSTInt b8;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts7) {
        bool pr = b8.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test duplicate insertion */
    if(b8.insert(5) != false) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test size. */
    cout << "Size is: " << b8.size() << endl;
    if(b8.size() != testOfInts7.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b8.height() << endl;
    if(b8.height() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (b8.find(3)) {
        cout << "Incorrect return value when finding 3" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts7) {
        if(!b8.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
   
    /* Test empty() return value. */
    if(b8.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }

    /*Our test 8*/
    vector<int> testOfInts8;
    testOfInts8.push_back(5);
    testOfInts8.push_back(4);
    testOfInts8.push_back(3);
    testOfInts8.push_back(2);
    testOfInts8.push_back(1);

    /* Create an instance of BST holding int */
    BSTInt b9;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts8) {
        bool pr = b9.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test duplicate insertion */
    if(b9.insert(5) != false) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test size. */
    cout << "Size is: " << b9.size() << endl;
    if(b9.size() != testOfInts8.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b9.height() << endl;
    if(b9.height() != 4) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (b9.find(6)) {
        cout << "Incorrect return value when finding 6" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts8) {
        if(!b9.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
   
    /* Test empty() return value. */
    if(b9.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }

    /*Our test 9*/
    vector<int> testOfInts9;
    testOfInts9.push_back(3);
    testOfInts9.push_back(6);
    testOfInts9.push_back(1);
    testOfInts9.push_back(2);
    testOfInts9.push_back(4);
    testOfInts9.push_back(8);
    testOfInts9.push_back(0);
    testOfInts9.push_back(7);

    /* Create an instance of BST holding int */
    BSTInt b10;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : testOfInts9) {
        bool pr = b10.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test duplicate insertion */
    if(b10.insert(8) != false) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test size. */
    cout << "Size is: " << b10.size() << endl;
    if(b10.size() != testOfInts9.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b10.height() << endl;
    if(b10.height() != 3) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 5, which isn't in vector */
    if (b10.find(5)) {
        cout << "Incorrect return value when finding 6" << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : testOfInts9) {
        if(!b10.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }
   
    /* Test empty() return value. */
    if(b10.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }


    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    
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

    

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    cout << "All tests passed!" << endl;
    return 0;
}
