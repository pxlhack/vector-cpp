#include "../lib/user_functions.h"
#include <exception>


#define HELP "Menu:\n\
1) Create new empty vector\n\
2) Create new vector(size) and random fill\n\
3) Push value to vector\n\
4) Insert an value into a position\n\
5) Сhange the value in the position\n\
6) Get position in vector for a given value\n\
7) Show vector\n\
8) Show size and capacity\n\
9) Сheck the vector for emptiness\n\
10) Find out if there is value in the vector\n\
11) Delete value by index from vector\n\
12) Delete value by value\n\
13) Clear vector\n\
14) Iterators\n\
15) Count of values in previous operation\n\
0) Exit\n"


bool foo(int &value);

void randomFillVector(MyVector<int> **myVector) {
    srand(time(NULL));

    for (int i = 0; i < (*myVector)->getCapacity(); ++i) {
        (*myVector)->pushBack(rand() % 200 - 100);
    }
}

bool isPositiveValue(std::string_view s) {
    static const regex r(R"(\d{1,})");
    return regex_match(s.data(), r);
}

bool isNegativeValue(std::string_view s) {
    static const regex r(R"(-\d{1,})");
    return regex_match(s.data(), r);
}

string getPositiveValueAsString(string desiredValue) {
    string str;
    bool flag = true;

    do {
        cout << "Enter the " << desiredValue << ":";
        cin >> str;

        if (str == "e") break;
        if (isPositiveValue(string_view(str))) {
            flag = false;
        } else {
            cout << "Not a number!\n\n";
        }
    } while (flag);
    return str;
}

string getIntegerValueAsString(string desiredValue) {
    string str;
    bool flag = true;

    do {
        cout << "Enter the " << desiredValue << ":";
        cin >> str;

        if (str == "e") break;
        if (isPositiveValue(string_view(str)) || isNegativeValue(string_view(str))) {
            flag = false;
        } else {
            cout << "Not a number!\n\n";
        }
    } while (flag);
    return str;
}

bool createVector(MyVector<int> **v) {
    string str = getPositiveValueAsString("size");
    if (str == "e") {
        return false;
    }

    if (*v != nullptr) {
        (*v)->clear();
    }

    int size = stoul(str);
    *v = new MyVector<int>(size);

    cout << "~~ Created a empty vector (size = " << size << ")~~\n\n";
    return true;
}

bool setValueFromString(int *value) {
    string valueString = getIntegerValueAsString("value");
    if (valueString == "e") {
        return true;
    }
    *value = stoul(valueString);
    return false;
}

bool setPositionFromString(int *pos) {
    string positionString = getIntegerValueAsString("position");
    if (positionString == "e") {
        return true;
    }
    *pos = stoul(positionString);
    return false;
}


void testmenu() {
    MyVector<int> *pMyVector = nullptr;

    bool isWorked = true;
    string command;

    do {
        cout << HELP;
        cout << ">";
        cin >> command;

        if (isPositiveValue(std::string_view(command))) {
            int num = stoul(command);
            switch (num) {
                case 1: {
                    createVector(&pMyVector);
                    break;
                }
                case 2: {
                    bool isCreatedVector = createVector(&pMyVector);
                    if (isCreatedVector) {
                        randomFillVector(&pMyVector);
                    }
                    break;
                }
                case 3: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n";
                        break;
                    }

                    string valueString = getIntegerValueAsString("value");
                    if (valueString == "e") {
                        break;
                    }
                    int value = stoul(valueString);

                    pMyVector->pushBack(value);
                    cout << "~~ " << value << " pushed to pMyVector~~\n";
                    break;
                }
                case 4: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    string valueString = getIntegerValueAsString("value");
                    if (valueString == "e") {
                        break;
                    }
                    int value = stoul(valueString);

                    string positionValue = getPositiveValueAsString("position");
                    if (positionValue == "e") {
                        break;
                    }
                    int pos = stoul(positionValue);

                    try {
                        pMyVector->insert(value, pos);
                        cout << "~~ '" << value << "' inserted into " << pos << " position\n";
                    }
                    catch (const char *e) { cout << e; }
                    break;
                }
                case 5: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n ";
                        break;
                    }

                    if (pMyVector->isEmpty()) {
                        cout << "-- Vector is empty --\n\n";
                        break;
                    }

                    int value;
                    if (setValueFromString(&value)) {
                        break;
                    }

                    int position;
                    if (setPositionFromString(&position)) {
                        break;
                    }

                    pMyVector->setValue(value, position);

                    break;
                }
                case 6: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n ";
                        break;
                    }

                    if (pMyVector->isEmpty()) {
                        cout << "-- Vector is empty --\n\n";
                        break;
                    }

                    int value;
                    if (setValueFromString(&value)) {
                        break;
                    }

                    int position = pMyVector->indexOf(value);
                    if (position != -1) {
                        cout << "Position of " << value << " = " << position << endl;
                    } else {
                        cout << "Vector does not contain " << value << endl;
                    }
                    break;
                }
                case 7: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }
                    cout << *pMyVector << endl;
                    break;
                }
                case 8: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n";
                        break;
                    }
                    cout << "~~ Size = " << pMyVector->getSize() << " ~~\n";
                    cout << "~~ Capacity = " << pMyVector->getCapacity() << " ~~\n";
                    break;
                }
                case 9: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n";
                        break;
                    }

                    if (pMyVector->isEmpty()) {
                        cout << "~~ Vector is empty ~~\n\n";
                    } else {
                        cout << "-- Vector is not empty --\n\n";
                    }
                    break;
                }
                case 10: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n";
                        break;
                    }

                    int value;
                    if (setValueFromString(&value)) {
                        break;
                    }

                    if (pMyVector->contains(value))
                        cout << "Vector contains " << value << endl;
                    else
                        cout << "Vector does not contain " << value << endl;

                    break;
                }
                case 11: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (pMyVector->isEmpty()) {
                        cout << "-- Vector is empty --\n\n";
                        break;
                    }

                    int position;
                    if (setPositionFromString(&position)) {
                        break;
                    };

                    try {
                        int value = pMyVector->getValue(position);
                        pMyVector->erase(position);
                        cout << "~~ pMyVector[" << position << "] = " << value << " deleted from vector\n";
                    }
                    catch (const char *e) { cout << e; }

                    break;
                }
                case 12: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n ";
                        break;
                    }

                    if (pMyVector->isEmpty()) {
                        cout << "-- Vector is empty --\n\n";
                        break;
                    }

                    int value;
                    if (setValueFromString(&value)) {
                        break;
                    }
                    if (pMyVector->contains(value)) {
                        pMyVector->removeByValue(value);
                        cout << value << " deleted from vector\n";
                    } else {
                        cout << value << " value not found in vector\n";
                    }

                    break;
                }
                case 13: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n ";
                        break;
                    }

                    pMyVector->clear();
                    cout << "~~ Vector cleared ~~\n\n";
                    break;
                }
                case 14: {
                    if (pMyVector == nullptr) {
                        cout << "-- Vector not created --\n\n";
                        break;
                    }

                    if (pMyVector->isEmpty()) {
                        cout << "-- Vector is empty --\n\n";
                        break;
                    }

                    bool isIteratorsWorked = true;
                    string iteratorsCommand;
                    do {
                        cout << "1) it++\n2) it--\n3) *it\n4) begin\n5) end\n6) show\n";
                        cout << ">";
                        cin >> iteratorsCommand;
                        MyIterator<int> it;
                        try {
                            int num = stoul(iteratorsCommand);
                            switch (num) {
                                case 1: {
                                    if ((it) == pMyVector->end())
                                        cout << "iterator is not installed\n";
                                    else
                                        it++;
                                    break;
                                }
                                case 2: {
                                    it--;
                                    break;
                                }
                                case 3: {
                                    if (it == pMyVector->end())
                                        cout << "iterator is not installed\n";
                                    else
                                        cout << *it << endl;

                                    break;
                                }
                                case 4: {
                                    it = pMyVector->begin();
                                    break;
                                }
                                case 5: {
                                    it = pMyVector->end();
                                    break;
                                }
                                case 6: {
                                    auto it2 = pMyVector->begin();
                                    while (it2 != pMyVector->end()) {
                                        cout << *it2 << " ";
                                        it2++;
                                    }
                                    cout << endl;
                                    break;
                                }
                                case 0: {
                                    isIteratorsWorked = false;
                                    break;
                                }
                                default: {
                                    cout << "!!! unknown command: " << iteratorsCommand << " !!!" << endl;
                                    break;

                                }
                            }
                        } catch (exception &e) {
                            cout << "!!! unknown command: " << iteratorsCommand << " !!!" << endl;
                        }

                    } while (isIteratorsWorked);
                    break;
                }
                case 15: {
                    cout << "Count of values in previous operation: "
                         << pMyVector->getPreviousOperationValuesCount()
                         << endl;
                    break;
                }
                case 0 : {
                    isWorked = false;
                    break;
                }
                default: {
                    cout << "!!! unknown command: " << command << " !!!" << endl;
                }
            }
        } else {
            cout << "!!! unknown command: " << command << " !!!" << endl;
        }

    } while (isWorked);
}

