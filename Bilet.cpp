#pragma warning (disable:4996)
#include <iostream>
#include<crtdbg.h>
#include <fstream>
using namespace std;
//gestionarea biletelor unui film
class Bilet
{
private:
	const int idBilet;
	float pret;
	char* tip;

public:
	static int nrBilete;
	Bilet() : idBilet(nrBilete) {
		this->tip = new char[strlen("Necunoscut") + 1];
		strcpy(this->tip, "Necunoscut");
		this->pret = 0;
		nrBilete++;
	}

//constructor cu parametrii
	Bilet(int idBilet, float pretBilet, char* tipBilet) :idBilet(idBilet) {
		pret = pretBilet;
		tip = new char[strlen(tipBilet) + 1];
		strcpy(tip, tipBilet);
		nrBilete++;
	}

//getteri si setteri
	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0)
		{
			this->pret = pret;
		} 
		else {
			this->pret = 0;
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
	~Bilet()
	{
		if (this->tip != NULL)
			delete[]this->tip;
	}

//operator << - afisare
	friend ostream& operator<<(ostream& out, const Bilet& b) {
		out << b.idBilet << ", " << b.pret << ", " << b.tip << endl;
		return out;
	}

//operator >> -citire
	friend istream& operator>>(istream& in, Bilet& b) {
		if (b.tip != NULL)
		{
			delete[]b.tip;
		}
		cout << "Bilet: ";
		char x[10];
		in >> x;
		in.getline(x, 10);
		b.tip = new char[strlen(x) + 1];
		strcpy(b.tip, x);
		cout << "Pret bilet: ";
		in >> b.pret;
		return in;
	}

};
