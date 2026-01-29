//
//  structure.cpp
//  
//
//  Created by Xinhong WU on 29.01.26.
//

/*
 struct is an user customization data type, the properties just like standard data type.
 a collection of several date types makes up a new data type
 */
# include <iostream>

// use semicolon after defined the struct



struct Student{
    std::string name;
    int age;
};

//Nesting
//key point: (strcut name_struct) is whole data type definition. just like (int)
struct Teacher{
    std::string name;
    int age;
    struct Student stu;
};


int main(){
    struct Student s1 = {"xin",20};
    std::cout<<"name: "<<s1.name<<"   age:  "<<s1.age<< std::endl;
    //or
    struct Student* p = &s1;
    std::cout<<"name: "<<p->name<<"   age:  "<<p->age<< std::endl;
    // here is grammer suger,cpp using the -> instead of (*p).name
    std::cout<<"name: "<<(*p).name<<"   age:  "<<(*p).age<< std::endl;
    
    
    struct Student s_arr[] ={{"xin",20},{"hong",25},{"wu",16}};
    for (int i =0 ; i<3; i++){
        std::cout<<"name: "<<s_arr[i].name<<"   age:  "<<s_arr[i].age<< std::endl;
    }
    
    struct Teacher t1= {"xinhong",40,s1};
    std::cout<<"name: "<<t1.name<<"   age:  "<<t1.age<< std::endl;
    std::cout<<"stu name: "<<t1.stu.name<<" stu age:  "<<t1.stu.age<< std::endl;
    
    
    
}
