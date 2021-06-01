#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <iterator>

#include "funkcije.h"
#include "person.h"
#include "menu.h"
using namespace std;

int main()
{
    loadFromFile();

    int t;
    bool testing = true;
    while (testing == true) {

        printajMainMenu();
        cin>>t;

        switch (t){

    case 1:
        addNewEmployee();
            break;

    case 2:
        deleteEmployee();
        break;

    case 3:
        updateEmployee();
        break;

    case 4:
        reportListOfEmployees();
        break;

    case 0:
        cout<<"Closing.........."<<endl;
        loadInFile();
        testing = false;
        break;

    default:
        cout<<"\nPogresan unos"<<endl;

        }
    }
}
