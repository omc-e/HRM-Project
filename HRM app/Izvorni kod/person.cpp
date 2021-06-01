#include <iostream>
#include <string>
#include "person.h"

person::person(){

}

person::person(string name, string surname, int age, string jmbg, string department)
: ime(name), prezime (surname), godine (age), jmbg (jmbg), department (department)
{

}

person::~person(){

}

void person::setName(string ime) {
	this->ime = ime;
}

void person::setSurname(string prezime) {
	this->prezime = prezime;
}

void person::setAge(int godine) {
	this->godine = godine;
}

string person::getName() {
	return this->ime;
}

string person::getSurname() {
	return this->prezime;
}

int person::getAge() {
	return this->godine;
}

void person::setJMBG(string jmbg){
    this->jmbg = jmbg;
}

string person::getJMBG(){
    return this->jmbg;
}

void person::setDepartment (string department){
    this->department = department;
}

string person::getDepartment (){
    return this->department;
}
