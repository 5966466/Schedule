//
//  course.cpp
//  schedule
//
//  Created by 谢欣承 on 1/28/17.
//  Copyright © 2017 谢欣承. All rights reserved.
//

#include "course.hpp"
#include <iomanip>

std::ostream & operator<<(std::ostream & os, Course & a)
{
    os << std::setw(2) << a.sequence << "\t" << a.theCourse << std::endl;
    return os;
}

std::istream & operator>>(std::istream & is, Course & a)//没有对输入进行检验
{
    std::cout << "Please input the sequence: ";
    is >> a.sequence;
    std::cout << "Please input the course name: ";
    is.get();
    getline(is, a.theCourse);
    return is;
}

std::ofstream & operator<<(std::ofstream & os, Course & a)
{
    os << "* " << std::setw(2) << a.sequence << "\t" << a.theCourse << std::endl;
    return os;
}

std::ifstream & operator>>(std::ifstream & is, Course & a)
{
    is >> a.sequence;
    is.get();
    getline(is, a.theCourse);
    return is;
}
