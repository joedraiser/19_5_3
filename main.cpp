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
    payroll.open("C:\\Users\\evgenii.korchagov\\CLionProjects\\19_5_3\\payroll.txt");

    if(!payroll.is_open())
    {
        std::cout << "File is not opened.";
        exit(EXIT_FAILURE);
    }

    std::vector<manNsalary> ppleNstuff;
    manNsalary temp;
    std::string name, surname;



    while(!payroll.eof())
    {
        payroll >> name >> surname >> temp.salary >> temp.date;
        temp.name+=name+" "+surname;
        name="";
        surname="";
        ppleNstuff.push_back(temp);
        temp.name="";
    }

    payroll.close();

    for(int i=0;i<ppleNstuff.size();i++)
    {
        if(temp.salary<ppleNstuff[i].salary)
        {
            temp.name=ppleNstuff[i].name;
            temp.salary=ppleNstuff[i].salary;
            temp.date=ppleNstuff[i].date;
        }
    }

    std::cout << "Human with greatest salary: " << temp.name << " " << temp.salary << " " << temp.date;
    return 0;
}
