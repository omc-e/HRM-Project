#include <iterator>
#include <vector>
#include <string>

#include "person.h"
#include "funkcije.h"

using namespace std;

funkcije::funkcije(){

}
funkcije::~funkcije(){

}
void funkcije::addToEmployee(const person& employee) {
	this->employee.push_back(employee);
}

employee_it funkcije::findEmployee(string& jmbg) {
	for (auto it = this->employee.begin(); it != this->employee.end(); advance(it, 1))
		if (it->getJMBG() == jmbg)
			return it;
        throw 0;
}


void funkcije::deleteFromEmployee(employee_it it) {
	it = this->employee.erase(it);
}


vector<person> funkcije::getEmployee() {
	return this->employee;
}

bool funkcije::provjeriJMBG (string& jmbg) {
for (auto it = this->employee.begin(); it != this->employee.end(); std::advance(it, 1))
		if (it->getJMBG() == jmbg)
			return false;
	return true;
}

employee_it funkcije::posljedniClan(){
    return prev(employee.end());
    //kako sam ja skontao prev funkcija vraca iterator za broj mjesta koji zadamo ali krece s kraja
    //tako da ako samo stavimo employee.end bez da mu zadamo koliko mjesta se pomjera
    //vracat ce posljedni element
}

void funkcije::updateEmp(employee_it& it, vector<string>& unos){
    if (unos.at(0) != "0")
            it->setName(unos.at(0));

	if (unos.at(1) != "0")
            it->setSurname(unos.at(1));

	if (unos.at(2) != "0")
            it->setAge(stoi(unos.at(2))); //funkcija stoi za konvertovanje

	if (unos.at(3) != "0")
            it->setDepartment(unos.at(3));

	return;


}
