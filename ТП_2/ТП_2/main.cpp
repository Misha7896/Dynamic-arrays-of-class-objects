#include "STUDENT.h"
#include "GROUP.h"

using namespace std;

int GROUP::Count = 0;

int main()
{
    while(true)
    {
        char c;
        cout << "\nMenu:" << endl;
        cout << "1. Task number 1" << endl;
        cout << "2. Task number 2" << endl;
        cout << "3. Exit" << endl;
        cin >> c;

        if (int(c - 48) == 1)
        {
            vector<GROUP> groups;

            while (true) {
                int choice;
                cout << "\nMenu:" << endl;
                cout << "1. Add student to group" << endl;
                cout << "2. Display students with good grades" << endl;
                cout << "3. Delete" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    int groupNumber;
                    cout << "Enter group number: ";
                    cin >> groupNumber;

                    STUDENT newStudent;
                    cin >> newStudent;

                    bool foundGroup = false;
                    for (auto& group : groups) {
                        if (group.groupNumber == groupNumber) {
                            group.addStudent(newStudent);
                            foundGroup = true;
                            break;
                        }
                    }

                    if (!foundGroup) {
                        GROUP newGroup;
                        newGroup.groupNumber = groupNumber;
                        newGroup.addStudent(newStudent);
                        groups.push_back(newGroup);
                    }
                }
                else if (choice == 2) {
                    bool flag = true;

                    int min;
                    int max = -1;

                    for (auto& group : groups)
                        flag = false;

                    if (flag)
                        cout << "There are no groups" << endl;
                    else
                        min = groups[0].groupNumber;

                    for (int i = GROUP::Count; i > 0; i--)
                    {
                        for (auto& group : groups)
                        {
                            if (max < group.groupNumber)
                                min = group.groupNumber;
                        }

                        for (auto& group : groups) {
                            if (min > group.groupNumber && max < group.groupNumber)
                                min = group.groupNumber;
                        }

                        for (auto& group : groups) {

                            if (min == group.groupNumber)
                            {
                                group.displayStudentsWithGoodGrades();
                                max = group.groupNumber;
                            }
                        }
                    }

                }
                else if (choice == 3) {
                    int groupNumber;
                    cout << "Enter group number: ";
                    cin >> groupNumber;

                    //bool foundGroup = false;
                    int i = 0;
                    for (auto& group : groups) {
                        if (group.groupNumber == groupNumber) {
                            groups.erase(groups.begin() + i);
                            GROUP::Count--;
                            break;
                        }
                        i++;
                    }

                }
                else if (choice == 4) {
                    int i = (GROUP::Count - 1);
                    for( ; i > 0; i--)
                        groups.erase(groups.begin() + i);
                    break;
                }
                else {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }

            return 0;
        }
        else if (int(c - 48) == 2)
        {
            char strin[100];
            char str[100];

            fstream fs;
            fs.open("myFile.txt", fstream::in | fstream::out);
            if (!fs.is_open())
            {
                cout << "Error: the file did not open!" << endl;
            }
            else
            {
                for (int i = 0; fs.getline(str, 100); i++)
                {
                    int kol = 0;
                    bool flag = false;

                    for (int j = 0, kl = 0; j < 100; j++)
                    {
                        //char SpaceR = 'T';
                        //char SpaceL = 'T';


                        int SpaceR = 0;
                        int SpaceL = 0;


                        if (!flag && strin[0] != ' ' && (str[j] == '\n' || str[j] == '\0'))
                        {
                            strin[kl] = '\n';
                            for (int k = 0; strin[k] != '\n'; k++)
                                cout << strin[k];

                            strin[0] = ' ';
                            break;
                        }

                        if (str[j] == ' ' || str[j] == '!' || str[j] == '.' || str[j] == ',')
                        {
                            SpaceL = j;
                            flag = true;
                            for (; str[j] == ' ' || str[j] == '!' || str[j] == '.' || str[j] == ','; j++, kol--);
                            kol++;
                        }

                        if (!flag)
                        {
                            strin[kl] = str[j];
                        }

                        kl++;

                        // Пишу в консоль
                        if (flag)
                        {
                            // Первая часть (второе слово)
                            strin[kl - 1] = '\n';
                            for (int k = j; str[k] != ' ' && str[k] != '\n' && str[k] != '\0'; k++)
                            {
                                if (str[k] == '!' || str[k] == '.' || str[k] == ',')
                                {
                                    SpaceR = k;
                                    //kol++;
                                    break;
                                }
                                else
                                    cout << str[k];
                                kol++;
                            }

                            if (SpaceL != 0)
                            {
                                {
                                    for (int k = SpaceL; (str[k] == ' ' || str[k] == '!' || str[k] == '.' || str[k] == ',') && (str[k] != '\n' && str[k] != '\0'); k++)
                                    {
                                        kol++;
                                        cout << str[k];
                                    }
                                    kol--;
                                    SpaceL = 0;
                                }
                            }
                            else
                                cout << ' ';

                            // Вторая часть (первое слово)
                            for (int k = 0; strin[k] != '\n'; k++)
                                cout << strin[k];

                            if (SpaceR != 0)
                            {
                                for (int k = SpaceR; (str[k] == ' ' || str[k] == '!' || str[k] == '.' || str[k] == ',') && (str[k] != '\n' && str[k] != '\0'); k++)
                                {
                                    kol++;
                                    cout << str[k];
                                }
                                kol--;
                                SpaceR = 0;
                            }
                            else
                                cout << ' ';

                            strin[0] = ' ';
                            kl = 0;
                            j += kol;
                            kol = 0;
                            flag = false;
                        }
                    }
                    cout << endl;
                }
            }
            fs.close();
        }
        else if (int(c - 48) == 3) {
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}