#pragma once
#include <iostream>
using namespace std;

// ����� ��������
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
    student(); // �����������
    ~student(); // ����������
    void cleanup();
    //��������� ��������
    void set_student(int id, string name, string surname, string thirdname, int gender, int age, int department, float avg);
    void getinfo_std();//����������

};

// ����� ��
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
    void getinfo();//����������
    void dism_std();
    void dism_prof();
    void set_students(student*** alstd);//����������� ��������� �� ��
}; 

 

 // ������ ��������� ��

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

 //������ �������
 student*** read_csv();//������ csv � ������ ������ �� ����� ����������
 void dest(student*** allst);//������� ������ �� ����� ����������