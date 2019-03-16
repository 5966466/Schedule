//
//  function.cpp
//  schedule
//
//  Created by 谢欣承 on 1/28/17.
//  Copyright © 2017 谢欣承. All rights reserved.
//

#include "function.hpp"

using namespace std;

void is_open_file(string documentPath) //判断能否打开
{
    ifstream putin(documentPath);
    if (!putin.is_open())
    {
        throw "The file can't open.\n";//这个异常抛出有些问题
    }
    putin.close();
}

bool end_file(ifstream & is)//判断是否到达文末
{
    char temp;
    is >> temp;//读取"*"来判断是否到达文末
    if (is.eof())
    {
        return true;
    }
    return false;
}

void open_file(vector<Course>::iterator course_begin, vector<Course>::iterator course_end, string filePath, int & count)//把文件中的数据读进数组
{
    ifstream putin(filePath);
    putin.ignore(256, '\n');//忽略第一行
    if (end_file(putin))
    {
        cout << "No record." << std::endl;
        putin.close();
        return;
    }
    
    vector<Course>::iterator course;
    Course temp;
    int seq = 1;
    do
    {
        putin >> temp;
        for (course = course_begin; course != course_end; course++, seq++)
        {
            if (temp == seq)
            {
                *course = temp;
                course_begin = course;
                count++;
                break;
            }
        }
    }while(!end_file(putin));//依次赋值
    
    cout << "loading..." << endl;
    cout << count << " records have loaded" << endl;
    putin.close();
}

void displayMonthCalendar(int chooseMonth, string documentPath)//打印月历
{
    const int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char * WEEKNAME[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    int theDayOfYear = 1;
    for(int i = 0;i < (chooseMonth - 1); i++)
    {
        theDayOfYear += MONTH[i];
    }
    
    for (int i = 0; i < 7; i++)
    {
        cout << WEEKNAME[i] << "\t";
    }
    cout << endl;
    
    int j = (theDayOfYear + 6) % 7;
    for (int i = 0; i < j; i++)
    {
        cout << "\t";
    }//确定1日位置
    
    for (int i = 1; i <= MONTH[chooseMonth - 1]; i++, j++)
    {
        stringstream ss;
        ss << "/" << chooseMonth << "/" << i << ".txt";
        cout << i;
        ifstream is(documentPath + ss.str());
        is.ignore(256, '\n');
        if (!end_file(is))
        {
            cout << "*";//如果有记录就在日期数字后面打"*"
        }
        cout << "\t";
        if ((j + 1) % 7 == 0)
        {
            cout << endl;
        }
        is.close();
    }
    cout << endl;
}

void display(vector<Course>::iterator course_begin, vector<Course>::iterator course_end, int count)//展示记录
{
    if (count == 0)
    {
        cout << "No record.\n";
        return;
    }
    
    vector<Course>::iterator course;
    cout << "Seq.\tCourse\n";
    for (course = course_begin; course != course_end; course++)
    {
        if (course->is_null())//如果没数据就跳掉
        {
            continue;
        }
        cout << *course;
    }
}

void revise_insert(vector<Course>::iterator course_begin, vector<Course>::iterator course_end, int & count)//修改和插入放进一个函数了
{
    Course temp;
    cin >> temp;
    vector<Course>::iterator course;
    int seq = 1;
    for (course = course_begin; course != course_end; course++, seq++)
    {
        if (temp == seq)
        {
            if (course->is_null())
            {
                count++;
            }
            *course = temp;
            return;
        }
    }
    cout << "Can't find.\n";
}

void delete_(vector<Course>::iterator course_begin, vector<Course>::iterator course_end)//删除记录
{
    cout << "Please input the sequence you want to delete: ";
    int seq;
    cin >> seq;
    Course temp;//建立一个空白的副本
    vector<Course>::iterator course;
    for (course = course_begin; course != course_end; course++)
    {
        if (*course == seq)
        {
            *course = temp;//把这条记录弄成空白
            return;
        }
    }
    cout << "Can't find.\n";
}

void save_file(vector<Course>::iterator course_begin, vector<Course>::iterator course_end, string filePath, int count)//保存记录
{
    ofstream putout(filePath);
    if (count == 0)
    {
        putout << "No record.\n";
        return;
    }
    
    vector<Course>::iterator course;
    putout << "* Seq.\tCourse\n";
    for (course = course_begin; course != course_end; course++)
    {
        if (course->is_null())
        {
            continue;
        }
        putout << *course;
    }
}
