//
// Created by johnc on 4/5/2023.
//

#include "main.h"
#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <assert.h>
using namespace  std;


// This two phase commit will take a vector of int data that is greater than zero
// This all the data will be prepared until all the data is been processed.
// If there is atleast one integer in the vector that is less than 0 then it will
// do a rollback and undo all the add Else if all the integer are positive numbers then
// commit
void TwoPhaseCommitAdd(vector<int>& data,LinkedList*l,int n) {
    int i = 0;
    if (n == 0) return;
    while (i < n) {
        if (data[i] < 0) {
            l->RollBack();
            return;
        }else {
            l->Add(data[i]);
        }
        i++;
    }
    l->Commit();
    return;
}
// Take a bunch of delete operation and will commit if all the integer are found in the linkedlist
// otherwise it will revert all the previous operation.
void TwoPhaseCommitDelete(vector<int>& data,LinkedList*l,int n) {
    int i = 0;
    if (n == 0) return;
    while (i < n) {
        if (l->Delete(data[i]) == false) {
            l->RollBack();
            return;
        }
        i++;
    }
    l->Commit();
    return;
}
int main () {
    LinkedList* m = new LinkedList(0);
    int n;
    /// Test to do a bunch of add
    vector<int> batch1;
    batch1.push_back(1);
    batch1.push_back(2);
    batch1.push_back(3);
    batch1.push_back(4);

    n = batch1.size();
    TwoPhaseCommitAdd(batch1,m,n);

    cout << "Batch 1 result - Add without error" << endl;
    m->Print();
    cout << endl;

    /// Bunch of Add with error
    vector<int> batch2;
    batch2.push_back(10);
    batch2.push_back(20);
    batch2.push_back(30);
    batch2.push_back(-40); // Error here

    n = batch2.size();
    TwoPhaseCommitAdd(batch2,m,n);

    cout << "Batch 2 result - Add with error" << endl;
    m->Print();
    cout << endl;

    /// Bunch of delete without error
    vector<int> batch3;
    batch3.push_back(1);
    batch3.push_back(20);
    batch3.push_back(3);
    batch3.push_back(4);
    n = batch3.size();
    TwoPhaseCommitDelete(batch3,m,n);

    cout << "Batch 3 result - Delete without error" << endl;
    m->Print();
    cout << endl;

    /// Bunch of delete without error
    vector<int> batch4;
    batch4.push_back(11);
    batch4.push_back(12);
    batch4.push_back(13);
    batch4.push_back(14);
    batch4.push_back(15);
    batch4.push_back(16);
    n = batch4.size();
    TwoPhaseCommitAdd(batch4,m,n);

    cout << "Batch 4 result - Add without error" << endl;
    m->Print();
    cout << endl;

    vector<int> batch5;
    batch5.push_back(11);
    batch5.push_back(12);
    batch5.push_back(21);  // Error here
    batch5.push_back(14);
    n = batch5.size();
    TwoPhaseCommitDelete(batch5,m,n);
    cout << "Batch 5 result - Delete with error" << endl;
    m->Print();


    return 1;
}