#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <ostream>
#include <vector>

#include "funkcije.h"
#include "person.h"

using namespace std;

const int MINIMAL_AGE = 18;
const int MAX_AGE = 65; //valjda u 65. godini ide u penziju

struct it_company {

    funkcije listaFunkcija;
    person employee;
};


        //glavne funkcije menua
        void printajMainMenu(); // ***
        void addNewEmployee();  //***
        void deleteEmployee();
        void reportListOfEmployees();
        void updateEmployee();


        //dodatne funkcije menua
        void printRadnika(vector<person> , ostream&);
        vector<person> findEmployee();
        string testJMBG();; //***
        bool testJMBGallNum(const string&); //***
        employee_it findPersonByJMBG ();
        vector<string> unosKorisnika(const int& n);
        string testGodine();
        void loadFromFile();
        void loadInFile();
        vector<string> nekiRazmak(string&); //NE DIRAJ!!! RADI!!!

#endif // MENU_H
