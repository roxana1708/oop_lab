#include <iostream>

#include "ArboreBicolor.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Arbore_bicolor tree;
    tree.insertRBT(47);
    tree.insertRBT(32);
    tree.insertRBT(71);
    tree.insertRBT(93);
    tree.insertRBT(65);
    tree.insertRBT(82);
    tree.insertRBT(87);
    tree.insertRBT(51);
    tree.deleteRBT(71);

    Arbore_bicolor tree2;
    tree2.insertRBT(12);
    tree2.insertRBT(5);
    tree2.insertRBT(15);

    tree2.insertRBT(3);
    tree2.insertRBT(10);
    tree2.insertRBT(13);
    tree2.insertRBT(17);

    std::cout << tree2.adancimeArbore(tree2.getRadacina()) << std::endl;

    tree2.insertRBT(4);
    tree2.insertRBT(7);
    tree2.insertRBT(11);
    tree2.insertRBT(14);
    tree2.insertRBT(6);
    tree2.insertRBT(8);
    tree2.deleteRBT(7);
    tree2.deleteRBT(6);
    tree2.deleteRBT(8);
    std::cout << tree2;
    std::cout << tree2.adancimeArbore(tree2.getRadacina());


    ABC tree3;
    tree3.inserareVal(12);
    tree3.inserareVal(10);
    tree3.inserareVal(4);
    tree3.inserareVal(3);
    tree3.inserareVal(2);
    tree3.inserareVal(1);
    std::cout << tree3;
    std::cout << tree3.adancimeArbore(tree3.getRadacina());


    Arbore_bicolor tree4;
    tree4.insertRBT(8);
    tree4.insertRBT(3);
    tree4.insertRBT(13);
    tree4.insertRBT(2);
    tree4.insertRBT(6);
    tree4.insertRBT(11);
    tree4.insertRBT(17);
    tree4.insertRBT(1);
    tree4.insertRBT(5);
    tree4.insertRBT(7);
    tree4.insertRBT(10);
    tree4.insertRBT(12);
    tree4.insertRBT(15);
    tree4.insertRBT(18);
    tree4.insertRBT(4);
    tree4.insertRBT(14);
    tree4.insertRBT(16);


    std::cout << tree4;

    return 0;
}
