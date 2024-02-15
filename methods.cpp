#include <iostream>
#include "classes.h"
#include <sstream>
#include <fstream>
#define filename "mipt.csv"
using namespace std;

////////////////////////////////////////////////////////////////////
//������ ��� ������ ���������

student::student() {
    this->id = 0;
    this->name = new string;
    this->surname = new string;
    this->thirdname = new string;
    this->gender = 0;
    this->age = 0;
    this->department = 0;
    this->avg = 0;
    cout << "NEW STUDENT CREATED" << endl;
    //cout << endl;
}

student :: ~student() {
    this->id = 0;
    delete[] this->name;
    delete[] this->surname;
    delete[] this->thirdname;
    this->gender = 0;
    this->age = 0;
    this->department = 0;
    this->avg = 0;
    

}


void student::set_student(int id, string name, string surname, string thirdname, int gender, int age, int department, float avg) {
    this->id = id;
    *this->name = name;
    *this->surname = surname;
    *this->thirdname = thirdname;
    this->gender = gender;
    this->age = age;
    this->department = department;
    this->avg = avg;
    cout << "NEW STUDENT SETTED" << endl;
    cout << name << " " << surname << " " << thirdname << " " << gender << " " << age << " " << department << " " << avg << endl;

    cout << endl;
}

void student::getinfo_std() {
    cout << this->id << " ";
    cout << *(this->name) << " ";
    cout << *(this->surname) << " ";
    cout << *(this->thirdname) << endl;
}


/////////////////////////////////////////////////////
// ������ ��� ������ �� 
ph_dep::ph_dep() {
	this->dep_num = 0;
	this->prf_num = 0;
	this->spec = "";
	this->std_num = 0;
	cout << "DEPARTMENT CREATED" << endl;
	cout << endl;
}

ph_dep :: ~ph_dep() {
	this->dep_num = 0;
	this->prf_num = 0;
	this->spec = "";
	this->std_num = 0;
}


void ph_dep::set_students(student*** alstd) {
    this->std_spec = alstd[this->dep_num];

    int cou = 0;
    while (this->std_spec[cou] != NULL) {
        cou++;
    }
    this->std_num = cou;
}

void ph_dep::getinfo() {
    cout << "======GETINFO======" << endl;
    cout << "DEPARTMENT: " << this->dep_num << endl;
    cout <<  "NUMBER OF STUDENTS: " << this->std_num << endl;

    for (int i = 0; i < this->std_num; i++) {
        this->std_spec[i]->getinfo_std();
    }
    cout << endl;
}






///////////////////////////////////////////////////////////////////
//������ ��� ������� ��������� ��

dasr::dasr() {
    this->showers = 0;
    this->dep_num = 2;
    cout << "DASR CREATED" << endl;
    cout << endl;
}


dgap::dgap() {
    this->dep_num = 1;
    this->showers = 0;
    cout << "DGAP CREATED" << endl;
    cout << endl;
}






///////////////////////////////////////////////
//������ CSV

// ������ csv � ������ 
student*** read_csv() {
    student*** students =  new student ** [8];
    for (int i = 0; i < 8; i++) {
        students[i] = new student* [1000];
    }

    for (int i = 0; i < 8; i++) {
        for (int q = 0; q < 1000; q++ ) {
            students[i][q] = NULL;
        }
    }



    // ������ csv - ����

    ifstream work_file(filename);
    string line;
    char delimiter = ';';
    //������ ������ ������, ����� ��������� ��, ��� ��� ��� �������� ����������
    getline(work_file, line);
    // ��������� ��� �������
    while (getline(work_file, line))
    {
        stringstream stream(line); // �������������� ������ � �����
        string ID, Name, Surname, Thirdname, Gender, Age, Department, Avg;
        // ���������� ���� �������� � ���� ������
        getline(stream, ID, delimiter);
        getline(stream, Name, delimiter);
        getline(stream, Surname, delimiter);
        getline(stream, Thirdname, delimiter);
        getline(stream, Gender, delimiter);
        getline(stream, Age, delimiter);
        getline(stream, Department, delimiter);
        getline(stream, Avg, delimiter);

        int IDint = stoi(ID);
        int Genderint = stoi(Gender);
        int Ageint = stoi(Age);
        int Departmentint = stoi(Department);
        float Avgflt = stof(Avg);

        //������ �������� � ���������� � ���� ������
        student* new_student = new student();
        new_student->set_student(IDint, Name, Surname, Thirdname, Genderint, Ageint, Departmentint, Avgflt);

        // ���������� ��� � ������
        int i = 0;
        while ((students[Departmentint][i]) != NULL) {
            i++;
        }
        students[Departmentint][i] = new_student; 
        
       
    }
    work_file.close();
    return students;
}

///////////////////////////////////////////////////////
//������ ����
void dest(student *** allst) {
    for (int i = 0; i < 8; i++) {
        for (int q = 0; q < 1000; q++) {
            allst[i][q] = NULL;
            delete[] allst[i][q];
        }
        //allst[i] = NULL;
        delete[] allst[i];
    }
    //allst = NULL;
    delete[] allst;
}