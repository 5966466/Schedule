//
//  function.hpp
//  schedule
//
//  Created by 谢欣承 on 1/28/17.
//  Copyright © 2017 谢欣承. All rights reserved.
//

#ifndef courseList_hpp
#define courseList_hpp

#include "course.hpp"
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

void is_open_file(std::string documentPath);

bool end_file(std::ifstream & is);

void open_file(std::vector<Course>::iterator course_begin, std::vector<Course>::iterator course_end, std::string filePath, int & count);

void displayMonthCalendar(int chooseMonth, std::string documentPath);

void display(std::vector<Course>::iterator course_begin, std::vector<Course>::iterator course_end, int count);

void revise_insert(std::vector<Course>::iterator course_begin, std::vector<Course>::iterator course_end, int & count);

void delete_(std::vector<Course>::iterator course_begin, std::vector<Course>::iterator course_end);

void save_file(std::vector<Course>::iterator course_begin, std::vector<Course>::iterator course_end, std::string filePath, int count);

#endif /* function_hpp */
