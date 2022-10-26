#include "../lib/user_functions.h"
#include <exception>


#define HELP "Menu:\n\
1) Create new empty vector\n\
2) Create new vector(size) and random fill\n\
3) Push item to vector\n\
4) Show vector\n\
5) Delete item by index from vector\n\
6) Insert an item into a position\n\
7) Show vector size and capacity\n\
8) Clear vector\n\
9) Сheck the vector for emptiness\n\
10) Find out if there is item in the vector\n\
11) Show vector using iterators\n\
12) Show vector using reverse iterators\n\
13) Сhange the value in the position\n\
14) Get position in vector for a given value\n\
15) Delete item by value\n\
16) Iterators\n\
0) Exit\n"


void randomFillVector(MyVector<int> *myVector) {
    srand(time(NULL));

    for (int i = 0; i < myVector->capacity(); ++i) {
        myVector->push_back(rand() % 200 - 100);
    }
}


void testmenu() {
    MyVector<int> *v1 = nullptr, *v2 = nullptr, *v3 = nullptr;
    MyVector<int> *myVector[3] = {v1, v2, v3};

    bool flag = true;
    string str;

    do {
        cout << HELP;
        cout << ">";
        cin >> str;
        try {
            int num = stoul(str);
            cout << num << endl;
            switch (num) {
                case 1: {
                    if (myVector[0] != nullptr) {
                        cout << "-- Vector has already been created --\nEnter the '8' to clear vector\n\n";
                    } else {
                        string str1;
                        bool flag1 = true;

                        do {
                            cout << "Enter a size:";
                            cin >> str1;

                            if (str1 == "e") break;

                            try {
                                int size = stoul(str1);
                                myVector[0] = new MyVector<int>(size);

                                flag1 = false;
                                cout << "~~ Created a empty vector (size = " << size << ")~~\n\n";
                            }

                            catch (exception &e) {
                                cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                            }

                        } while (flag1);

                    }

                    break;
                }
                case 2: {
                    if (myVector[0] != nullptr) {
                        cout << "-- Vector has already been created --\nEnter the '8' to clear vector\n\n";
                        break;
                    }

                    string str2;
                    bool flag2 = true;

                    do {
                        cout << "Enter a size:";
                        cin >> str2;

                        if (str2 == "e") break;

                        try {
                            int size = stoul(str2);
                            myVector[0] = new MyVector<int>(size);
                            randomFillVector(myVector[0]);

                            flag2 = false;
                            cout << "~~Created and filled vector (size = " << size << ")~~\n\n";
                        }

                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }

                    } while (flag2);

                    break;
                }
                case 3: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    string str3;
                    bool flag3 = true;

                    do {
                        cout << "Enter the number:";
                        cin >> str3;

                        if (str3 == "e") break;
                        try {
                            int item = stoul(str3);
                            myVector[0]->push_back(item);

                            flag3 = false;
                            cout << "~~ " << item << " pushed to v1~~\n";
                            cout << "### number of requests: " << myVector[0]->getCount() << " ###\n\n";
                            myVector[0]->setCount(0);
                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag3);

                    break;
                }
                case 4: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    cout << *myVector[0] << endl;
                    cout << "### number of requests: " << myVector[0]->size() << " ###\n\n";
                    break;
                }
                case 5: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    string str5;
                    bool flag5 = true;

                    do {
                        cout << "Enter the index:";
                        cin >> str5;

                        if (str5 == "e") break;
                        try {
                            int index = stoul(str5);
                            int item;
                            try {
                                item = myVector[0]->get(index);
                                //1 + size-index
                                myVector[0]->erase(index);

                                flag5 = false;
                                cout << "~~ v[" << index << "] = " << item << " deleted from vector\n";
                                cout << "### number of requests: 1 + " << myVector[0]->size() - index << " ###\n\n";
                                break;
                            }
                            catch (const char *e) { cout << e; }

                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag5);

                    break;
                }
                case 6: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    string str61, str62;
                    bool flag61 = true, flag62 = true;
                    int item, index;

                    do {
                        cout << "Enter the number:";
                        cin >> str61;

                        if (str61 == "e") break;

                        try {
                            item = stoul(str61);
                            flag61 = false;
                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag61);

                    if (myVector[0]->size() == 0) {
                        myVector[0]->push_back(item);
                        cout << "~~ " << item << " pushed to v1~~\n";
                        cout << "### number of requests: " << myVector[0]->getCount() << " ###\n\n";
                        myVector[0]->setCount(0);
                        break;
                    }

                    do {
                        cout << "Enter the position [0, " << myVector[0]->size() << "]:";
                        cin >> str62;
                        if (str62 == "e") break;
                        try {
                            index = stoul(str62);

                            try {
                                myVector[0]->insert(item, index);

                                flag62 = false;
                                cout << "~~ '" << item << "' inserted into " << index << " position\n";
                                cout << "### number of requests: " << myVector[0]->getCount() << " ###\n\n";
                            }
                            catch (const char *e) { cout << e; }

                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag62);


                    break;
                }
                case 7: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }
                    cout << "~~ Size = " << myVector[0]->size() << " ~~\n";
                    cout << "~~ Capacity = " << myVector[0]->capacity() << " ~~\n";
                    break;
                }
                case 8: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    myVector[0]->clear();
                    cout << "~~ Vector cleared ~~\n\n";
                    break;
                }
                case 9: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty())
                        cout << "~~ Vector is empty ~~\n\n";
                    else
                        cout << "-- Vector is not empty --\nEnter '4' to show vector\n\n";

                    break;

                }
                case 10: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    string str10;
                    bool flag10;

                    do {
                        cout << "Enter the number:";
                        cin >> str10;

                        if (str10 == "e") break;

                        try {
                            int item = stoul(str10);
                            if (myVector[0]->contains(item))
                                cout << "Vector contains " << item << endl;
                            else
                                cout << "Vector does not contain " << item << endl;
                            cout << "### number of requests: " << myVector[0]->getCount() << " ###\n\n";
                            myVector[0]->setCount(0);

                            flag10 = false;
                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag10);

                    break;
                }
                case 11: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    auto it = myVector[0]->begin();
                    while (it != myVector[0]->end()) {
                        cout << *it << " ";
                        it++;
                    }
                    cout << endl;
                    cout << "### number of requests: " << myVector[0]->size() << " ###\n\n";
                    break;
                }
                case 12: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    auto it = myVector[0]->rbegin();
                    while (it != myVector[0]->rend()) {
                        cout << *it << " ";
                        it++;
                    }
                    cout << endl;
                    cout << "### number of requests: " << myVector[0]->size() << " ###\n\n";
                    break;
                }
                case 13: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    string str13_1, str13_2;
                    bool flag13_1 = true, flag13_2 = true;
                    int item, index;

                    do {
                        cout << "Enter the number:";
                        cin >> str13_1;

                        if (str13_1 == "e") break;

                        try {
                            item = stoul(str13_1);
                            flag13_1 = false;
                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag13_1);

                    if (myVector[0]->size() == 1) {
                        myVector[0]->set(item, index);
                        cout << "### number of requests: " << 1 << " ###\n\n";
                        break;
                    }

                    do {
                        cout << "Enter the position [0, " << myVector[0]->size() - 1 << "]:";
                        cin >> str13_2;
                        if (str13_2 == "e") break;
                        try {
                            index = stoul(str13_2);

                            try {
                                myVector[0]->set(item, index);
                                cout << "### number of requests: " << 1 << " ###\n\n";

                                flag13_2 = false;
                            }
                            catch (const char *e) { cout << e; }

                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag13_2);
                    break;
                }
                case 14: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    string str14;
                    bool flag14 = true;
                    int item, index;

                    do {
                        cout << "Enter the number:";
                        cin >> str14;

                        if (str14 == "e") break;

                        try {
                            item = stoul(str14);
                            index = myVector[0]->index_of(item);

                            if (index != -1) {
                                cout << "Position of " << item << " = " << index << endl;

                            } else
                                cout << "Vector does not contain " << item << endl;
                            cout << "### number of requests: " << myVector[0]->getCount() << " ###\n\n";
                            flag14 = false;
                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag14);

                    break;
                }
                case 15: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    string str15;
                    bool flag15 = true;

                    do {
                        cout << "Enter the number:";
                        cin >> str15;

                        if (str15 == "e") break;
                        try {
                            int item = stoul(str15);
                            if (myVector[0]->contains(item)) {
                                myVector[0]->remove(item);
                                cout << item << " deleted from vector\n";

                            } else {
                                cout << item << " item not found in vector\n";

                            }
                            cout << "### number of requests: " << myVector[0]->getCount() << " ###\n\n";
                            flag15 = false;
                        }
                        catch (exception &e) {
                            cout << "Not a number!\nEnter the number or enter 'e' to exit to this menu item\n\n";
                        }
                    } while (flag15);

                    break;
                }
                case 16: {
                    if (myVector[0] == nullptr) {
                        cout << "-- Vector not created --\n Enter '1' or '2' to create vector\n\n ";
                        break;
                    }

                    if (myVector[0]->is_empty()) {
                        cout << "-- Vector is empty --\n Enter '3' to insert item to vector\n\n";
                        break;
                    }

                    bool flag16 = true;
                    string str16;
                    do {
                        cout << "1) it++\n2) it--\n3) *it\n4) begin\n5) end\n6) show\n";
                        cout << ">";
                        cin >> str16;
                        MyIterator<int> it;
                        try {
                            int num = stoul(str16);
                            switch (num) {
                                case 1: {
                                    if ((it) == myVector[0]->end())
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
                                    if (it == myVector[0]->end())
                                        cout << "iterator is not installed\n";
                                    else
                                        cout << *it << endl;

                                    break;
                                }
                                case 4: {
                                    it = myVector[0]->begin();
                                    break;
                                }
                                case 5: {
                                    it = myVector[0]->end();
                                    break;
                                }
                                case 6: {
                                    auto it2 = myVector[0]->begin();
                                    while (it2 != myVector[0]->end()) {
                                        cout << *it2 << " ";
                                        it2++;
                                    }
                                    cout << endl;
                                    break;
                                }
                                case 0: {
                                    flag16 = false;
                                    break;
                                }
                                default: {
                                    cout << "!!! unknown command: " << str16 << " !!!" << endl;
                                    break;

                                }
                            }
                        } catch (exception &e) {
                            cout << "!!! unknown command: " << str16 << " !!!" << endl;
                        }

                    } while (flag16);
                    break;
                }
                case 0 : {
                    flag = false;
                    break;
                }
                default: {
                    cout << "!!! unknown command: " << str << " !!!" << endl;
                }
            }
        }
        catch (exception &e) {
            cout << "!!! unknown command: " << str << " !!!" << endl;
        }
    } while (flag);
}
