#include <iostream>
#include "classes.h"
using namespace std;


//названия ф/ш
//string dep_array = ("DRCT", "DGAP", "DASR", "FEFM", "FPMI", "FBMF", "INBIKST");




int main()
{
	student*** all_std = read_csv();
	dasr dasr;
	dgap dgap;
	dasr.set_students(all_std);
	dgap.set_students(all_std);
	dgap.getinfo();
	dasr.getinfo();

	dest(all_std);
}