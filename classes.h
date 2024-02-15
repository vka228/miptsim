#pragma once
#include <iostream>
using namespace std;

// класс студента
class student {
private:
    int id;
    string* name;
    string* surname;
    string* thirdname;
    int gender;
    int age;
    int department;
    float avg;
public:
    student(); // конструктор
    ~student(); // деструктор
    void cleanup();
    //настройка студента
    void set_student(int id, string name, string surname, string thirdname, int gender, int age, int department, float avg);
    void getinfo_std();//информация

};

// класс фш
 class ph_dep {
protected:
    int dep_num;
    int std_num;
    int prf_num;
    string spec;
    student** std_spec;

public:
    ph_dep();
    ~ph_dep();
    void getinfo();//информация
    void dism_std();
    void dism_prof();
    void set_students(student*** alstd);//раскидываем студентов по фш
}; 

 

 // классы отдельных фш

 class dgap : public ph_dep {
 private:
     int showers;
 public:
     dgap();
};

 class dasr : public ph_dep {
 private:
     int showers;
 public:
     dasr();

 };

 //список функций
 student*** read_csv();//читает csv и создаёт массив со всеми студентами
 void dest(student*** allst);//удаляет массив со всеми студентами