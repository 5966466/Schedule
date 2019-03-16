//
//  main.cpp
//  schedule
//
//  Created by 谢欣承 on 1/28/17.
//  Copyright © 2017 谢欣承. All rights reserved.
//
// 操作系统基于macOS/Unix

#include "function.hpp"
using namespace std;

int main()
{
    cout << "Please input the file path: ";
    string documentPath;
    getline(cin, documentPath);
    try
    {
        is_open_file(documentPath + "/1/1.txt");//我认为检查第一个就行了
    }
    catch (char * fail)
    {
        cout << fail;
        exit(EXIT_FAILURE);
    }//异常有问题
    while (1)
    {
        cout << "Please input the month you want to see: (1-12)";
        int chooseMonth;
        cin >> chooseMonth;
        displayMonthCalendar(chooseMonth, documentPath);
        
        cout << "Please input the day you want to see: (1-31)";
        int chooseDay;
        cin >> chooseDay;//没有对输入的月份日期的合法性进行鉴定
        
        stringstream ss;
        ss << "/" << chooseMonth << "/" << chooseDay << ".txt";
        string filePath = documentPath;
        filePath += ss.str();
        
        vector<Course> course_Day(12);//我觉得一天课排满就是12节
        int count = 0;
        open_file(course_Day.begin(), course_Day.end(), filePath, count);
        display(course_Day.begin(), course_Day.end(), count);
        
        int choice;
        bool is_save = true;
        while (1)
        {
            cout << "What do you want to do next?\n"
            << "1 = revise or insert a record.\n"
            << "2 = delete a record.\n"
            << "3 = save the records.\n"
            << "4 = return.\n";
            cin >> choice;//没有对输入合法性进行鉴定
            system("clear");//在windows/DOS系统改为"cls"
            switch (choice)
            {
                case 1:
                    revise_insert(course_Day.begin(), course_Day.end(), count);
                    is_save = false;
                    break;
                case 2:
                    delete_(course_Day.begin(), course_Day.end());
                    count--;
                    is_save = false;
                    break;
                case 3:
                    save_file(course_Day.begin(), course_Day.end(), filePath, count);
                    is_save = true;
                    break;
                default:
                    break;
            }
            if (choice == 4)
            {
                if (!is_save)
                {
                    cout << "Are you sure to quit without saving?(y/n)\n";
                    char yes_no;
                    cin >> yes_no;
                    if (yes_no == 'n')
                    {
                        continue;
                    }
                }
                break;
            }
            display(course_Day.begin(), course_Day.end(), count);
        }
        
        cout << "What do you want to do next?\n"
        << "1 = continue.\n"
        << "2 = quit.\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                break;
            case 2:
                return 0;
        }
    }
    return 0;
}
