#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>
#include <ios>
#include <limits>
#include <algorithm>
#include <fstream>

#include "person.h"
#include "funkcije.h"
#include "menu.h"

using namespace std;

it_company company; // Objekat strukture company

void printajMainMenu() {

    cout << "\n\t" << string(3, '*') << " MAIN MENU " << string(3, '*') << "\n\n";
	cout << " 1. Dodaj novog radnika!\n";
	cout << " 2. Izbrisi radnika iz sistema!\n";
	cout << " 3. Izmijeni informacije o radniku!\n";
	cout << " 4. Ispisi listu svih radnika!\n";
	cout << " 0. Sacuvaj izmjene i izadji!\n" <<endl;
	cout << "Vas unos: ";

}

void addNewEmployee(){

    vector<string>unos = unosKorisnika(1);
    int age = stoi(unos.at(2)); //funkcija stoi string to int

    company.employee  = person(unos.at(0), unos.at(1), age, unos.at(3), unos.at(4)); //pozivanje konstruktora
    company.listaFunkcija.addToEmployee(company.employee);
}

string testGodine(){
int godine;
	while (cin >> godine){
		if (godine <= 0 || godine >= MAX_AGE)
			cout << "Vrijeme za penziju!" << endl;
		else if (godine < MINIMAL_AGE && godine > 0)
			cout << "Nema 18 godina!" << endl;
		else
			return to_string(godine);
	}
	throw 0;

}

vector<string> unosKorisnika(const int& n) {
	string s;
	vector<string> unos;

	cout << "Ime: ";
	cin >> s;
	unos.push_back(s);

	cout << "Prezime: ";
	cin >> s;
	unos.push_back(s);

	cout << "Godine: ";
	s = testGodine(); //ogranicava godine
	unos.push_back(s);

	if (n == 1){
		cout << "JMBG: ";
		try {
			s = testJMBG();	//samo provjerava ogranicenja jmbg-a
			unos.push_back(s);
		} catch (int e) {
			if (e == 0)
				cout << "GRESKA!" << endl;
		}
	}

	cout << "Pozicija: ";
	cin.ignore();
	getline(cin, s, '\n');
	cin.clear();
    cin.sync();
	unos.push_back(s);

	return unos;
	//da bi smanjili ponavljanje koda u funkciji addEmployee ovdje pravimo funkciju koja to radi
	//vektor stringova koji ce sadrzavati nase osnovne informacije koje trebamo unijte
	//ovo koristim radi lakse kontrole kod update radnika
}

string testJMBG(){
	string jmbg;
	while (cin >> jmbg) {
		if (jmbg.size() == 13) {
        if (testJMBGallNum(jmbg))  {  //ovdje imamo funkciju koja testira da li su u jmbg upisani samo brojevi
        if (company.listaFunkcija.provjeriJMBG(jmbg)) //ovdje provjerava da li JMBG vec postoji
        return jmbg;
        else
                cout << "JMBG vec postoji!" <<endl;
        } else
				cout << "JMBG mora sadrzavati samo brojeve!" <<endl;
		} else
                cout << "JMBG mora imati 13 cifara!" <<endl;
	}
	throw 0;
}

bool testJMBGallNum(const string& temp) {
    return !temp.empty() && std::find_if(temp.begin(), temp.end(), [](unsigned char c) { return !isdigit(c); }) == temp.end();
    //funkcija koja testira da li su svi clanovi jmbga brojevi, preko lambde vraca vrijednost true or false

}

void deleteEmployee (){
    if (company.listaFunkcija.getEmployee().empty()){
        cout<<"\nLista je prazna"<<endl;
    }
    else {
    employee_it it = findPersonByJMBG();
    company.listaFunkcija.deleteFromEmployee (it);
    }
}

employee_it findPersonByJMBG () {
    string jmbg;
	cout << "Unesite JMBG osobje koju zelite pronaci: ";
	cin >> jmbg;
	employee_it it;
	try {
		it = company.listaFunkcija.findEmployee(jmbg);
	} catch (int e) {
		if (e == 0)
			std::cout << "Ne postoji osoba s tim jmbg!" << std::endl;
	}
	return it;
}

void updateEmployee(){
    cout << "\n\t" << string(15, '*') << " Izmijeni korisnika " << string(15, '*') << "\n\n";
	if (company.listaFunkcija.getEmployee().empty()){
        cout<<"\nLista je prazna";
	}
	else {employee_it it = findPersonByJMBG();
	vector<string> unos = unosKorisnika(0);
	company.listaFunkcija.updateEmp(it, unos);
	cout<<"\nUspjesno izmijenjene informacije o korisniku"<<endl;
    }
}

void printRadnika(vector<person> employee , ostream& output){

    for (auto it = employee.begin(); it != employee.end(); advance(it, 1)) {
		output << string(15, '-') << endl;
		output << "Ime: " << it->getName() <<endl;
		output << "Prezime: " << it->getSurname() <<endl;
		output << "Godine: " << it->getAge() <<endl;
		output << "JMBG: " << it->getJMBG() <<endl;
		output << "Pozicija: " << it->getDepartment() <<endl;
		output << string(15, '-') << endl;
	}
} //Funkcija za vizuelno printanje radnika na ekran te u fajl a proslijedjujemo je vektor koji trebamo printati

void reportListOfEmployees () {
    cout<<"\t\t"<<"Lista svih radnika"<<endl;
    vector<person> employees = company.listaFunkcija.getEmployee();
    if (!employees.empty()){
        printRadnika(employees, cout);
    }
    else {
        cout<<"\nU sistemu nema upisanih radnika"<<endl;
        return;
    }

}

void loadInFile(){
    ofstream file ("radnici.txt");
    vector<person> privremeni = company.listaFunkcija.getEmployee();
    printRadnika(privremeni, file);
}

void loadFromFile(){
person radnik;
ifstream file ("radnici.txt");
vector<string> nesto;
int age;
string linija;

while (getline(file, linija)){
    if (linija == string(15, '-'))
        continue;

    nesto=nekiRazmak(linija);
    if(nesto.at(0) == "Ime:")
        radnik.setName(nesto.at(1));

        else if (nesto.at(0) == "Prezime:")
			radnik.setSurname(nesto.at(1));

		else if (nesto.at(0) == "Godine:") {
			age = stoi(nesto.at(1));
			radnik.setAge(age);

		} else if (nesto.at(0) == "JMBG:")
			radnik.setJMBG(nesto.at(1));

		else if (nesto.at(0) == "Pozicija:") {
			for (auto it = nesto.begin() + 2; it != nesto.end(); advance(it, 1))
				nesto.at(1) += " " + *it;
        radnik.setDepartment(nesto.at(1));

        company.listaFunkcija.addToEmployee(radnik);
    }
} }


vector<string> nekiRazmak(string& unos) {
	istringstream iss(unos);
	vector<string> p(istream_iterator<string>{iss}, istream_iterator<string>());
	return p;
}
