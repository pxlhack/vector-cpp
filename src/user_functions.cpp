#include "../lib/user_functions.h"


#define HELP "Menu:\n\
1) Create new empty vector\n\
2) Create new vector(size) and random fill\n"


void menu() {
//    cout << HELP << endl;
    bool flag = true;
    std::string str;

    do {
//        cout << ">";
        getline(cin, str);
        switch (str[0]) {
            case '1': {
//                cout << "Created a empty vector" << endl;
                break;
            }
            case '2': {
                int size = 0;
                cout << "Enter a size:" << endl;
                cin >> size;
                cout << "Size: " << size << endl;
                break;
            }
            case '0' : {
                flag = false;
                break;
            }
            case '\0' : {
                break;
            }
            default: {
                cout << "unknown command!" << endl;
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