#include <iostream>

#include "ArboreBicolor.h"

int main() {

    Arbore_bicolor arb;
    int v[100] = {47, 32, 71, 93, 65, 82, 87, 51};
    int a[100] = {71, 87};
    arb.insert(v);
    std::cout << arb;
    arb.sterge(a);
    std::cout << arb;

    ABC arb2;
    arb2.insert(v);
    std::cout << arb2;
    arb2.sterge(a);
    std::cout << arb2;
    return 0;
}
