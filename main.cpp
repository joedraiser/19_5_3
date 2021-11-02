#include <iostream>
#include <fstream>
#include <vector>

struct manNsalary
        {
            std::string name;
            int salary;
            std::string date;
        };

int main()
{
    std::ifstream payroll;
    payroll.open("payroll.txt");

    if(!payroll.is_open())
    {
        std::cout << "File is not opened.";
        exit(EXIT_FAILURE);
    }


    manNsalary temp, max;
    max.salary=0;
    std::string name, surname;



    while(!payroll.eof())
    {
        payroll >> name >> surname >> temp.salary >> temp.date;
        temp.name=name+" "+surname;
        if(max.salary<temp.salary)
        {
            max=temp;
        }
        name="";
        surname="";

    }

    payroll.close();

    std::cout << "Human with greatest salary: " << max.name << " " << max.salary << " " << max.date;
    return 0;
}
