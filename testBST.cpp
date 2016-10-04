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

    /* Test size for iterator. */
    cout << "Size is: " << btemp.size() << endl;
    if(btemp.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height for iterator. */
    cout << "Height is: " << btemp.height() << endl;
    if(btemp.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test empty() return value. */
    if(btemp.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 2 */
    BST<int> btemp2;
    for (int item : testOfInts1) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp2.insert(item);
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
    for (int item: testOfInts1) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp2.find(item);
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
    sort(testOfInts1.begin(),testOfInts1.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts1Start = testOfInts1.begin();
    auto testOfInts1End = testOfInts1.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp2End = btemp2.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp2Start = btemp2.begin();

    for(; testOfInts1Start != testOfInts1End; ++testOfInts1Start) {
        if(! (btemp2Start != btemp2End) ) {
            cout << *btemp2Start << "," << *testOfInts1Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp2Start << endl;
        if(*btemp2Start != *testOfInts1Start) {
            cout << *btemp2Start << "," << *testOfInts1Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp2Start;
    }

    /* Test size. */
    cout << "Size is: " << btemp2.size() << endl;
    if(btemp2.size() != testOfInts1.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp2.height() << endl;
    if(btemp2.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test to find return value. */
    /* Test items that are not in the tree */
    if(btemp2.find(6) != nullptr) {
        cout << "Incorrect return value when finding 6" << endl;
        return -1;
    } 

    /* Test empty() return value. */
    if(btemp2.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 3 */
    BST<int> btemp3;
    for (int item : testOfInts2) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp3.insert(item);
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
    for (int item: testOfInts2) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp3.find(item);
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
    sort(testOfInts2.begin(),testOfInts2.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts2Start = testOfInts2.begin();
    auto testOfInts2End = testOfInts2.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp3End = btemp3.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp3Start = btemp3.begin();

    for(; testOfInts2Start != testOfInts2End; ++testOfInts2Start) {
        if(! (btemp3Start != btemp3End) ) {
            cout << *btemp3Start << "," << *testOfInts2Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp3Start << endl;
        if(*btemp3Start != *testOfInts2Start) {
            cout << *btemp3Start << "," << *testOfInts2Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp3Start;
    } 


    /* Test size. */
    cout << "Size is: " << btemp3.size() << endl;
    if(btemp3.size() != testOfInts2.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp3.height() << endl;
    if(btemp3.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test find return value. */
    /* Test if can find 4 in vector */
    if (! (btemp3.find(4) != nullptr)) {
        cout << "Incorrect return value when finding 4" << endl;
        return -1;
    }

    /* Test empty() return value. */
    if(btemp3.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 4 */
    BST<int> btemp4;
    for (int item : testOfInts3) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp4.insert(item);
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
    for (int item: testOfInts3) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp4.find(item);
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
    sort(testOfInts3.begin(),testOfInts3.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts3Start = testOfInts3.begin();
    auto testOfInts3End = testOfInts3.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp4End = btemp4.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp4Start = btemp4.begin();

    for(; testOfInts3Start != testOfInts3End; ++testOfInts3Start) {
        if(! (btemp4Start != btemp4End) ) {
            cout << *btemp4Start << "," << *testOfInts3Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp4Start << endl;
        if(*btemp4Start != *testOfInts3Start) {
            cout << *btemp4Start << "," << *testOfInts3Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp4Start;
    } 


    /* Test size. */
    cout << "Size is: " << btemp4.size() << endl;
    if(btemp4.size() != testOfInts3.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp4.height() << endl;
    if(btemp4.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test find return value. */
    /* Test if can find 2 in vector */
    if (! (btemp4.find(2) != nullptr)) {
        cout << "Incorrect return value when finding 2" << endl;
        return -1;
    }


    /* Test empty() return value. */
    if(btemp4.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 5 */
    BST<int> btemp5;
    for (int item : testOfInts4) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp5.insert(item);
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
    for (int item: testOfInts4) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp5.find(item);
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
    sort(testOfInts4.begin(),testOfInts4.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts4Start = testOfInts4.begin();
    auto testOfInts4End = testOfInts4.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp5End = btemp5.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp5Start = btemp5.begin();

    for(; testOfInts4Start != testOfInts4End; ++testOfInts4Start) {
        if(! (btemp5Start != btemp5End) ) {
            cout << *btemp5Start << "," << *testOfInts4Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp5Start << endl;
        if(*btemp5Start != *testOfInts4Start) {
            cout << *btemp5Start << "," << *testOfInts4Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp5Start;
    } 

    /* Test size. */
    cout << "Size is: " << btemp5.size() << endl;
    if(btemp5.size() != testOfInts4.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp5.height() << endl;
    if(btemp5.height() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }


    /* Test find return value. */
    // Test the items that are not in tree
    if((btemp5.find(1) != nullptr)) {
        cout << "Incorrect return value when finding 1" << endl;
        return -1;
    }
    
    /* Test empty() return value. */
    if(btemp5.empty() != true) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 6 */
    BST<int> btemp6;
    for (int item : testOfInts5) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp6.insert(item);
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
    for (int item: testOfInts5) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp6.find(item);
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
    sort(testOfInts5.begin(),testOfInts5.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts5Start = testOfInts5.begin();
    auto testOfInts5End = testOfInts5.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp6End = btemp6.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp6Start = btemp6.begin();

    for(; testOfInts5Start != testOfInts5End; ++testOfInts5Start) {
        if(! (btemp6Start != btemp6End) ) {
            cout << *btemp6Start << "," << *testOfInts5Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp6Start << endl;
        if(*btemp6Start != *testOfInts5Start) {
            cout << *btemp6Start << "," << *testOfInts5Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp6Start;
    } 


    /* Test size. */
    cout << "Size is: " << btemp6.size() << endl;
    if(btemp6.size() != testOfInts5.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp6.height() << endl;
    if(btemp6.height() != 2) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if ((btemp6.find(3) != nullptr)) {
        cout << "Incorrect return value when finding 3" << endl;
        return -1;
    }

   
    /* Test empty() return value. */
    if(btemp6.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 7 */
    BST<int> btemp7;
    for (int item : testOfInts6) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp7.insert(item);
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
    for (int item: testOfInts6) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp7.find(item);
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
    sort(testOfInts6.begin(),testOfInts6.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts6Start = testOfInts6.begin();
    auto testOfInts6End = testOfInts6.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp7End = btemp7.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp7Start = btemp7.begin();

    for(; testOfInts6Start != testOfInts6End; ++testOfInts6Start) {
        if(! (btemp7Start != btemp7End) ) {
            cout << *btemp7Start << "," << *testOfInts6Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp7Start << endl;
        if(*btemp7Start != *testOfInts6Start) {
            cout << *btemp7Start << "," << *testOfInts6Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp7Start;
    } 

    /* Test duplicate insertion */
    if(((btemp7.insert(5).first) != (nullptr)) && (btemp7.insert(5).second != 
            false)) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test duplicate insertion */
    if((btemp7.insert(2).first != (nullptr)) && (btemp7.insert(2).second != 
            false)) {
        cout << "Incorrect insertion of duplicate" << endl;
    }


    /* Test size. */
    cout << "Size is: " << btemp7.size() << endl;
    if(btemp7.size() != testOfInts6.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp7.height() << endl;
    if(btemp7.height() != 1) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (btemp7.find(3) != nullptr) {
        cout << "Incorrect return value when finding 3" << endl;
        return -1;
    }

   
    /* Test empty() return value. */
    if(btemp7.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 8 */
    BST<int> btemp8;
    for (int item : testOfInts7) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp8.insert(item);
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
    for (int item: testOfInts7) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp8.find(item);
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
    sort(testOfInts7.begin(),testOfInts7.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts7Start = testOfInts7.begin();
    auto testOfInts7End = testOfInts7.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp8End = btemp8.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp8Start = btemp8.begin();

    for(; testOfInts7Start != testOfInts7End; ++testOfInts7Start) {
        if(! (btemp8Start != btemp8End) ) {
            cout << *btemp8Start << "," << *testOfInts7Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp8Start << endl;
        if(*btemp8Start != *testOfInts7Start) {
            cout << *btemp8Start << "," << *testOfInts7Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp8Start;
    } 

   /* Test duplicate insertion */
    if((btemp8.insert(5).first != nullptr) && (btemp8.insert(5).second !=
            false)) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test size. */
    cout << "Size is: " << btemp8.size() << endl;
    if(btemp8.size() != testOfInts7.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp8.height() << endl;
    if(btemp8.height() != 0) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (btemp8.find(3) != nullptr) {
        cout << "Incorrect return value when finding 3" << endl;
        return -1;
    }

   
    /* Test empty() return value. */
    if(btemp8.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 9 */
    BST<int> btemp9;
    for (int item : testOfInts8) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp9.insert(item);
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
    for (int item: testOfInts8) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp9.find(item);
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
    sort(testOfInts8.begin(),testOfInts8.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts8Start = testOfInts8.begin();
    auto testOfInts8End = testOfInts8.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp9End = btemp9.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp9Start = btemp9.begin();

    for(; testOfInts8Start != testOfInts8End; ++testOfInts8Start) {
        if(! (btemp9Start != btemp9End) ) {
            cout << *btemp9Start << "," << *testOfInts8Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp9Start <<  endl;
        if(*btemp9Start != *testOfInts8Start) {
            cout << *btemp9Start << "," << *testOfInts8Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp9Start;
    } 

    /* Test duplicate insertion */
    if((btemp9.insert(5).first != nullptr) && (btemp9.insert(5).second != 
            false)) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test size. */
    cout << "Size is: " << btemp9.size() << endl;
    if(btemp9.size() != testOfInts8.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp9.height() << endl;
    if(btemp9.height() != 4) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 3, which isn't in vector */
    if (btemp9.find(6) != nullptr) {
        cout << "Incorrect return value when finding 6" << endl;
        return -1;
    }

   
    /* Test empty() return value. */
    if(btemp9.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }



    /** Test Iterator 10 */
    BST<int> btemp10;
    for (int item : testOfInts9) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp10.insert(item);
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
    for (int item: testOfInts9) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp10.find(item);
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
    sort(testOfInts9.begin(),testOfInts9.end());

    cout << "traversal using iterator..." << endl;
    auto testOfInts9Start = testOfInts9.begin();
    auto testOfInts9End = testOfInts9.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto btemp10End = btemp10.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto btemp10Start = btemp10.begin();

    for(; testOfInts9Start != testOfInts9End; ++testOfInts9Start) {
        if(! (btemp10Start != btemp10End) ) {
            cout << *btemp10Start << "," << *testOfInts9Start 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *btemp10Start <<  endl;
        if(*btemp10Start != *testOfInts9Start) {
            cout << *btemp10Start << "," << *testOfInts9Start 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++btemp10Start;
    } 

    /* Test duplicate insertion */
    if((btemp10.insert(8).first != nullptr) && (btemp10.insert(8).second != 
            false)) {
        cout << "Incorrect insertion of duplicate" << endl;
    }

    /* Test size. */
    cout << "Size is: " << btemp10.size() << endl;
    if(btemp10.size() != testOfInts9.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << btemp10.height() << endl;
    if(btemp10.height() != 3) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    /* Test if can find 5, which isn't in vector */
    if (btemp10.find(5) != nullptr) {
        cout << "Incorrect return value when finding 6" << endl;
        return -1;
    }

   
    /* Test empty() return value. */
    if(btemp10.empty() != false) {
        cout << "Incorrect return value when checking if empty" << endl;
        return -1;
    }


    cout << "success!" << endl;

    cout << "All tests passed!" << endl;
    return 0;
}
