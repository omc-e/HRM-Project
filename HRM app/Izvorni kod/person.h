#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class person {
	private:
		string ime;
		string prezime;
		int godine;
		string jmbg;
		string department;

	public:
	    person();
	    person (string name, string surname, int age, string jmbg, string department);
	    ~person();
		void setName(string ime);
		void setSurname(string prezime);
		void setAge(int godine);
		void setJMBG (string jmbg);
		void setDepartment (string department);
		string getName();
		string getSurname();
		int getAge();
		string getJMBG();
		string getDepartment ();
};

#endif // PERSON_H
