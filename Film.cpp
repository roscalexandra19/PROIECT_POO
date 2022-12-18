#pragma warning (disable:4996)
#include <iostream>
#include<crtdbg.h>
using namespace std;

class Film
{
private:
	const int idFilm;
	char* nume;
	char* tip;

public:
	static int nrFilme;
	Film() : idFilm(nrFilme) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->tip = new char[strlen("NECUNOSCUT") + 1];
		strcpy(this->tip, "NECUNOSCUT");
		nrFilme++;
	}

	//constructori cu parametrii
	Film(int idFilm, char* numeFilm, char* tipFilm) :idFilm(idFilm) {
		nume = new char[strlen(numeFilm) + 1];
		strcpy(nume, numeFilm);
		tip = new char[strlen(tipFilm) + 1];
		strcpy(tip, tipFilm);
		nrFilme++;
	}

	//getteri si setteri
	char* getNume() {
		return this->nume;
	}
	void setNume(const char* nume) {
		if (this->nume != NULL)
		{
			delete[]this->nume;
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}

	char* getTip() {
		return this->tip;
	}

	void setTip(char* tip) {
		if (this->tip != NULL)
		{
			delete[]this->tip;
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
		}
	}

	//destructor
	~Film() {
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}

		if (this->tip != NULL)
		{
			delete[]this->tip;
		}
	}

//operator << -afisare
	friend ostream& operator<<(ostream& out, const Film& f) {
		out << f.idFilm << ", " << f.nume << ", " << f.tip << endl;
	}

//operator >> -citire
	friend istream& operator>>(istream& in, Film& f) {
		if (f.nume != NULL)
		{
			delete[]f.nume;
		}
		cout << "Nume: ";
		char y[100];
		in >> y;
		in.getline(y, 100);
		f.nume = new char[strlen(y) + 1];
		strcpy(f.nume, y);

		if (f.tip != NULL)
		{
			delete[]f.tip;
		}
		cout << "Tip: ";
		char z[100];
		in >> z;
		in.getline(z, 100);
		f.tip = new char[strlen(z) + 1];
		strcpy(f.tip, z);
		return in;
	}

};
