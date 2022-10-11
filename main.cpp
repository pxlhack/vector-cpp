#include <iostream>
#include "lib/my_vector.h"

using namespace std;

int main() {
    MyVector<int> vector1;
    for (int i = 0; i < 10; ++i) {
        vector1.push_back(i);
    }

    MyVector<int> vector3(vector1);
    cout << vector3.size() << endl;

    vector3.clear();

    vector3.push_back(4);
    cout << vector3.size() << " " << vector3.capacity() << endl;
    return 0;
}
