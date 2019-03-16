//
//  course.hpp
//  schedule
//
//  Created by 谢欣承 on 1/28/17.
//  Copyright © 2017 谢欣承. All rights reserved.
//

#ifndef course_hpp
#define course_hpp

#include <string>
#include <fstream>
#include <iostream>

class Course
{
private:
    int sequence;
    std::string theCourse;
    //std::string detail;
public:
    Course(){sequence = 0; theCourse = "None";}
    ~Course(){}
    bool is_null() const {return (sequence == 0);}//判断是不是空白记录
    bool operator==(int seq) const{return (sequence == seq);}
    
    friend std::ostream & operator<<(std::ostream & os, Course & a);
    friend std::istream & operator>>(std::istream & is, Course & a);
    friend std::ofstream & operator<<(std::ofstream & os, Course & a);
    friend std::ifstream & operator>>(std::ifstream & is, Course & a);
};
#endif /* course_hpp */
