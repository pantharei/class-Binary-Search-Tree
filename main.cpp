#include "classBST.h"

int main(){

    Tree t;
    t.add(3);
    t.add(9);
    t.add(1);
    t.add(-1);
    t.add(2);
    t.add(8);
    t.add(11);

    t.in();

    t.cancelNode(1);
    t.out();

    t.cancelNode(9);
    t.cancelNode(11);
    t.cancelNode(2);
    t.pre();

    return 0;
}
