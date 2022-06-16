#include "Group.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");//руссификатор

    Progress pr("Информатика", { 3,4,4,5 });

    Student Ivan("Иван"s, 18, { {"Математика"s, {2,3,4,5}}, {"Геометрия"s, {5,5,5,5}}, {"Русский язык"s, {2,3,4,5}} });
    Student Den("Денис"s, 18, { {"Математика"s, {5,5,5,5}}, {"Геометрия"s, {5,5,5,5}}, {"Русский язык"s, {5,5,5,5}} });
    Student Kolya("Коля"s, 18, { {"Математика"s, {2,2,2,2}}, {"Геометрия"s, {5,5,5,5}}, {"Русский язык"s, {2,2,2,2}} });
    Student Matvey("Матвей"s, 18, { {"Математика"s, {2,2,2,2}}, {"Геометрия"s, {5,5,5,5}}, {"Русский язык"s, {2,2,2,2}} });
    Matvey = Matvey + pr;

    Group one(1, { Ivan,Den,Kolya });
    one = one + Matvey;
    cout << one.CalcAverageMark() << endl;
    cout << one.CalcAverageMark("Геометрия"s) << endl;

   
    //отличники - у кого средний балл по всем предметам - 5
    //задолжники - те у кого средний балл хотябы по одному предмету 2
    one.PrintHonorStudents();
    one.PrintDebtorStudents();

    cout << one << endl;
}

