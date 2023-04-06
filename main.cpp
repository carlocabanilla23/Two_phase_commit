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

int main () {
    LinkedList* m = new LinkedList(5);
    m->Print();
    assert(m->Add(1 ) == true);
    m->Commit();
    m->Print();
    assert(m->Add(2) == true);

    assert(m->Add(4) == true);
    m->Print();
    m->RollBack();
    assert(m->Add(3) == true);
    m->Print();
    m->Commit();
    assert(m->Delete(3) == true);
    m->Print();
//  assert(m->Delete(6) == false);
    m->RollBack();
    m->Print();

    return 1;
}