#include <iostream>
#include "lib/header.h"

using namespace std;

int main() {
    MyVector<int> vector2(10);
    randomFillVector(vector2);
    cout << vector2 << endl;

    menu();
    return 0;
}