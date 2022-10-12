#include "../lib/user_functions.h"



#define HELP "Menu:"


void menu() {
    cout << HELP << endl;
    bool flag = true;
    std::string str;

    do {
        cout << ">";
        getline(cin, str);
        switch (str[0]) {
            case '1': {
                cout << "111" << endl;
                break;
            }
            case '2': {
                cout << "222" << endl;
                break;
            }
            case '0' : {
                flag = false;
                break;

            }
        }

    } while (flag);
}

void randomFillVector(MyVector<int> &myVector) {
    srand(time(NULL));

    for (int i = 0; i < myVector.capacity(); ++i) {
        myVector.push_back(rand() % 10);
    }
}