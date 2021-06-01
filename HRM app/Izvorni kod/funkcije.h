#ifndef FUNKCIJE_H
#define FUNKCIJE_H


#include <vector>
#include <string>

#include "person.h"
using namespace std;

typedef vector<person>::iterator employee_it;

class funkcije {
	private:
            vector<person> employee;
	public:
            funkcije();
            ~funkcije();
            void addToEmployee(const person&); //dodaje
            employee_it findEmployee(string&); //vraca iterator sa trazenim element
            void deleteFromEmployee(employee_it); //brise trazeni element
            vector<person> getEmployee(); //funkcija koja vraca vektor employee
            bool provjeriJMBG (string& jmbg); //provjerava da li postoji vec neka osoba s tim jmbg-om
            void updateEmp(employee_it&, vector<string>&); //funkcija za izmjenu informacija o clanu vektora
            employee_it posljedniClan (); //funkcija koja vraca iterator na posljedni clan vektora
};


#endif // FUNKCIJE_H
