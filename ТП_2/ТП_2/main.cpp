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
                cout << "3. Exit" << endl;
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
            char array[100][100];

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
                int i = 0;
                while (fs.getline(str, 100))
                {
                    int kol = 0;
                    bool flag = false;

                    for (int j = 0, kl = 0; j < 100; j++)
                    {
                        if (!flag && strin[0] != ' ' && (str[j] == '\n' || str[j] == '\0'))
                        {
                            strin[kl] = '\n';
                            for (int k = 0; strin[k] != '\n'; k++)
                                cout << strin[k];

                            strin[0] = ' ';
                            break;
                        }

                        if (str[j] == ' ')
                        {
                            flag = true;
                            j++;
                        }

                        if (!flag)
                            strin[kl] = str[j];

                        kl++;

                        if (flag)
                        {
                            strin[kl - 1] = '\n';
                            for (int k = j; str[k] != ' ' && str[k] != '\n' && str[k] != '\0'; k++)
                            {
                                cout << str[k];
                                kol++;
                            }

                            cout << ' ';

                            for (int k = 0; strin[k] != '\n'; k++)
                                cout << strin[k];

                            cout << ' ';

                            strin[0] = ' ';
                            kl = 0;
                            j += kol;
                            kol = 0;
                            flag = false;
                        }
                    }
                    i++;
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