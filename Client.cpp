#pragma warning (disable:4996)
#include <iostream>
#include<crtdbg.h>
using namespace std;

class Client
{
private:
	const int idClient;
	char* nume;
	char* prenume;
	int varsta;

public:
	static int nrClienti;
	Client() : idClient(nrClienti) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->prenume = new char[strlen("PAnonim") + 1];
		strcpy(this->prenume, "PAnonim");
		this->varsta = 0;
		nrClienti++;
	}

	Client(int idClient, char* numeClient, char* prenumeClient, int varstaClient) :idClient(idClient) {
		nume = new char[strlen(numeClient) + 1];
		strcpy(nume, numeClient);
		prenume = new char[strlen(prenumeClient) + 1];
		strcpy(prenume, prenumeClient);
		varsta = varstaClient;
		nrClienti++;
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

	char* getPrenume() {
		return this->prenume;
	}
	void setPrenume(const char* prenume) {
		if (this->prenume != NULL)
		{
			delete[]this->prenume;
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsya(int varsta) {
		if(varsta>0)
		{
			this->varsta = varsta;
		}
		else {
			this->varsta = 0;
		}
	}

//destructor
	~Client() {
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}

		if (this->prenume != NULL)
		{
			delete[]this->prenume;
		}
	}

//operator << -afisare
	friend ostream& operator<<(ostream& out, const Client& c) {
		out << c.idClient << ", " << c.nume << ", " << c.prenume << ", " << c.varsta << endl;
		return out;
	}

//operator >> -citire
	friend istream& operator>>(istream& in, Client& c) {
		if (c.nume != NULL)
		{
			delete[]c.nume;
		}
		cout << "Nume: ";
		char n[20];
		in >> n;
		in.getline(n, 20);
		c.nume = new char[strlen(n) + 1];
		strcpy(c.nume, n);

		if (c.prenume != NULL)
		{
			delete[]c.prenume;
		}
		cout << "Prenume: ";
		char p[20];
		in >> p;
		in.getline(p, 20);
		c.prenume = new char[strlen(p) + 1];
		strcpy(c.prenume, p);

		cout << "Varsta: ";
		in >> c.varsta;
		return in;
	}

};
