#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
/*
GESTIUNE UNEI FIRME DE IMOBILIARE BY ALEXANDRU EPURESCU 1052
*/

enum tipPlata {
	Neprecizat = 0, plataTransfer = 1, plataCash = 2, plataMix = 3, plataPrinCreditBancar = 4
};

class Imobil
{
	const int idImobil;
	string orasImobil;
	char* adresaImobil;
	char cartier[100];
	float mpImobil;//preferinta
	int anConstructieImobil;//preferinta
	int nrCamere;//preferinta
	float* mpCamere;
	float pretImobil;//preferinta
	//alte pref
	bool areCentrala;//preferinta
	float distantaMetrou;//preferinta
public:
	//Constructor fara parametrii pentru Clasa Imobil
	Imobil() :idImobil(0000)
	{
		this->orasImobil = "Necunoscut";
		this->adresaImobil = new char[strlen("Necunoscut") + 1];
		strcpy(this->adresaImobil, "Necunoscut");
		strcpy(this->cartier, "Necunoscut");
		this->mpImobil = 0;
		this->anConstructieImobil = 0;
		this->nrCamere = 0;
		this->mpCamere = NULL;
		this->areCentrala = 0;
		this->distantaMetrou = 0;
		this->pretImobil = 0;
	}
	//Constructor cu toti parametrii pentru Clasa Imobil
	Imobil(int idImobil, string orasImobil, const char* adresaImobil, const char cartier[100], float mpImobil, int anConstructieImobil, int nrCamere, float* mpCamere, bool areCentrala, float distantaMetrou, float pretImobil) :idImobil(idImobil)
	{
		this->orasImobil = orasImobil;
		this->adresaImobil = new char[strlen(adresaImobil) + 1];
		strcpy(this->adresaImobil, adresaImobil);
		strcpy(this->cartier, cartier);
		this->mpImobil = mpImobil;
		this->anConstructieImobil = anConstructieImobil;
		this->nrCamere = nrCamere;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->mpCamere[i] = mpCamere[i];
		this->areCentrala = areCentrala;
		this->distantaMetrou = distantaMetrou;
		this->pretImobil = pretImobil;
	}
	//Void afisare pentru Imobil
	void afisare()
	{
		cout << endl << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << endl;
		cout << "Id imobil: " << this->idImobil << endl;
		cout << "Orasul: " << this->orasImobil << endl;
		cout << "Adresa: " << this->adresaImobil << endl;
		cout << "Cartier: " << this->cartier << endl;
		cout << "Suprafata: " << this->mpImobil << "mp" << endl;
		cout << "An constructie: " << this->anConstructieImobil << endl;
		cout << "Numar camere: " << this->nrCamere << endl;
		cout << "Suprafata camerelor: " << endl;
		for (int i = 0; i < this->nrCamere; i++)
			cout << this->mpCamere[i] << "mp, ";
		cout << endl;
		cout << "Are centrala (0=NU / 1=DA): " << this->areCentrala << endl;
		cout << "Distanta pana la cel mai apropiat metrou: " << this->distantaMetrou << "m" << endl;
		cout << "Pret: " << this->pretImobil << "$" << endl;
		cout << endl << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"<<endl << endl;
	}

	//Geteri pentru atributele din clasa Imobil
	int getIdImobil()
	{
		return this->idImobil;
	}
	string getOrasImobil()
	{
		return this->orasImobil;
	}
	char* getAdresaImobil()
	{
		return this->adresaImobil;
	}
	string getCartier()
	{
		return this->cartier;
	}
	float getMpImobil()
	{
		return this->mpImobil;
	}
	int getAnConstructieImobil()
	{
		return this->anConstructieImobil;
	}
	int getNrCamere()
	{
		return this->nrCamere;
	}
	float* getMpCamere()
	{
		return this->mpCamere;
	}
	float getPretImobil()
	{
		return this->pretImobil;
	}
	bool getAreCentrala()
	{
		return this->areCentrala;
	}
	float getDistantaMetrou()
	{
		return this->distantaMetrou;
	}

	//Seteri pentru atributele din clasa Imobil
	void setOrasImobil(string orasImobil)
	{
		if (size(orasImobil) >= 3)
			this->orasImobil = orasImobil;
		else
			cout << endl << "Oras introdus invalid !";
	}
	void setAdresaImobil(const char* adresaImobil)
	{
		if (strlen(adresaImobil) >= 4)
			this->adresaImobil = new char[strlen(adresaImobil) + 1];
		strcpy(this->adresaImobil, adresaImobil);

	}
	void setCartier(const char cartier[100])
	{
		if (strlen(cartier) >= 3)
			strcpy(this->cartier, cartier);
		else
			cout << endl << "Cartier introdus invalid !";
	}
	void setMpImobil(float mpImobil)
	{
		if (mpImobil > 0)
			this->mpImobil = mpImobil;
		else
			cout << endl << "Mp introdusi invalizi !";
	}
	void setAnConstructieImobil(int anConstructieImobil)
	{
		if (anConstructieImobil > 0 && anConstructieImobil <= 2022)
			this->anConstructieImobil = anConstructieImobil;
		else
			cout << endl << "An constructie introdus invalid !";
	}
	void setMpCamere(int nrCamere, float* mpCamere)
	{
		int suma = 0;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
		this->nrCamere = nrCamere;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
		{
			this->mpCamere[i] = mpCamere[i];
			suma = suma + this->mpCamere[i];
		}
		if (suma > this->mpImobil)
			cout << endl << "Mp ai camerelor au fost introdusi eronat!";
	}
	void setPretImobil(float pretImobil)
	{
		if (pretImobil > 0 && pretImobil / 10000 >= 1)
			this->pretImobil = pretImobil;
		else
			cout << endl << "Verificati numarul de zero-uri";
	}
	void setAreCentrala(bool areCentrala)
	{
		if (areCentrala == 0)
			cout << "Bafta la iarna!";
		this->areCentrala = areCentrala;
	}
	void setDistantaMetrou(float distantaMetrou)
	{
		if (distantaMetrou > 0)
			this->distantaMetrou = distantaMetrou;
	}

	//adauga o noua camera la imobil si o pune pe prima pozitie
	void adaugareCamPrimaPoz(float mpCamera)
	{
		Imobil copie = *this;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
		this->nrCamere = this->nrCamere + 1;
		this->mpCamere = new float[this->nrCamere + 1];
		this->mpCamere[0] = mpCamera;
		for (int i = 0; i < this->nrCamere; i++)
		{
			this->mpCamere[i+1] = copie.mpCamere[i];
		}
	}

	//Constructor de copiere pentru clasa Imobil
	Imobil(const Imobil& im) :idImobil(im.idImobil)
	{
		this->orasImobil = im.orasImobil;
		this->adresaImobil = new char[strlen(im.adresaImobil) + 1];
		strcpy(this->adresaImobil, im.adresaImobil);
		strcpy(this->cartier, im.cartier);
		this->mpImobil = im.mpImobil;
		this->anConstructieImobil = im.anConstructieImobil;
		this->nrCamere = im.nrCamere;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->mpCamere[i] = im.mpCamere[i];
		this->areCentrala = im.areCentrala;
		this->distantaMetrou = im.distantaMetrou;
		this->pretImobil = im.pretImobil;
	}
	//Operator= pentru clasa imobil
	Imobil& operator=(const Imobil& im)
	{
		if (this != &im)
		{
			if (this->adresaImobil != NULL)
				delete[]this->adresaImobil;
			if (this->mpCamere != NULL)
				delete[]this->mpCamere;
			this->orasImobil = im.orasImobil;
			this->adresaImobil = new char[strlen(im.adresaImobil) + 1];
			strcpy(this->adresaImobil, im.adresaImobil);
			strcpy(this->cartier, im.cartier);
			this->mpImobil = im.mpImobil;
			this->anConstructieImobil = im.anConstructieImobil;
			this->nrCamere = im.nrCamere;
			this->mpCamere = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
				this->mpCamere[i] = im.mpCamere[i];
			this->areCentrala = im.areCentrala;
			this->distantaMetrou = im.distantaMetrou;
			this->pretImobil = im.pretImobil;
		}
		return *this;
	}
	//cout<<i1;
	//Operator ostream<< pentru clasa Imobil
	friend ostream& operator<<(ostream& out, const Imobil& im)
	{
		out << endl << "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii" << endl;
		out << "Id imobil: " << im.idImobil << endl;
		out << "Orasul: " << im.orasImobil << endl;
		out << "Adresa: " << im.adresaImobil << endl;
		out << "Cartier: " << im.cartier << endl;
		out << "Suprafata: " << im.mpImobil << "mp" << endl;
		out << "An constructie: " << im.anConstructieImobil << endl;
		out << "Numar camere: " << im.nrCamere << endl;
		out << "Suprafata camerelor: " << endl;
		for (int i = 0; i < im.nrCamere; i++)
			out << im.mpCamere[i] << "mp, ";
		out << endl;
		out << "Are centrala (0=NU / 1=DA): " << im.areCentrala << endl;
		out << "Distanta pana la cel mai apropiat metrou: " << im.distantaMetrou << "m" << endl;
		out << "Pret: " << im.pretImobil << "$" << endl;
		out << endl << "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii" << endl;
		return out;
	}
	//cin>>i3;
	//Operator istream>> pentru clasa Imobil
	friend istream& operator>>(istream& in, Imobil& im)
	{
		cout << "Orasul: ";
		in >> ws;//pus ca sa dea clear inainte si sa poata citi cum trebuie
		getline(in, im.orasImobil);

		cout << "Adresa: ";
		if (im.adresaImobil != NULL)
			delete[]im.adresaImobil;
		char buffer[200];
		in >> ws;
		in.getline(buffer, 199);
		im.adresaImobil = new char[strlen(buffer) + 1];
		strcpy(im.adresaImobil, buffer);
		cout << "Cartier: ";
		char buffer1[100];
		in >> ws;
		in.getline(buffer1, 99);
		strcpy(im.cartier, buffer1);
		cout << "Suprafata: ";
		in >> im.mpImobil;
		cout << "An constructie: ";
		in >> im.anConstructieImobil;
		cout << "Numar camere: ";
		in >> im.nrCamere;
		cout << "Suprafata camerelor: " << endl;
		if (im.mpCamere != NULL)
			delete[]im.mpCamere;
		im.mpCamere = new float[im.nrCamere];
		for (int i = 0; i < im.nrCamere; i++)
			in >> im.mpCamere[i];
		cout << endl;
		cout << "Are centrala (0=NU / 1=DA): ";
		in >> im.areCentrala;
		cout << "Distanta pana la cel mai apropiat metrou: ";
		in >> im.distantaMetrou;
		cout << "Pret: ";
		in >> im.pretImobil;
		return in;
	}
	//Operator[] ce ne spune dimensiunea camerei indicate
	float& operator[](int pozitie) {
		if (pozitie > 0 && pozitie <= this->nrCamere)
		{
			return this->mpCamere[pozitie];
		}
		else
			cout << "Camera data nu exista in acest Imobil ";
	}
	//Operator+ ce adauga o camera si dimensiunea sa e data ca parametru
	Imobil operator+(float valoare)
	{
		Imobil copie = *this;
		if (copie.mpCamere != NULL)
			delete[]copie.mpCamere;
		copie.nrCamere++;
		copie.mpCamere = new float[copie.nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			copie.mpCamere[i] = this->mpCamere[i];
		copie.mpCamere[copie.nrCamere - 1] = valoare;
		return copie;
	}
	Imobil& operator++()
	{//adauga inca o camera la imobil si ia valoare ultimei camere;
		Imobil copie = *this;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
		this->nrCamere++;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->mpCamere[i] = copie.mpCamere[i];
		this->mpCamere[this->nrCamere - 1] = copie.mpCamere[copie.nrCamere - 1];
		return *this;
	}
	Imobil& operator++(int)
	{//adauga inca o camera la imobil si ia valoare ultimei camere;
		Imobil copie = *this;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
		this->nrCamere++;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->mpCamere[i] = copie.mpCamere[i];
		this->mpCamere[this->nrCamere - 1] = copie.mpCamere[copie.nrCamere - 1];
		return copie;
	}

	Imobil& operator--()
	{//sterge o camera din imobil
		Imobil copie = *this;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
		this->nrCamere--;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->mpCamere[i] = copie.mpCamere[i];
		return *this;
	}
	Imobil& operator--(int)
	{//sterge o camera din imobil
		Imobil copie = *this;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
		this->nrCamere--;
		this->mpCamere = new float[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++)
			this->mpCamere[i] = copie.mpCamere[i];
		return copie;
	}
	bool operator!()
	{
		if (this->areCentrala == true)
		{
			this->areCentrala = false;
			return true;
		}
		if (this->areCentrala == false)
		{
			this->areCentrala = true;
			return false;
		}
	}
	explicit operator string()
	{
		return this->cartier;
	}
	explicit operator float()
	{
		return this->pretImobil;
	}
	~Imobil()
	{
		if (this->adresaImobil != NULL)
			delete[]this->adresaImobil;
		if (this->mpCamere != NULL)
			delete[]this->mpCamere;
	}
	//fisiere text
	//operatorul << (de afisare)
	friend ofstream& operator<<(ofstream& out, const Imobil& im)
	{
		out << im.orasImobil << endl;
		out << im.adresaImobil << endl;
		out << im.cartier << endl;
		out << im.mpImobil << endl;
		out << im.anConstructieImobil << endl;
		out << im.nrCamere << endl;
		for (int i = 0; i < im.nrCamere; i++)
			out << im.mpCamere[i];
		out << endl;
		out << im.areCentrala << endl;
		out << im.distantaMetrou << endl;
		out << im.pretImobil << endl;
		return out;
	}
	//operatorul >> (de citire)
	friend ifstream& operator>>(ifstream& in, Imobil& im)
	{
		in >> ws;//pus ca sa dea clear inainte si sa poata citi cum trebuie
		getline(in, im.orasImobil);
		if (im.adresaImobil != NULL)
			delete[]im.adresaImobil;
		char buffer[200];
		in >> ws;
		in.getline(buffer, 199);
		im.adresaImobil = new char[strlen(buffer) + 1];
		strcpy(im.adresaImobil, buffer);
		char buffer1[100];
		in >> ws;
		in.getline(buffer1, 99);
		strcpy(im.cartier, buffer1);
		in >> im.mpImobil;
		in >> im.anConstructieImobil;
		in >> im.nrCamere;
		if (im.mpCamere != NULL)
			delete[]im.mpCamere;
		im.mpCamere = new float[im.nrCamere];
		for (int i = 0; i < im.nrCamere; i++)
			in >> im.mpCamere[i];
		in >> im.areCentrala;
		in >> im.distantaMetrou;
		in >> im.pretImobil;
		return in;
	}

	//fisiere CSV
	//de facut sa avem o baza de date pentru fiecare
	void exportCSV(string nume)
	{
		ofstream f(nume, ios::out);
		f << this->orasImobil << ",";
		f << this->adresaImobil << ",";
		f << this->cartier << ",";
		f << this->mpImobil << ",";
		f << this->anConstructieImobil << ",";
		f << this->nrCamere << ",";
		for (int i = 0; i < this->nrCamere; i++)
			f << this->mpCamere[i]<< ",";
		f << this->areCentrala << ",";
		f << this->distantaMetrou << ",";
		f << this->pretImobil << endl;
		f.close();
	}

	void importCSV(string nume)
	{
		
		ifstream g(nume, ios::in);
		if (g.is_open())
		{
			//string
			getline(g, this->orasImobil, ',');
			//char*
			char aux[200];
			g.getline(aux, 199, ',');
			if (this->adresaImobil != NULL)
			{
				delete[]this->adresaImobil;
			}
			this->adresaImobil = new char[strlen(aux) + 1];
			strcpy(this->adresaImobil, aux);

			//char
			g.getline(this->cartier, 99, ',');
			//int/float
			/*string buffer1;
			getline(g, buffer1, ',');
			this->mpImobil = stof(buffer1);*/
			//string buffer2;
			//getline(g, buffer2, ',');
			//this->anConstructieImobil = stoi(buffer2);
			//string buffer3;
			//getline(g, buffer3, ',');
			//this->nrCamere = stoi(buffer3);
			//
			////float*
			//if (this->mpCamere != NULL)
			//	delete[]this->mpCamere;
			//this->mpCamere = new float[this->nrCamere];
			//for(int i=0;i<this->nrCamere;i++)
			//{
			//	string buffer4;
			//	getline(g, buffer4, ',');
			//	this->mpCamere[i] = stoi(buffer4);
			//}
			//
			////float 
			//string buffer5;
			//getline(g, buffer5, ',');
			//this->pretImobil = stof(buffer5);
			//string buffer6;
			//getline(g, buffer6, ',');
			//this->areCentrala = stoi(buffer6);
			//string buffer7;
			//getline(g, buffer7, ',');
			//this->distantaMetrou = stof(buffer7);
		}
		else
			cout << endl << "Fisierul nostru NO exista!";
	}

	//fisiere binare
	void scriereBIN(string nume)
	{
		ofstream f(nume, ios::out | ios::binary);
		//string
		int dimOras = this->orasImobil.size();
		f.write((char*)&dimOras, sizeof(dimOras));
		f.write(this->orasImobil.c_str(), dimOras + 1);
		//char*
		int dimAdresa = strlen(this->adresaImobil);
		f.write((char*)&dimAdresa, sizeof(dimAdresa));
		f.write(this->adresaImobil, dimAdresa + 1);
		//char
		f.write((char*) & this->cartier, sizeof(this->cartier));
		//pt numerice+bool
		f.write((char*)&this->mpImobil, sizeof(this->mpImobil));
		f.write((char*)&this->anConstructieImobil, sizeof(this->anConstructieImobil));
		f.write((char*)&this->nrCamere, sizeof(this->nrCamere));
		for(int i=0;i<this->nrCamere;i++)
			{
				f.write((char*)&this->mpCamere[i], sizeof(this->mpCamere[i]));
			}
		f.write((char*)&this->pretImobil, sizeof(this->pretImobil));
		f.write((char*)&this->areCentrala, sizeof(this->areCentrala));
		f.write((char*)&this->distantaMetrou, sizeof(this->distantaMetrou));

	}

	void citireBIN(string nume)
	{
		ifstream g(nume, ios::in | ios::binary);
		if (g.is_open())
		{
			//string
			int dimOras = 0;
			g.read((char*)&dimOras, sizeof(dimOras));
			char* aux = new char[dimOras + 1];
			g.read(aux, dimOras + 1);
			this->orasImobil = aux;
			delete[]aux;
			//char*
			if(this->adresaImobil !=NULL)
			{
				delete[]this->adresaImobil;
			}
				int dimAdresa = 0;
				g.read((char*)&dimAdresa, sizeof(dimAdresa));
				this->adresaImobil = new char[dimAdresa + 1];
				g.read(this->adresaImobil, dimAdresa + 1);
			//char
			g.read((char*)&this->cartier, sizeof(this->cartier));
			//pt numerice+bool
			g.read((char*)&this->mpImobil, sizeof(this->mpImobil));
			g.read((char*)&this->anConstructieImobil, sizeof(this->anConstructieImobil));
			g.read((char*)&this->nrCamere, sizeof(this->nrCamere));
			if (this->mpCamere != NULL)
			{
				delete[]this->mpCamere;
			}
			this->mpCamere = new float[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++)
			{
				g.read((char*)&this->mpCamere[i], sizeof(this->mpCamere[i]));
			}
			g.read((char*)&this->pretImobil, sizeof(this->pretImobil));
			g.read((char*)&this->areCentrala, sizeof(this->areCentrala));
			g.read((char*)&this->distantaMetrou, sizeof(this->distantaMetrou));
		}
		else
			cout << "Fisierul pe care il vrem doesen't exist!" << endl;

	}
	bool operator<(Imobil im) const {
		if (this->cartier == im.cartier)
		{
			return strcmp(this->cartier, im.cartier) == -1;
		}
		else
		{
			return this->cartier < im.cartier;
		}
	}
};

class bonusAgentiClsAbs {
protected:
	float valBonus;
public:
	virtual void bonusVechime(int nrAniVechime) = 0;
};

class Agent:public bonusAgentiClsAbs
{
protected:
	const int idAgent;
	static int numarator;
	char* nume;
	char prenume[50];
	int aniExperienta;
	int nrVanzariPrecedente;
	float* valoareVanzari;
	float salariuDeBaza;
	bool esteAcreditat;
public:
	Agent() :idAgent(numarator++)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		strcpy(this->prenume, "Anonim");
		this->aniExperienta = 0;
		this->nrVanzariPrecedente = 0;
		this->valoareVanzari = NULL;
		this->salariuDeBaza = 0;
		this->esteAcreditat = 0;
	}

	Agent(const char* nume, const char prenume[50], int aniExperienta, int nrVanzariPrecedente, float* valoareVanzari, float salariuDeBaza, bool esteAcreditat) :idAgent(numarator++)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		strcpy(this->prenume, prenume);
		this->aniExperienta = aniExperienta;
		this->nrVanzariPrecedente = nrVanzariPrecedente;
		this->valoareVanzari = new float[this->nrVanzariPrecedente];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			this->valoareVanzari[i] = valoareVanzari[i];
		this->salariuDeBaza = salariuDeBaza;
		this->esteAcreditat = esteAcreditat;
	}

	void afisare()
	{
		cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		cout << "Id agent: " << this->numarator << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Prenume: " << this->prenume << endl;
		cout << "Ani de experienta: " << this->aniExperienta << " ani" << endl;
		cout << "Numar de vanzari precedente: " << this->nrVanzariPrecedente << endl;
		cout << "Valoarea vanzarilor precedente: " << endl;
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			cout << this->valoareVanzari[i] << "$, ";
		cout << endl;
		cout << "Salariu de baza: " << this->salariuDeBaza << "$" << endl;
		cout << "Este acreditat (0=NU / 1=DA): " << this->esteAcreditat << endl;
		cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
	}
	//Geteri
	int getIdAgent()
	{
		return this->numarator;
	}
	char* getNume()
	{
		return this->nume;
	}
	string getPrenume()
	{
		return this->prenume;
	}
	int getAniExperienta()
	{
		return this->aniExperienta;
	}
	int getNrVanzariPrecedente()
	{
		return this->nrVanzariPrecedente;
	}
	float* getValoareVanzari()
	{
		return this->valoareVanzari;
	}
	float getSalariuDeBaza()
	{
		return this->salariuDeBaza;
	}
	bool getEsteAcreditat()
	{
		return this->esteAcreditat;
	}
	//Seteri
	void setNume(const char* nume)
	{
		if (this->nume != NULL)
			delete[]this->nume;
		if (strlen(nume) >= 1)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else cout << endl << "Nume invalid";
	}
	void setPrenume(const char prenume[50])
	{
		if (strlen(nume) >= 1)
		{
			strcpy(this->prenume, prenume);
		}
		else cout << endl << "Prenume invalid";
	}
	void setAniExperienta(int aniExperienta)
	{
		if (aniExperienta <= 70)
			this->aniExperienta = aniExperienta;
		else cout << endl << "Ani de experinta introdusi invalizi";
	}

	void setValoareVanzari(int nrVanzariPrecedente, float* valoareVanzari)
	{
		this->nrVanzariPrecedente = nrVanzariPrecedente;
		if (this->valoareVanzari != NULL)
			delete[]this->valoareVanzari;
		this->valoareVanzari = new float[this->nrVanzariPrecedente];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			this->valoareVanzari[i] = valoareVanzari[i];
	}
	void setSalariuDeBaza(float salariuDeBaza)
	{
		if (salariuDeBaza > 0 && salariuDeBaza / 10000 < 1)
			this->salariuDeBaza = salariuDeBaza;
		else cout << endl << "Salariul introdus este gresit";
	}
	void setEsteAcreditat(bool esteAcreditat)
	{
		this->esteAcreditat = esteAcreditat;
	}

	Agent(const Agent& a) :idAgent(a.numarator)
	{
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		strcpy(this->prenume, a.prenume);
		this->aniExperienta = a.aniExperienta;
		this->nrVanzariPrecedente = a.nrVanzariPrecedente;
		this->valoareVanzari = new float[this->nrVanzariPrecedente];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			this->valoareVanzari[i] = a.valoareVanzari[i];
		this->salariuDeBaza = a.salariuDeBaza;
		this->esteAcreditat = a.esteAcreditat;
	}

	Agent& operator=(const Agent& a)
	{
		if (this != &a)
		{
			if (this->nume != NULL)
				delete[]this->nume;
			if (this->valoareVanzari != NULL)
				delete[]this->valoareVanzari;
			this->nume = new char[strlen(a.nume) + 1];
			strcpy(this->nume, a.nume);
			strcpy(this->prenume, a.prenume);
			this->aniExperienta = a.aniExperienta;
			this->nrVanzariPrecedente = a.nrVanzariPrecedente;
			this->valoareVanzari = new float[this->nrVanzariPrecedente];
			for (int i = 0; i < this->nrVanzariPrecedente; i++)
				this->valoareVanzari[i] = a.valoareVanzari[i];
			this->salariuDeBaza = a.salariuDeBaza;
			this->esteAcreditat = a.esteAcreditat;
		}
		return *this;
	}
	//cout << a1;
	friend ostream& operator<<(ostream& out, const Agent& a)
	{
		out <<endl<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
		out << "Id agent: " << a.idAgent << endl;
		out << "Nume: " << a.nume << endl;
		out << "Prenume: " << a.prenume << endl;
		out << "Ani de experienta: " << a.aniExperienta << " ani" << endl;
		out << "Numar de vanzari precedente: " << a.nrVanzariPrecedente << endl;
		out << "Valoarea vanzarilor precedente: " << endl;
		for (int i = 0; i < a.nrVanzariPrecedente; i++)
			out << a.valoareVanzari[i] << "$, ";
		out << endl;
		out << "Salariu de baza: " << a.salariuDeBaza << "$" << endl;
		out << "Este acreditat (0=NU / 1=DA): " << a.esteAcreditat << endl;
		return out;
		out <<endl<< "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
	}
	//cin >> a1;
	friend istream& operator>>(istream& in, Agent& a)
	{

		cout << "Nume: ";
		if (a.nume != NULL)
			delete[]a.nume;
		char buffer[100];
		in.getline(buffer, 99);
		a.nume = new char[strlen(buffer) + 1];
		strcpy(a.nume, buffer);
		cout << "Prenume: ";
		char buffer1[50];
		in.getline(buffer1, 49);
		strcpy(a.prenume, buffer1);
		cout << "Ani de experienta: ";
		in >> a.aniExperienta;
		cout << "Numar de vanzari precedente: ";
		in >> a.nrVanzariPrecedente;
		cout << "Valoarea vanzarilor precedente: ";
		if (a.valoareVanzari != NULL)
			delete[]a.valoareVanzari;
		a.valoareVanzari = new float[a.nrVanzariPrecedente];
		for (int i = 0; i < a.nrVanzariPrecedente; i++)
			in >> a.valoareVanzari[i];
		cout << endl;
		cout << "Salariu de baza: ";
		in >> a.salariuDeBaza;
		cout << "Este acreditat (0=NU / 1=DA): ";
		in >> a.esteAcreditat;
		return in;
	}
	//a1[2]=30000
	//operator cast care ne spune valaore unei vanzari din portofoliul agentului
	float& operator[](int pozitie) {
		if (pozitie > 0 && pozitie <= this->nrVanzariPrecedente)
		{
			return this->valoareVanzari[pozitie];
		}
		else
			cout << "Vanzarea introdusa nu exista";
	}
	//a1+20000
	//operator de adaugare care adauga o noua vanzare in portofoliul agentului
	Agent operator+(float valoare)
	{
		Agent copie = *this;
		if (copie.valoareVanzari != NULL)
			delete[]copie.valoareVanzari;
		copie.nrVanzariPrecedente++;
		copie.valoareVanzari = new float[copie.nrVanzariPrecedente];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			copie.valoareVanzari[i] = this->valoareVanzari[i];
		copie.valoareVanzari[copie.nrVanzariPrecedente - 1] = valoare;
		return copie;
	}
	Agent& operator++()
	{//adauga inca o vanzare in portofoliul agentului si ia valoare SI VALOAREA ACESTEIA ESTE VALAORE MEDIE A VANZARILOR PRECEDENTE;
		Agent copie = *this;
		float suma = 0;
		float valoare = 0;
		if (this->valoareVanzari != NULL)
			delete[]this->valoareVanzari;
		this->nrVanzariPrecedente++;
		this->valoareVanzari = new float[this->nrVanzariPrecedente];
		for (int i = 0; i < copie.nrVanzariPrecedente; i++)
		{
			this->valoareVanzari[i] = copie.valoareVanzari[i];
			suma = suma + copie.valoareVanzari[i];
		}
		valoare = suma / copie.nrVanzariPrecedente;
		this->valoareVanzari[this->nrVanzariPrecedente - 1] = valoare;
		return *this;
	}
	Agent operator++(int)
		{//adauga inca o vanzare in portofoliul agentului si ia valoare SI VALOAREA ACESTEIA ESTE VALAORE MEDIE A VANZARILOR PRECEDENTE;
			Agent copie = *this;
			float suma = 0;
			float valoare = 0;
			if (this->valoareVanzari != NULL)
				delete[]this->valoareVanzari;
			this->nrVanzariPrecedente++;
			this->valoareVanzari = new float[this->nrVanzariPrecedente];
			for (int i = 0; i < copie.nrVanzariPrecedente; i++)
			{
				this->valoareVanzari[i] = copie.valoareVanzari[i];
				suma = suma + copie.valoareVanzari[i];

			}
			valoare = suma / copie.nrVanzariPrecedente;
			this->valoareVanzari[this->nrVanzariPrecedente - 1] = valoare;
			return copie;
		}

	Agent& operator--()
	{//sterge ultima tranzactie a agentului
		Agent copie = *this;
		if (this->valoareVanzari != NULL)
			delete[]this->valoareVanzari;
		this->nrVanzariPrecedente--;
		this->valoareVanzari = new float[this->nrVanzariPrecedente];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			this->valoareVanzari[i] = copie.valoareVanzari[i];
		return *this;
	}
	Agent& operator--(int)
	{//sterge ultima tranzactie a agentului
		Agent copie = *this;
		if (this->valoareVanzari != NULL)
			delete[]this->valoareVanzari;
		this->nrVanzariPrecedente--;
		this->valoareVanzari = new float[this->nrVanzariPrecedente];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			this->valoareVanzari[i] = copie.valoareVanzari[i];
		return copie;
	}
	bool operator!()
	{//modifica daca agentul primeste acreditarea
		if (this->esteAcreditat == true)
		{
			this->esteAcreditat = false;
			return true;
		}
		if (this->esteAcreditat == false)
		{
			this->esteAcreditat = true;
			return false;
		}
	}

	explicit operator int()
	{
		return this->aniExperienta;
	}
	explicit operator float()
	{
		return this->salariuDeBaza;
	}
	~Agent()
	{
		//cout <<endl<< "S-a apelat destructorul in clasa parinte";
		if (this->nume != NULL)
			delete[]this->nume;
		if (this->valoareVanzari != NULL)
			delete[]this->valoareVanzari;
	}

	float tranzactieMax()
	{
		float max=this->valoareVanzari[0];
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
		{
			if (this->valoareVanzari[i] > max)
			{
				max = this->valoareVanzari[i];
			}

		}
		return max;
	}

	float sumaTranzactii()
	{
		float suma = 0;
		for (int i = 0; i < this->nrVanzariPrecedente; i++)
			suma += this->valoareVanzari[i];
		return suma;
	}

	virtual void bonusAngajatulLunii()
	{
		//Agentul normal primeste ca bonus daca iese angajatul lunii inca o data salariul.
		float bonus = this->salariuDeBaza;
		cout <<endl<< "A primit un bonus de " << bonus << " lei." << endl;
	}
	void bonusVechime(int nrAniVechime) {
		cout << endl << "Bonusul extra este " << (this->salariuDeBaza / 10) * nrAniVechime << " lei." << endl;
	}

};

class AgentImobiliar:public Agent{
	 int procentComision;
	 string agentiePartenera;
	 bool percepeComisionAmbeleParti;
	 //de facut metoda pentru a-i calcula venitul generat de comision 
	 //si venitul total (impreuna cu salariul de baza)

public:
	//constructor fara param
	AgentImobiliar():Agent() {//apelam constructorul fara parametrii din clasa parinte
		this->procentComision = 0;
		this->agentiePartenera = "Anonim";
		this->percepeComisionAmbeleParti = 0;

	}
	//constructor toti param
	AgentImobiliar(const char* nume, const char prenume[50], int aniExperienta, int nrVanzariPrecedente, float* valoareVanzari, float salariuDeBaza, bool esteAcreditat, int procentComision, string agentiePartenera, bool percepeComisionAmbeleParti):Agent(nume, prenume, aniExperienta, nrVanzariPrecedente, valoareVanzari, salariuDeBaza, esteAcreditat)
	{
		this->procentComision = procentComision;
		this->agentiePartenera = agentiePartenera;
		this->percepeComisionAmbeleParti = percepeComisionAmbeleParti;
	}
	//constructorul de copiere
	AgentImobiliar(const AgentImobiliar& ai):Agent(ai) {
		this->procentComision = ai.procentComision;
		this->agentiePartenera = ai.agentiePartenera;
		this->percepeComisionAmbeleParti = ai.percepeComisionAmbeleParti;
	}
	//downCasting
	AgentImobiliar(const Agent& ai) :Agent(ai) {
		this->procentComision = 99999;
		this->agentiePartenera = "DownCast SRL";
		this->percepeComisionAmbeleParti = 1;
	}
	//operator=
	AgentImobiliar& operator=(const AgentImobiliar& ai) {
		if (this != &ai)
		{
			Agent::operator=(ai);
			this->procentComision = ai.procentComision;
			this->agentiePartenera = ai.agentiePartenera;
			this->percepeComisionAmbeleParti = ai.percepeComisionAmbeleParti;
		}
		return *this;
	}
	//operator<<
	friend ostream& operator<<(ostream& out, const AgentImobiliar& ai)
	{
		cout << (Agent&)ai << endl;
		cout << endl <<"Procent comision: "<<ai.procentComision<<"%";
		cout << endl <<"Agentie partenera: "<<ai.agentiePartenera;
		cout << endl <<"Percepe comision de la ambele parti ?"<<ai.percepeComisionAmbeleParti;
		return out;
	
	}


	~AgentImobiliar() {
		//cout << endl << "S-a apelat desturcotrul in clasa derivata";
	}

	//metoda care calculeaza salariul total al Agentului imobiliar(Salariu baza+ comision)

	float valIncasariComision(const AgentImobiliar& a)
	{
		float suma = 0;
		float venitComision = 0;
		for (int i = 0; i < a.nrVanzariPrecedente; i++)
		{
			venitComision = venitComision + ((this->procentComision * a.valoareVanzari[i])/100);
		}
		return a.salariuDeBaza+venitComision;
	}

	void bonusAngajatulLunii()
	{
		//AgentulImob primeste ca bonus daca iese angajatul lunii inca o data salariul + comisionul perceput*100
		float bonus = this->salariuDeBaza+(100*this->procentComision);
		cout << endl << "A primit un bonus de " << bonus << " lei." << endl;
	}
	void bonusVechime(int nrAniVechime) {
		//AgentulImob primeste acelasi bonus ca un agent normal + comisionul sau * 100;
		cout << endl << "Bonusul extra este " << ((this->salariuDeBaza / 10) * nrAniVechime)+(this->procentComision*100) << " lei." << endl;
	}
};

class Proprietar
{
	string nume;
	char* prenume;
	char profesie[50];
	int varsta;
	Imobil imobil;
	int nrProprietatiVanduteAnterior;
	float* valoareProprietatiVanduteAnterior;
	bool esteRezident;
public:
	Proprietar()
	{
		this->nume = "Anonim";
		this->prenume = new char[strlen("Anonim") + 1];
		strcpy(this->prenume, "Anonim");
		strcpy(this->profesie, "Necunoscut");
		this->varsta = 0;
		this->nrProprietatiVanduteAnterior = 0;
		this->valoareProprietatiVanduteAnterior = NULL;
		this->esteRezident = 0;
	}
	Proprietar(string nume, const char* prenume, const char profesie[50], int varsta, Imobil imobil, int nrProprietatiVanduteAnterior, float* valoareProprietatiVanduteAnterior, bool esteRezident)
	{
		this->nume = nume;
		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);
		strcpy(this->profesie, profesie);
		this->varsta = varsta;
		this->imobil = imobil;
		this->nrProprietatiVanduteAnterior = nrProprietatiVanduteAnterior;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			this->valoareProprietatiVanduteAnterior[i] = valoareProprietatiVanduteAnterior[i];
		this->esteRezident = esteRezident;
	}
	Proprietar(const Proprietar& p)
	{
		this->nume = p.nume;
		this->prenume = new char[strlen(p.prenume) + 1];
		strcpy(this->prenume, p.prenume);
		strcpy(this->profesie, p.profesie);
		this->varsta = p.varsta;
		this->imobil = p.imobil;
		this->nrProprietatiVanduteAnterior = p.nrProprietatiVanduteAnterior;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			this->valoareProprietatiVanduteAnterior[i] = p.valoareProprietatiVanduteAnterior[i];
		this->esteRezident = p.esteRezident;
	}
	Proprietar& operator=(const Proprietar& p)
	{
		if (this != &p)
		{
			if (this->prenume != NULL)
				delete[]this->prenume;
			if (this->valoareProprietatiVanduteAnterior != NULL)
				delete[]this->valoareProprietatiVanduteAnterior;
			this->nume = p.nume;
			this->prenume = new char[strlen(p.prenume) + 1];
			strcpy(this->prenume, p.prenume);
			strcpy(this->profesie, p.profesie);
			this->varsta = p.varsta;
			this->imobil = p.imobil;
			this->nrProprietatiVanduteAnterior = p.nrProprietatiVanduteAnterior;
			this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
			for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
				this->valoareProprietatiVanduteAnterior[i] = p.valoareProprietatiVanduteAnterior[i];
			this->esteRezident = p.esteRezident;
		}
		return *this;
	}
	void afisare()
	{
		cout << endl << "ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp" << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Prenume: " << this->prenume << endl;
		cout << "Varsta: " << this->varsta << endl;
		cout << "Imobil asignat:"<<endl;
		cout << this->imobil << endl;
		cout << "Numar proprietati vandute anterior: " << this->nrProprietatiVanduteAnterior << endl;
		cout << "Valoare proprietati vandute anterior: " << endl;
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			cout << this->valoareProprietatiVanduteAnterior[i] << "$, ";
		cout << endl;
		cout << "Este rezident: " << this->esteRezident << endl;
		cout << endl << "pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp" << endl;
	}
	//Geteri
	string getNume()
	{
		return this->nume;
	}
	char* getPrenume()
	{
		return this->prenume;
	}
	string getProfesie()
	{
		return this->profesie;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	Imobil getImobil()
	{
		return this->imobil;
	}
	int getNrProprietatiVanduteAnterior()
	{
		return this->nrProprietatiVanduteAnterior;
	}
	float* getValoareProprietatiVanduteAnterior()
	{
		return this->valoareProprietatiVanduteAnterior;
	}
	bool getEsteRezident()
	{
		return this->esteRezident;
	}
	//Seteri
	void setNume(string nume)
	{
		this->nume = nume;
	}
	void setPrenume(char* prenume)
	{
		if (this->prenume != NULL)
			delete[]this->prenume;
		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);
		
	}
	void setProfesie(char profesie[50])
	{
		strcpy(this->profesie, profesie);
	}
	void setVarsta(int varsta)
	{
		this->varsta = varsta;
	}
	void setImobil(Imobil imobil)
	{
		this->imobil = imobil;
	}
	void setCaloareProprietatiVanduteAnterior(int nrProprietatiVanduteAnterior,float* valoareProprietatiVanduteAnterior)
	{
		if (this->valoareProprietatiVanduteAnterior != NULL)
			delete[]this->valoareProprietatiVanduteAnterior;
		this->nrProprietatiVanduteAnterior = nrProprietatiVanduteAnterior;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			this->valoareProprietatiVanduteAnterior[i] = valoareProprietatiVanduteAnterior[i];
	}
	void setEsteRezident(bool esteRezident)
	{
		this->esteRezident = esteRezident;
	}
	
	friend ostream& operator<<(ostream& out, const Proprietar& p)
	{
		out << "pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp" << endl;
		out <<endl<< "Nume: " << p.nume << endl;
		out << "Prenume: " << p.prenume << endl;
		out << "Varsta: " << p.varsta << endl;
		out << "Profesie: " << p.profesie << endl;
		out << "Proprietate asignata:";
		out << "   " << p.imobil << endl;
		out << "Numar proprietati vandute anterior: " << p.nrProprietatiVanduteAnterior << endl;
		out << "Valoare proprietati vandute anterior: " << endl;
		for (int i = 0; i < p.nrProprietatiVanduteAnterior; i++)
			out << p.valoareProprietatiVanduteAnterior[i] << "$, ";
		out << endl;
		out << "Este rezident: " << p.esteRezident << endl;
		out << "pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp>" << endl << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Proprietar& p)
	{

		cout << "Nume: ";
		getline(in, p.nume);
		cout << "Prenume: ";
		if (p.prenume != NULL)
			delete[]p.prenume;
		char buffer2[100];
		in.getline(buffer2, 99);
		p.prenume = new char[strlen(buffer2) + 1];
		strcpy(p.prenume, buffer2);
		cout << "Profesie: ";
		char buffer3[50];
		in.getline(buffer3, 49);
		strcpy(p.profesie, buffer3);
		cout << "Varsta: ";
		in >> p.varsta;
		cout << "PROPRIETATE ASIGNATA";
		in >> p.imobil;
		cout << "Numar proprietati vandute anterior: ";
		in >> p.nrProprietatiVanduteAnterior;
		cout << "Valoare proprietati vandute anterior: ";
		if (p.valoareProprietatiVanduteAnterior != NULL)
			delete[]p.valoareProprietatiVanduteAnterior;
		p.valoareProprietatiVanduteAnterior = new float[p.nrProprietatiVanduteAnterior];
		for (int i = 0; i < p.nrProprietatiVanduteAnterior; i++)
			in >> p.valoareProprietatiVanduteAnterior[i];
		cout << endl;
		cout << "Este rezident: ";
		in >> p.esteRezident;
		return in;
	}

	float& operator[](int pozitie) {
		if (pozitie > 0 && pozitie <= this->nrProprietatiVanduteAnterior)
		{
			return this->valoareProprietatiVanduteAnterior[pozitie];
		}
		else
			cout << "Aceasta proprietate nu vanduta";
	}
	Proprietar operator+(float valoare)
	{//adauga un nou imobil in lista si valoare la care acesta a fost vandut 
		Proprietar copie = *this;
		if (copie.valoareProprietatiVanduteAnterior != NULL)
			delete[]copie.valoareProprietatiVanduteAnterior;
		copie.nrProprietatiVanduteAnterior++;
		copie.valoareProprietatiVanduteAnterior = new float[copie.nrProprietatiVanduteAnterior];
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			copie.valoareProprietatiVanduteAnterior[i] = this->valoareProprietatiVanduteAnterior[i];
		copie.valoareProprietatiVanduteAnterior[copie.nrProprietatiVanduteAnterior - 1] = valoare;
		return copie;
	}
	Proprietar operator+(int valoare)
	{//Incrementeaza varsta proprietarului cu o valoare data
		this->varsta = this->varsta + valoare;
		return *this;
	}
	Proprietar& operator++()
	{//incrementeaza numarul de proprietati vandute anterior si adauga valoare celei mai mici dintre acestea 
		float valPropVandute = this->valoareProprietatiVanduteAnterior[0];
		Proprietar copie = *this;
		if (this->valoareProprietatiVanduteAnterior != NULL)
			delete[]this->valoareProprietatiVanduteAnterior;
		this->nrProprietatiVanduteAnterior++;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < copie.nrProprietatiVanduteAnterior; i++)
		{
			this->valoareProprietatiVanduteAnterior[i] = copie.valoareProprietatiVanduteAnterior[i];
			if (valPropVandute > this->valoareProprietatiVanduteAnterior[i])
				valPropVandute = this->valoareProprietatiVanduteAnterior[i];
		}
		this->valoareProprietatiVanduteAnterior[copie.nrProprietatiVanduteAnterior+1] = valPropVandute;
		return *this;
	}
	Proprietar& operator++(int)
	{//incrementeaza numarul de proprietati vandute anterior si adauga valoare celei mai mici dintre acestea 
		float valPropVandute = this->valoareProprietatiVanduteAnterior[0];
		Proprietar copie = *this;
		if (this->valoareProprietatiVanduteAnterior != NULL)
			delete[]this->valoareProprietatiVanduteAnterior;
		this->nrProprietatiVanduteAnterior++;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < copie.nrProprietatiVanduteAnterior; i++)
		{
			this->valoareProprietatiVanduteAnterior[i] = copie.valoareProprietatiVanduteAnterior[i];
			if (valPropVandute > this->valoareProprietatiVanduteAnterior[i])
				valPropVandute = this->valoareProprietatiVanduteAnterior[i];
		}
		this->valoareProprietatiVanduteAnterior[this->nrProprietatiVanduteAnterior - 1] = valPropVandute;
		return copie;
	}

	Proprietar& operator--()
	{//sterge una din prop vandutele anterior 
		Proprietar copie = *this;
		if (this->valoareProprietatiVanduteAnterior != NULL)
			delete[]this->valoareProprietatiVanduteAnterior;
		this->nrProprietatiVanduteAnterior--;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			this->valoareProprietatiVanduteAnterior[i] = copie.valoareProprietatiVanduteAnterior[i];
		return *this;
	}
	Proprietar& operator--(int)
	{//sterge una din prop vandutele anterior 
		Proprietar copie = *this;
		if (this->valoareProprietatiVanduteAnterior != NULL)
			delete[]this->valoareProprietatiVanduteAnterior;
		this->nrProprietatiVanduteAnterior--;
		this->valoareProprietatiVanduteAnterior = new float[this->nrProprietatiVanduteAnterior];
		for (int i = 0; i < this->nrProprietatiVanduteAnterior; i++)
			this->valoareProprietatiVanduteAnterior[i] = copie.valoareProprietatiVanduteAnterior[i];
		return copie;
	}
	bool operator!()
	{
		if (this->esteRezident == true)
		{
			this->esteRezident = false;
			return true;
		}
		if (this->esteRezident == false)
		{
			this->esteRezident = true;
			return false;
		}
	}

	explicit operator string()
	{
		return this->nume;
	}
	explicit operator int()
	{
		return this->varsta;
	}
	~Proprietar()
	{
		if (this->prenume != NULL)
			delete[]this->prenume;
		if (this->valoareProprietatiVanduteAnterior != NULL)
			delete[]this->valoareProprietatiVanduteAnterior;
	}
};
class Cumparator
{
	char nume[50];
	char* prenume;
	int varsta;
	float buget;//preferinta
	int nrImobileDetinuteAnterior;
	float* valoareImobileDetinuteAnterior;
	bool eligibilDeCredit;
	//preferinte
	int prefMinimAnConstructieImobil;
	int prefMinimNrCamere;
	float prefMinimMpImobil;
	bool prefCentrala;
	float prefDistantaMaxMetrou;
public:
	Cumparator()
	{
		strcpy(this->nume, "Anonim");
		this->prenume = new char[strlen("Anonim") + 1];
		strcpy(this->prenume, "Anonim");
		this->varsta = 0;
		this->buget = 0;
		this->nrImobileDetinuteAnterior = 0;
		this->valoareImobileDetinuteAnterior = NULL;
		this->eligibilDeCredit = 0;
		this->prefMinimAnConstructieImobil = 0;
		this->prefMinimNrCamere = 0;
		this->prefMinimMpImobil = 0;
		this->prefCentrala = 0;
		this->prefDistantaMaxMetrou = 0;
	}
	Cumparator(const char nume[50],
		const char* prenume,
		int varsta,
		float buget,
		int nrImobileDetinuteAnterior,
		float* valoareImobileDetinuteAnterior,
		bool eligibilDeCredit,
		int prefMinimAnConstructieImobil,
		int prefMinimNrCamere,
		float prefMinimMpImobil,
		bool prefCentrala,
		float prefDistantaMaxMetrou)
	{
		strcpy(this->nume, nume);
		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);
		this->varsta = varsta;
		this->buget = buget;
		this->nrImobileDetinuteAnterior = nrImobileDetinuteAnterior;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			this->valoareImobileDetinuteAnterior[i] = valoareImobileDetinuteAnterior[i];
		this->eligibilDeCredit = eligibilDeCredit;
		this->prefMinimAnConstructieImobil = prefMinimAnConstructieImobil;
		this->prefMinimNrCamere = prefMinimNrCamere;
		this->prefMinimMpImobil = prefMinimMpImobil;
		this->prefCentrala = prefCentrala;
		this->prefDistantaMaxMetrou = prefDistantaMaxMetrou;
	}
	//Geteri
	string getNume()
	{
		return this->nume;
	}
	const char* getPrenume()
	{
		return this->prenume;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	float getBuget()
	{
		return this->buget;
	}
	int getNrImobileDetinuteAnterior()
	{
		return this->nrImobileDetinuteAnterior;
	}
	float* getValoareImobileDetinuteAnterior()
	{
		return this->valoareImobileDetinuteAnterior;
	}
	bool getEligibilDeCredit()
	{
		return this->eligibilDeCredit;
	}
	int getPrefMinimAnConstructieImobil()
	{
		return this->prefMinimAnConstructieImobil;
	}
	int getPrefMinimNrCamere()
	{
		return this->prefMinimNrCamere;
	}
	float getPrefMinimMpImobil()
	{
		return this->prefMinimMpImobil;
	}
	bool getPrefCentrala()
	{
		return this->prefCentrala;
	}
	float getPrefDistantaMaxMetrou()
	{
		return this->prefDistantaMaxMetrou;
	}
	//Seteri

	void setNume(const char nume[50])
	{
		if (strlen(nume) > 1)
			strcpy(this->nume, nume);
		else
			cout << "Nume invalid";
	}
	void setPrenume(const char* prenume)
	{
		if (this->prenume != NULL)
			delete[]this->prenume;
		if (strlen(prenume) > 1)
		{
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
		else
			cout << "Prenume invalid";
	}
	void getVarsta(int varsta )
	{
		if(varsta > 10)
		this->varsta = varsta;
		else
			cout << "Varsta invalida";
	}
	void getBuget(float buget)
	{
		if(buget > 0)
		this->buget = buget;
		else
			cout << "Buget invalid";
	}
	void setValoareImobileDetinuteAnterior(int nrImobileDetinuteAnterior, float* valoareImobileDetinuteAnterior)
	{
		if (this->valoareImobileDetinuteAnterior != NULL)
			delete[]this->valoareImobileDetinuteAnterior;
		this->nrImobileDetinuteAnterior = nrImobileDetinuteAnterior;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			this->valoareImobileDetinuteAnterior[i] = valoareImobileDetinuteAnterior[i];
	}
	void getEligibilDeCredit(bool eligibilDeCredit)
	{
		this->eligibilDeCredit = eligibilDeCredit;
	}
	void getPrefMinimAnConstructieImobil(int prefMinimAnConstructieImobil)
	{
		if(prefMinimAnConstructieImobil > 0 && prefMinimAnConstructieImobil < 2022)
		this->prefMinimAnConstructieImobil = prefMinimAnConstructieImobil;
		else
			cout << "Preferinta an constructie imobil invalida";
	}
	void getPrefMinimNrCamere(int prefMinimNrCamere)
	{
		if(prefMinimNrCamere > 0)
		this->prefMinimNrCamere = prefMinimNrCamere;
		else
			cout << "Numar de camere introdus invalid";
	}
	void getPrefMinimMpImobil(float prefMinimMpImobil)
	{
		if(prefMinimMpImobil > 0)
		this->prefMinimMpImobil = prefMinimMpImobil;
		else
			cout << "Minimul de mp introdus invalid";
	}
	void getPrefCentrala(bool prefCentrala)
	{
		this->prefCentrala = prefCentrala;
	}
	void getPrefDistantaMaxMetrou(float prefDistantaMaxMetrou)
	{
		if(prefDistantaMaxMetrou > 0)
		this->prefDistantaMaxMetrou = prefDistantaMaxMetrou;
		else
			cout << "Distanta la cel mai apropiat metrou invalida";
	}

	void afisare()
	{
		cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Prenume: " << this->prenume << endl;
		cout << "Varsta: " << this->varsta << endl;
		cout << "Buget: " << this->buget << endl;
		cout << "Nr. imobile detinute anterior: " << this->nrImobileDetinuteAnterior << endl;
		cout << "Valoarea imobilelor detinute anterior: " << endl;
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			cout << this->valoareImobileDetinuteAnterior[i] << "$, ";
		cout << endl;
		cout << "Este eligibil de credit bancar? (0=NU / 1=DA): " << this->eligibilDeCredit << endl;
		cout << "An constructie minim preferat pentru un imobil: " << this->prefMinimAnConstructieImobil << endl;
		cout << "Mp minim preferati pentru imobil;: " << this->prefMinimMpImobil << "mp" << endl;
		cout << "Nr camere minim preferat pentru imobil: " << this->prefMinimNrCamere << endl;
		cout << "Prefera ca imobilul sa aiba centrala(0=NU / 1=DA): " << this->prefCentrala << endl;
		cout << "Distana maxima fata de metrou preferata: " << this->prefDistantaMaxMetrou << "m" << endl;
		cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl<<endl;
	}
	Cumparator(const Cumparator& c)
	{
		strcpy(this->nume, c.nume);
		this->prenume = new char[strlen(c.prenume) + 1];
		strcpy(this->prenume, c.prenume);
		this->varsta = c.varsta;
		this->buget = c.buget;
		this->nrImobileDetinuteAnterior = c.nrImobileDetinuteAnterior;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			this->valoareImobileDetinuteAnterior[i] = c.valoareImobileDetinuteAnterior[i];
		this->eligibilDeCredit = c.eligibilDeCredit;
		this->prefMinimAnConstructieImobil = c.prefMinimAnConstructieImobil;
		this->prefMinimNrCamere = c.prefMinimNrCamere;
		this->prefMinimMpImobil = c.prefMinimMpImobil;
		this->prefCentrala = c.prefCentrala;
		this->prefDistantaMaxMetrou = c.prefDistantaMaxMetrou;
	}

	Cumparator& operator=(const Cumparator& c)
	{
		if (this != &c)
		{
			
			if (this->prenume != NULL)
				delete[]this->prenume;
			if (this->valoareImobileDetinuteAnterior != NULL)
				delete[]this->valoareImobileDetinuteAnterior;
			strcpy(this->nume, c.nume);
			this->prenume = new char[strlen(c.prenume) + 1];
			strcpy(this->prenume, c.prenume);
			this->varsta = c.varsta;
			this->buget = c.buget;
			this->nrImobileDetinuteAnterior = c.nrImobileDetinuteAnterior;
			this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
			for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
				this->valoareImobileDetinuteAnterior[i] = c.valoareImobileDetinuteAnterior[i];
			this->eligibilDeCredit = c.eligibilDeCredit;
			this->prefMinimAnConstructieImobil = c.prefMinimAnConstructieImobil;
			this->prefMinimNrCamere = c.prefMinimNrCamere;
			this->prefMinimMpImobil = c.prefMinimMpImobil;
			this->prefCentrala = c.prefCentrala;
			this->prefDistantaMaxMetrou = c.prefDistantaMaxMetrou;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Cumparator& c)
	{
		cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		out <<endl<< "Nume: " << c.nume << endl;
		out << "Prenume: " << c.prenume << endl;
		out << "Varsta: " << c.varsta << endl;
		out << "Buget: " << c.buget << endl;
		out << "Nr. imobile detinute anterior: " << c.nrImobileDetinuteAnterior << endl;
		out << "Valoarea imobilelor detinute anterior: " << endl;
		for (int i = 0; i < c.nrImobileDetinuteAnterior; i++)
			out << c.valoareImobileDetinuteAnterior[i] << "$, ";
		out << endl;
		out << "Este eligibil de credit bancar? (0=NU / 1=DA): " << c.eligibilDeCredit << endl;
		out << "An constructie minim preferat pentru un imobil: " << c.prefMinimAnConstructieImobil << endl;
		out << "Mp minim preferati pentru imobil: " << c.prefMinimMpImobil << "mp" << endl;
		out << "Nr camere minim preferat pentru imobil: " << c.prefMinimNrCamere << endl;
		out << "Prefera ca imobilul sa aiba centrala(0=NU / 1=DA): " << c.prefCentrala << endl;
		out << "Distana maxima fata de metrou preferata: " << c.prefDistantaMaxMetrou << "m" << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, Cumparator& c)
	{
		cout << "Nume: " ;
		char buffer1[50];
		in.getline(buffer1, 49);
		strcpy(c.nume, buffer1);
		cout << "Prenume: ";
		if (c.prenume != NULL)
			delete[]c.prenume;
		char buffer2[100];
		in.getline(buffer2, 99);
		c.prenume = new char[strlen(buffer2) + 1];
		strcpy(c.prenume, buffer2);
		cout << "Varsta: ";
		in >> c.varsta;
		cout << "Buget: ";
		in >> c.buget;
		cout << "Nr. imobile detinute anterior: ";
		in >> c.nrImobileDetinuteAnterior;
		cout << "Valoarea imobilelor detinute anterior: " << endl;
		if (c.valoareImobileDetinuteAnterior != NULL)
			delete[]c.valoareImobileDetinuteAnterior;
		c.valoareImobileDetinuteAnterior = new float[c.nrImobileDetinuteAnterior];
		for (int i = 0; i < c.nrImobileDetinuteAnterior; i++)
			in >> c.valoareImobileDetinuteAnterior[i];
		cout << endl;
		cout << "Este eligibil de credit bancar? (0=NU / 1=DA): ";
		in >> c.eligibilDeCredit;
		cout << "An constructie minim preferat pentru un imobil: ";
		in >> c.prefMinimAnConstructieImobil;
		cout << "Mp minim preferati pentru imobil;: " ;
		in >> c.prefMinimMpImobil;
		cout << "Nr camere minim preferat pentru imobil: ";
		in >> c.prefMinimNrCamere;
		cout << "Prefera ca imobilul sa aiba centrala(0=NU / 1=DA): ";
		in >> c.prefCentrala;
		cout << "Distana maxima fata de metrou preferata: ";
		in >> c.prefDistantaMaxMetrou;
		return in;
	}

	//a1[2]=30000
	//operator cast care ne spune valoare imobilului detinut anterior de cumparator
	float& operator[](int pozitie) {
		if (pozitie > 0 && pozitie <= this->nrImobileDetinuteAnterior)
		{
			return this->valoareImobileDetinuteAnterior[pozitie];
		}
		else
			cout << "Imobilul introdus nu exista";
	}
	//a1+20000
	//operator de adaugare care adauga o noua proprietate detinuta atnerior de cumparator
	Cumparator operator+(float valoare)
	{
		Cumparator copie = *this;
		if (copie.valoareImobileDetinuteAnterior != NULL)
			delete[]copie.valoareImobileDetinuteAnterior;
		copie.nrImobileDetinuteAnterior++;
		copie.valoareImobileDetinuteAnterior = new float[copie.nrImobileDetinuteAnterior];
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			copie.valoareImobileDetinuteAnterior[i] = this->valoareImobileDetinuteAnterior[i];
		copie.valoareImobileDetinuteAnterior[copie.nrImobileDetinuteAnterior - 1] = valoare;
		return copie;
	}
	Cumparator& operator++()
	{//incrementeazza numarul de imobile detinute anterior de cumparator, adaugand valaore medie a celor anterioare;
		Cumparator copie = *this;
		float suma = 0;
		float valoare = 0;
		if (this->valoareImobileDetinuteAnterior != NULL)
			delete[]this->valoareImobileDetinuteAnterior;
		this->nrImobileDetinuteAnterior++;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < copie.nrImobileDetinuteAnterior; i++)
		{
			this->valoareImobileDetinuteAnterior[i] = copie.valoareImobileDetinuteAnterior[i];
			suma = suma + copie.valoareImobileDetinuteAnterior[i];
		}
		valoare = suma / copie.nrImobileDetinuteAnterior;
		this->valoareImobileDetinuteAnterior[this->nrImobileDetinuteAnterior - 1] = valoare;
		return *this;
	}

	Cumparator operator++(int)
	{//incrementeazza numarul de imobile detinute anterior de cumparator, adaugand valaore medie a celor anterioare;
		Cumparator copie = *this;
		float suma = 0;
		float valoare = 0;
		if (this->valoareImobileDetinuteAnterior != NULL)
			delete[]this->valoareImobileDetinuteAnterior;
		this->nrImobileDetinuteAnterior++;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < copie.nrImobileDetinuteAnterior; i++)
		{
			this->valoareImobileDetinuteAnterior[i] = copie.valoareImobileDetinuteAnterior[i];
			suma = suma + copie.valoareImobileDetinuteAnterior[i];
		}
		valoare = suma / copie.nrImobileDetinuteAnterior;
		this->valoareImobileDetinuteAnterior[this->nrImobileDetinuteAnterior - 1] = valoare;
		return copie;
	}

	Cumparator& operator--()
	{//sterge ultima tranzactie a agentului
		Cumparator copie = *this;
		if (this->valoareImobileDetinuteAnterior != NULL)
			delete[]this->valoareImobileDetinuteAnterior;
		this->nrImobileDetinuteAnterior--;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			this->valoareImobileDetinuteAnterior[i] = copie.valoareImobileDetinuteAnterior[i];
		return *this;
	}
	Cumparator& operator--(int)
	{//sterge ultima tranzactie a agentului
		Cumparator copie = *this;
		if (this->valoareImobileDetinuteAnterior != NULL)
			delete[]this->valoareImobileDetinuteAnterior;
		this->nrImobileDetinuteAnterior--;
		this->valoareImobileDetinuteAnterior = new float[this->nrImobileDetinuteAnterior];
		for (int i = 0; i < this->nrImobileDetinuteAnterior; i++)
			this->valoareImobileDetinuteAnterior[i] = copie.valoareImobileDetinuteAnterior[i];
		return copie;
	}

	bool operator!()
	{//modifica daca agentul primeste acreditarea
		if (this->eligibilDeCredit == true)
		{
			this->eligibilDeCredit = false;
			return true;
		}
		if (this->eligibilDeCredit == false)
		{
			this->eligibilDeCredit = true;
			return false;
		}
	}
	
	explicit operator int()
	{
		return this->prefMinimAnConstructieImobil;
	}
	explicit operator float()
	{
		return this->prefMinimMpImobil;
	}

	~Cumparator()
	{
		//cout << endl << "Destructor cumparator activat" << endl;
		if (this->prenume != NULL)
			delete[]this->prenume;
		if (this->valoareImobileDetinuteAnterior != NULL)
			delete[]this->valoareImobileDetinuteAnterior;

	}
	
};

class Contract
{
	const int nrContract;
	char* titluContract;
	Cumparator cumparator;
	Proprietar proprietar;
	tipPlata _tipPlata;
	string dataIncheiereContract;
	int nrClauze;
	string* numeClauze;
	float* valoareClauze;
	bool prevedeFortaMajora;
public:
	Contract() :nrContract(0)
	{
		this->titluContract = new char[strlen("Neprecizat") + 1];
		strcpy(this->titluContract, "Neprecizat");
		this->_tipPlata = tipPlata::Neprecizat;
		this->dataIncheiereContract = "00/00/0000";
		this->nrClauze = 0;
		this->numeClauze = NULL;
		this->valoareClauze = NULL;
		this->prevedeFortaMajora = 0;
	}
	Contract(int nrContract, const char* titluContract, Cumparator cumparator, Proprietar proprietar, tipPlata _tipPlata, string dataIncheiereContract, int nrClauze, string* numeClauze, float* valoareClauze, bool prevedeFortaMajora) :nrContract(nrContract)
	{
		this->titluContract = new char[strlen(titluContract) + 1];
		strcpy(this->titluContract, titluContract);
		this->cumparator = cumparator;
		this->proprietar = proprietar;
		this->_tipPlata = _tipPlata;
		this->dataIncheiereContract = dataIncheiereContract;
		this->nrClauze = nrClauze;
		this->numeClauze = new string[this->nrClauze];
		for (int i = 0; i < this->nrClauze; i++)
			this->numeClauze[i] = numeClauze[i];
		this->valoareClauze = new float[this->nrClauze];
		for (int i = 0; i < this->nrClauze; i++)
			this->valoareClauze[i] = valoareClauze[i];
		this->prevedeFortaMajora = prevedeFortaMajora;
	}
	//G E T E R I
	
	int getNrContract()
	{
	return this->nrContract;
	}
	
	char* getTitluContract()
	{
	return this->titluContract;
	}
	
	Cumparator getCumparator()
	{
	return this->cumparator;
	}
	
	Proprietar getProprietar()
	{
	return this->proprietar;
	}
	
	tipPlata get_tipPlata()
	{
	return this->_tipPlata;
	}
	
	string getDataIncheiereContract()
	{
	return this->dataIncheiereContract;
	}
	
	int getNrClauze()
	{
	return this->nrClauze;
	}
	
	string* getNumeClauze()
	{
	return this->numeClauze;
	}
	
	float* getValoareClauze()
	{
	return this->valoareClauze;
	}
	
	bool getPrevedeFortaMajora()
	{
	return this->prevedeFortaMajora;
	}
	
	//S E T E R I
	
	void setTitluContract(const char* titluContract)
	{
	if (this->titluContract != NULL)
			delete[]this->titluContract;
	if (strlen(titluContract) > 2)
	{
		this->titluContract = new char[strlen(titluContract) + 1];
		strcpy(this->titluContract, titluContract);
	}
	else 
		cout << endl << "Titlul introdus este invalid." << endl;
	}
	
	void setCumparator(Cumparator cumparator)
	{
	this->cumparator = cumparator;
	}
	
	void setProprietar(Proprietar proprietar)
	{
	this->proprietar = proprietar;
	}
	
	void set_tipPlata(tipPlata _tipPlata)
	{
	this->_tipPlata = _tipPlata;
	}
	
	void setDataIncheiereContract(string dataIncheiereContract)
	{
		if (size(dataIncheiereContract) < 8)
			this->dataIncheiereContract = dataIncheiereContract;
		else
			cout<<endl << "Data introdusa gresit! Formatul corect este DD/MM/YYYY!" << endl;
	}
	
	void setNrNumeValoareClauze(int nrClauze,string* numeClauze,float* valoareClauze)
	{
		if (this->numeClauze != NULL)
				delete[]this->numeClauze;
		if (this->valoareClauze != NULL)
				delete[]this->valoareClauze;
		this->nrClauze = nrClauze;
		this->numeClauze = new string[this->nrClauze];
			for (int i = 0; i < this->nrClauze; i++)
				this->numeClauze[i] = numeClauze[i];
		this->valoareClauze = new float[this->nrClauze];
			for (int i = 0; i < this->nrClauze; i++)
				this->valoareClauze[i] = valoareClauze[i];
	}
	void setPrevedeFortaMajora(bool prevedeFortaMajora)
	{
		this->prevedeFortaMajora = prevedeFortaMajora;
	}
	
	void afisare()
	{
		cout << "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" << endl;
		cout << "Nr Contract: " << this->nrContract << endl;
		cout << "Titlu Contract: " << this->titluContract << endl;
		cout << "Cumparator: " << this->cumparator << endl;
		cout << "Proprietar: " << this->proprietar << endl;
		cout << "Tip plata: " << this->_tipPlata << endl;
		cout << "Nr. Clauze: " << this->nrClauze << endl;
		cout << "Nume Clauze: " << endl;
		for (int i = 0; i < this->nrClauze; i++)
			cout<<this->numeClauze[i] <<", ";
		cout << endl;
		cout << "Valoare Clauze: "<< endl;
		for (int i = 0; i < this->nrClauze; i++)
			cout << this->valoareClauze[i] << "$, ";
		cout << endl;
		cout << "Contine clauza de forta majora? (0=NU / 1=DA): -" << this->prevedeFortaMajora <<"-" << endl;
		cout << "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" << endl << endl;;
	}
	Contract(const Contract& c) :nrContract(c.nrContract)
	{
		this->titluContract = new char[strlen(c.titluContract) + 1];
		strcpy(this->titluContract, c.titluContract);
		this->cumparator = c.cumparator;
		this->proprietar = c.proprietar;
		this->_tipPlata = c._tipPlata;
		this->dataIncheiereContract = c.dataIncheiereContract;
		this->nrClauze = c.nrClauze;
		this->numeClauze = new string[this->nrClauze];
		for (int i = 0; i < this->nrClauze; i++)
			this->numeClauze[i] = c.numeClauze[i];
		this->valoareClauze = new float[this->nrClauze];
		for (int i = 0; i < this->nrClauze; i++)
			this->valoareClauze[i] = c.valoareClauze[i];
		this->prevedeFortaMajora = c.prevedeFortaMajora;
	}
	Contract& operator=(const Contract& c)
	{
		if (this != &c)
		{
			if (this->numeClauze != NULL)
				delete[]this->numeClauze;
			if (this->valoareClauze != NULL)
				delete[]this->valoareClauze;
			this->titluContract = new char[strlen(c.titluContract) + 1];
			strcpy(this->titluContract, c.titluContract);
			this->cumparator = c.cumparator;
			this->proprietar = c.proprietar;
			this->_tipPlata = c._tipPlata;
			this->dataIncheiereContract = c.dataIncheiereContract;
			this->nrClauze = c.nrClauze;
			this->numeClauze = new string[this->nrClauze];
			for (int i = 0; i < this->nrClauze; i++)
				this->numeClauze[i] = c.numeClauze[i];
			this->valoareClauze = new float[this->nrClauze];
			for (int i = 0; i < this->nrClauze; i++)
				this->valoareClauze[i] = c.valoareClauze[i];
			this->prevedeFortaMajora = c.prevedeFortaMajora;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Contract& c)
	{
		out << "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" << endl;
		out << "Nr Contract: " << c.nrContract << endl;
		out << "Titlu Contract: " << c.titluContract << endl;
		out << "Cumparator: " << c.cumparator << endl;
		out << "Proprietar: " <<endl<< c.proprietar << endl;
		out << "Tip plata: " << endl << c._tipPlata << endl;
		out << "Nr. Clauze: " << endl << c.nrClauze << endl;
		out << "Nume Clauze: " << endl;
		for (int i = 0; i < c.nrClauze; i++)
			out << c.numeClauze[i] << ", ";
		out << endl;
		out << "Valoare Clauze: " << endl;
		for (int i = 0; i < c.nrClauze; i++)
			out << c.valoareClauze[i] << "$, ";
		out << endl;
		out << "Contine clauza de forta majora? (0=NU / 1=DA): -" << c.prevedeFortaMajora << "-" << endl;
		out << "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" << endl << endl;;
		return out;
	}
	friend istream& operator>>(istream& in, Contract& c)
	{
		
		cout << "Titlu Contract: ";
		if (c.titluContract != NULL)
			delete[]c.titluContract;
		char buffer1[200];
		in.getline(buffer1, 199);
		c.titluContract = new char[strlen(buffer1) + 1];
		strcpy(c.titluContract, buffer1);
		cout << "Cumparator: " ;
		in >> c.cumparator;
		cout << "Proprietar: ";
		in >> c.proprietar;
		cout << "Tip plata (Neprecizat = 0, plataTransfer = 1, plataCash = 2, plataMix = 3, plataPrinCreditBancar = 4): "<<endl ;
		int valoare;
		in >> valoare;
		switch (valoare)
		{
		case 0:c._tipPlata = Neprecizat; break;
		case 1:c._tipPlata = plataTransfer; break;
		case 2:c._tipPlata = plataCash; break;
		case 3:c._tipPlata = plataMix; break;
		case 4:c._tipPlata = plataPrinCreditBancar; break;
		}
		cout << "Nr. Clauze: ";
		in >> c.nrClauze;
		cout << "Nume Clauze: " << endl;
		c.numeClauze = new string[c.nrClauze];
		for (int i = 0; i < c.nrClauze; i++)
			in >> c.numeClauze[i];
		cout << endl;
		cout << "Valoare Clauze: " << endl;
		c.valoareClauze = new float[c.nrClauze];
		for (int i = 0; i < c.nrClauze; i++)
			in>>c.valoareClauze[i];
		cout << endl;
		cout << "Contine clauza de forta majora? (0=NU / 1=DA): -" ;
		in >> c.prevedeFortaMajora;
		return in;
	}
	/*
	operatorul pentru idexare [] V
	minim un operator matematic (+,-,* sau /) V
	++ sau -- (cu cele 2 forme) V
	operatorul cast (catre orice tip) explicit sau implicit  V
	operatorul pentru negatie ! V
	un operator conditional (<.>,=<,>=)
	operatorul pentru testarea egalitatii dintre 2 obiecte ==


		const int nrContract;
	char* titluContract;
	Cumparator cumparator;
	Imobil imobil;
	Proprietar proprietar;
	tipPlata _tipPlata;
	string dataIncheiereContract;
	int nrClauze;
	string* numeClauze;
	float* valoareClauze;
	bool prevedeFortaMajora;
		*/
	//Operator de indexare ce pe baza numarului clauzei ne spun care este aceasta
	string& operator[](int pozitie) 
	{
		if (pozitie > 0 && pozitie <= this->nrClauze)
		{
			return this->numeClauze[pozitie];
		}
		else
			cout << "Clauza cu acest numar nu exista";
	}

	//Operatorul + adauga o noua clauza in contract, numele acesteia fiind dat ca parametru 
	Contract operator+(string numeClauza)
	{
		Contract copie = *this;
		if (copie.numeClauze != NULL)
			delete[]copie.numeClauze;
		copie.nrClauze++;
		copie.numeClauze= new string[copie.nrClauze];
		for (int i = 0; i < this->nrClauze; i++)
			copie.numeClauze[i] = this->numeClauze[i];
		copie.numeClauze[copie.nrClauze - 1] = numeClauza;
		return copie;
	}
	//Operator de preincrementare ce adauga o clasa in contract, preia numele ultimei si valoare primei;
	Contract& operator++()//pre (modif se fac pe ob nostru)
	{
		Contract copie = *this;
		float valoareClauza = this->valoareClauze[0];
		string numeClauza = this->numeClauze[copie.nrClauze-1];
		if (this->numeClauze != NULL)
			delete[]this->numeClauze;
		if (this->valoareClauze != NULL)
			delete[]this->valoareClauze;
		this->nrClauze++;
		this->numeClauze= new string[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->numeClauze[i] = copie.numeClauze[i];
		}
		this->numeClauze[this->nrClauze-1] = numeClauza;
		
		this->valoareClauze= new float[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->valoareClauze[i] = copie.valoareClauze[i];
		}
		this->valoareClauze[this->nrClauze - 1] = valoareClauza;
		return *this;
	}
	//Operator de postincrementare ce adauga o clasa in contract, preia numele ultimei si valoare primei;
	Contract& operator++(int)//pre (modif se fac pe ob nostru)
	{
		Contract copie = *this;
		float valoareClauza = this->valoareClauze[0];
		string numeClauza = this->numeClauze[copie.nrClauze - 1];
		if (this->numeClauze != NULL)
			delete[]this->numeClauze;
		if (this->valoareClauze != NULL)
			delete[]this->valoareClauze;
		this->nrClauze++;
		this->numeClauze = new string[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->numeClauze[i] = copie.numeClauze[i];
		}
		this->numeClauze[copie.nrClauze + 1] = numeClauza;

		this->valoareClauze = new float[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->valoareClauze[i] = copie.valoareClauze[i];
		}
		this->valoareClauze[copie.nrClauze + 1] = valoareClauza;
		return copie;
	}
	//Operator de predecrementare ce sterge o clauza, numele si valoarea ei
	Contract& operator--()//pre (modif se fac pe ob nostru)
	{ 
		Contract copie = *this;
		if (this->numeClauze != NULL)
			delete[]this->numeClauze;
		if (this->valoareClauze != NULL)
			delete[]this->valoareClauze;
		this->nrClauze--;
		this->numeClauze = new string[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->numeClauze[i] = copie.numeClauze[i];
		}
		this->valoareClauze = new float[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->valoareClauze[i] = copie.valoareClauze[i];
		}
		return *this;
	}
	//Operator de postdecrementare ce sterge o clauza, numele si valoarea ei
	Contract& operator--(int)//pre (modif se fac pe ob nostru)
	{
		Contract copie = *this;
		if (this->numeClauze != NULL)
			delete[]this->numeClauze;
		if (this->valoareClauze != NULL)
			delete[]this->valoareClauze;
		this->nrClauze--;
		this->numeClauze = new string[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->numeClauze[i] = copie.numeClauze[i];
		}
		this->valoareClauze = new float[this->nrClauze];
		for (int i = 0; i < copie.nrClauze; i++)
		{
			this->valoareClauze[i] = copie.valoareClauze[i];
		}
		return copie;
	}
	//Operator ! ce schimba daca contractul prevede forta majora
	bool operator!()
	{
		if (this->prevedeFortaMajora == true)
		{
			this->prevedeFortaMajora = false;
			return true;
		}
		if (this->prevedeFortaMajora == false)
		{
			this->prevedeFortaMajora = true;
			return false;
		}
	}
	
	explicit operator string()
	{
		return this->dataIncheiereContract;
	}
	explicit operator int()
	{
		return this->nrClauze;
	}

	~Contract()
	{
		if (this->titluContract != NULL)
			delete[]this->titluContract;
		if (this->numeClauze != NULL)
			delete[]this->numeClauze;
		if (this->valoareClauze != NULL)
			delete[]this->valoareClauze;
	}
};
int Agent::numarator = 0;
void imobilulPerfect(Imobil im, Cumparator c)
{
	int k = 0;
	if(c.getPrefMinimAnConstructieImobil() >= im.getAnConstructieImobil());
	{
		cout << "Preferintele cumparatorului privind anul de constructie al imobilului se pliaza pe acest imobil." << endl;
		k++;
	}
	if(c.getPrefCentrala() == im.getAreCentrala());
	{
		cout << "Preferintele cumparatorului privind existenta unei centrale se pliaza pe acest imobil." << endl;
		k++;
	}
	if(c.getPrefDistantaMaxMetrou() <=  im.getDistantaMetrou());
	{
		cout << "Preferintele cumparatorului privind distanta maxima pana la cel mai apropiat metrou se pliaza pe acest imobil." << endl;
		k++;
	}
	if(c.getPrefMinimNrCamere() <= im.getNrCamere());
	{
		cout << "Preferintele cumparatorului privind numarul minim de camere se pliaza pe acest imobil." << endl;
		k++;
	}
	switch (k)
	{
	case 1:
		cout<<endl << "Imobilul se potrvieste in proportie de 20% cu preferintele clientului!" << endl;
	break;
	case 2:
		cout << endl << "Imobilul se potrvieste in proportie de 40% cu preferintele clientului!" << endl;
		break;
	case 3:
		cout << endl << "Imobilul se potrvieste in proportie de 60% cu preferintele clientului!" << endl;
		break;
	case 4:
		cout << endl << "Imobilul se potrvieste in proportie de 80% cu preferintele clientului!" << endl;
		break;
	case 5:
		cout << endl << "Imobilul se potrvieste in proportie de 100% cu preferintele clientului!" << endl;
		break;
	
	
	}
}

int main()
{
	//Z O N A       D E        T E S T A R E 
	//Z O N A       D E        T E S T A R E 
	//Z O N A       D E        T E S T A R E 
	//Z O N A       D E        T E S T A R E 
	//Z O N A       D E        T E S T A R E 
	



	system("Color 0D");
	//I M O B I L
	Imobil i0;

	//1.Testare functie afisare:
	//i0.afisare();

	//2.Testare constructor cu toti param:
	float mpCamere1[2] = { 15,16 };
	Imobil i1(0001, "Bucuresti", "Str. Vacaresti nr. 23", "Vitan", 74, 1984, 2, mpCamere1, 1, 800, 65000);
	Imobil i10(0001, "Calarasi", "Str. Manu nr. 5", "Dealu", 65, 1988, 2, mpCamere1, 1, 300, 89000);
	Imobil i11(0001, "Dolj", "Str. Popa nr. 1", "Gargauni", 54, 1984, 2, mpCamere1, 1, 600, 54000);
	Imobil i12(0001, "Bucuresti", "Str. Iulica nr. 235", "Pantelimon", 65, 1984, 1, mpCamere1, 1, 200, 25000);
	//i1.afisare();

	//3.Testare geteri:
	//cout << "Adresa imobilului 1 este: " << i1.getAdresaImobil() << endl;
	//cout << "Imobilul 1 se afla in cartierul: " << i1.getCartier() << endl;
	//cout << "Imobilul 1 are " << i1.getNrCamere() << " camere" << endl;
	//cout << "Camere din imobilul 1 au urmatoare suprafata: ";
	//for (int i = 0; i < i1.getNrCamere(); i++)
	//	cout << i1.getMpCamere()[i] << "mp, ";

	//4.Testare seteri:
	i1.setAdresaImobil("Aleea livezilor nr.13");
	i1.setCartier("Ferentari");
	float mpCamere1V2[3] = { 15,16,17 };
	i1.setMpCamere(3, mpCamere1V2);
	//cout << "Adresa imobilului 1 updated este: " << i1.getAdresaImobil() << endl;
	//cout << "Imobilul 1 updated se afla in cartierul: " << i1.getCartier() << endl;
	//cout << "Imobilul 1 updated are " << i1.getNrCamere() << " camere" << endl;
	//cout << "Camere din imobilul 1 updated au urmatoare suprafata: ";
	//for (int i = 0; i < i1.getNrCamere(); i++)
		//cout << i1.getMpCamere()[i] << "mp, ";

	//5.Testare constructor de copiere:
	Imobil i2 = i1;
	//i2.afisare();

	//6.Testare operator= :
	Imobil i3;
	//i3.afisare();
	i3 = i1;
	//cout << i3;

	//7.Testare operatori ostream si istream
	Imobil i4;
	//cin >> i4;
	//cout << i4;
	//i3.afisare();

	//8.Testare operator[]:
	//cout << i1[2] << endl;
	i1[1] = 18;

	//9.Testare operator!:
	//cout << i1;
	!i1;
	//cout << i1;

	//10.Testare operator():
	string cartier = (string)i1;
	//cout << endl << cartier;
	//cout << i3;

	//11.Testare operator++, operator++(int),operator--, operator--(int)
	//cout << ++i3;
	i3++;
	//cout << i3;
	//cout << i3;
	//cout << --i3;
	//i3--;
	//cout << i3;

	//12.Testare operator+=:
	Imobil i6 = i3 + 20;
	//cout << i6;

	//13.Testare metoda adaugare camera noua pe prima pozitie;
	//cout << i1;
	i1.adaugareCamPrimaPoz(15);
	//cout << i1;


	//FISIERE TEXT
	//Afisare intr-un fisier text
	ofstream fileOUT("test1.txt", ios::out);
	fileOUT << i1;
	fileOUT.close();
	//cout << i1;
	//Citirea dintr-un fisier text
	Imobil i8;
	//cout << i8;
	ifstream fileIN("test1.txt", ios::in);
	if (fileIN.is_open()) {
		fileIN >> i8;
	}
	else {
		cout << "Fisierul cautat nu exista!" << endl;
	}

	////FISIERE CSV
	//export
	i1.exportCSV("CSV.csv");
	//i0.exportCSV("CSVexportare.csv");
	//import
	Imobil i9;
	i9.importCSV("CSV.csv");
	//cout << i9;


	////FISIERE BINARE
	//serializare
	i1.scriereBIN("binar.bin");
	//deserializare
	Imobil BINARY;
	BINARY.citireBIN("binar.bin");
	//cout << BINARY;




	//A G E N T
	Agent a0;
	//cout << a0;
	//1.Testare functie afisare:
	//a0.afisare();

	//2.Testare constructor cu toti parametrii:
	float valVanzariAnterioare1[6] = { 50000,30000,60000,100000,50000,30000 };
	Agent a1("Trambitasu", "Serban", 7, 6, valVanzariAnterioare1, 3800, 1);
	Agent a10("Lovinescu", "Alexandru", 7, 6, valVanzariAnterioare1, 5000, 1);
	Agent a11("Popescu", "Liviu", 7, 6, valVanzariAnterioare1, 5000, 1);
	Agent a12("Gheorge", "Matei", 7, 6, valVanzariAnterioare1, 5000, 1);
	Agent a13("Matei", "Adrian", 7, 6, valVanzariAnterioare1, 5000, 1);

	//a1.afisare();

	//3.Testare constructor de copiere:
	Agent a2 = a1;
	//a2.afisare();

	//4.Testare operator=:
	Agent a3;
	//a3.afisare();
	a3 = a2;
	//cout << a3;

	//5.Testare operatori ostream si istream:
	Agent a4;
	//cout<<a4;
	//cin >> a4;
	//cout << a4;
	//a3.afisare();

	//6. Testare operator indexare:
	//ne arata valoare unei tranzactii facute de agent
	//cout << endl << "Valoare tranzactiei nr.4 din portofoliul agentului Serban Trambitasu:";
	float val4 = a1[4];
	//cout << val4;

	//7.Testare operator++,operator++(int),operator--,operator--(int): 
	Agent a5 = a1++;
	a5++;
	a5--;
	--a5;
	//cout << a5;

	//8.Testare operator+;
	//adauga o noua tranzactie in portofoliul agentului
	//cout << a1<<endl;
	a4 = a1 + 100000;
	//cout << a4;

	//9.Testare operator!:
	//cout << a4;
	//cout << endl << "Retragerea acreditarii lui Serban Trambitasu" << endl;
	!a4;
	//cout << a4;

	//10.Testare operator():
	int aniExperientaTrambitasu = (int)a4;
	float salariuDeBazaTrambitasu = (float)a4;
	//cout << "Serban Trambitasu, agentul tau imobiliar are " << aniExperientaTrambitasu << "ani de experienta" << endl;
	//cout << endl << "Trambitasu castiga lunar, minim" << salariuDeBazaTrambitasu << "lei" << endl;



	//A G E N T   I M O B I L I A R
	AgentImobiliar ai0;
	//cout << ai0;
	float valVanzariAnterioare4[3] = { 66000,55000,100000 };
	AgentImobiliar ai1("Priza", "Cristian", 7, 3, valVanzariAnterioare4, 3800, 1, 5, "REMAX", 1);
	//cout << ai1;
	AgentImobiliar ai2 = ai0;
	//cout << ai2;
	ai2 = ai1;
	//cout << ai2;

	//Exemplu de up-Casting
	Agent UpCast = ai1;
	/*cout << endl << UpCast;
	cout << endl << ai1;*/

	//Exemplu de down-Casting
	AgentImobiliar DownCast = a1;
	//cout << endl << DownCast;
	
	//virtualizare
	Agent* pointerAg = new Agent(a1);
	Agent* pointerAgIm = new AgentImobiliar(ai1);
	//pointerAg->bonusAngajatulLunii();
	//pointerAgIm->bonusAngajatulLunii();

	//functie virtuala pura

	bonusAgentiClsAbs* pointerClsAbsA = new Agent(a1);
	bonusAgentiClsAbs* pointerClsAbsAI = new AgentImobiliar(ai1);

	//pointerClsAbsA->bonusVechime(12);
	//pointerAgIm->bonusVechime(12);

	// S T L 
	// V E C T O R
	vector<Agent> vectorAgent;
	//populam vectorul cu agenti
	vectorAgent.push_back(a1);
	vectorAgent.push_back(a10);
	vectorAgent.push_back(a11);
	vectorAgent.push_back(a12);
	vectorAgent.push_back(a13);
	//cout << endl << "Vectorul contine " << vectorAgent.size() << " obiecte." << endl;
	//afisare + iterator
	vector<Agent>::iterator vIterator;
	/*for (vIterator = vectorAgent.begin(); vIterator != vectorAgent.end(); vIterator++)
		cout << *vIterator;*/

	//S E T
	set<Imobil> setImobil;
	setImobil.insert(i1);
	setImobil.insert(i10);
	setImobil.insert(i11);
	setImobil.insert(i12);
	set<Imobil>::iterator sIterator;
	/*for (sIterator = setImobil.begin(); sIterator != setImobil.end(); sIterator++)
		cout << *sIterator;*/

	//P R O P R I E T A R
	Proprietar p0;
	//cout << p0;

	//1.Testare constructor cu toti parametrii:
	float valPropVanduteAnterior[2] = { 100000,500000 };
	Proprietar p1("Gigi", "Becali", "Manager echipa fotbal", 64, i1, 2, valPropVanduteAnterior, 1);
	//cout << p1;

	//2.Testare constructor de copiere:
	Proprietar p2 = p1;
	//cout << p2;

	//3.Testare operator=:
	Proprietar p3;
	p3 = p1;
	//cout << p3;

	//4.Testare operator ostream si istream:
	Proprietar p4;
	/*	cin >> p4;*/
	//cout << p4;
	//cin >> p4;
	//cout << p4;

	//5.Testare operator[]:
	float valProp = p1[1];
	//cout <<endl<< "Valoare ultimei proprietatii vandute de primul proprietar este de " << valProp << "lei." << endl;
	//cout << p1;

	//6.Testare operator++, operator++(int), operator--, operator--(int):
	p1++;
	//cout << p1;
	p1--;
	//cout << p1;

	//7.Testare operator():
	string numeProp1 = (string)p1;
	int varstaProp1 = (int)p1;
	//cout << "Numele Proprietarului 1 este " << numeProp1<<" si are "<<varstaProp1<<" ani!" << endl;

	//8.Testare operator!:
	//cout << p1;
	//cout << "Proprietarul 1 nu mai este rezident rezident" << endl;
	!p1;
	//cout << p1;




	// C U M P A R A T O R
	Cumparator c0;
	//c0.afisare();

	//1.Testare constructor cu toti parametrii:
	float valoareImobDetinute1[2] = { 50000,55000 };
	Cumparator c1("Mihaita", "Lovinescu", 43, 60000, 2, valoareImobDetinute1, 1, 1978, 2, 65, 1, 500);
	//c1.afisare();

	//2.Testare constructori de copiere:
	Cumparator c2 = c1;
	//c2.afisare();

	//3.Testare operator=:
	Cumparator c3;
	//c3.afisare();
	c3 = c2;
	//c3.afisare(); 

	//4.Testare subprogram:
	//cout << achizitioneazaImobil(i1, c1);
	//cout << c1;

	//5.Testare operator ostream si istream:
	Cumparator c4;
	//cin >> c4;
	//cout << c4;

	//6.Testare opeartor():
	int prefCumparatorC1AnConstructie = (int)c1;
	int prefCumparatorC1MpImobil = (float)c1;
	//cout << "Cumparatorul 1 prefera ca imobilul pe care il va cumpara sa fie construit maxim in anul " << prefCumparatorC1AnConstructie << "." << endl;
	//cout << "Cumparatorul 1 prefera ca imobilul pe care il va cumpara sa sa aiba minim " << prefCumparatorC1MpImobil << " mp." << endl;

	//7.Testare opeartor[]:
	float valoareImobilAnteriorCumparator = c1[1];
	//cout << "Valoare imobilului detinut anterior de catre cumparator este de " << valoareImobilAnteriorCumparator << " euro." << endl;

	//8.Testare operator!:
	//cout << "Este cumparatorul 1 eligibil de credit bancar? (0=NU / 1=DA) -" << c1.getEligibilDeCredit() << "-" << endl;
	//!c1;
	//cout << "Cumparatorul 1 mai este eligibil de credit dupa schimbarea locului de munca? (0=NU / 1=DA) -" << c1.getEligibilDeCredit() << "-" << endl;

	//9.Testare operator++,operator++(),operator--,operator--(); 
	//cout << c1;
	c1++;
	//cout << c1;
	c1--;
	//cout << c1;

	//10.Testare opeartor+:
	Cumparator c5 = c1 + 20000;
	//cout << c5;



	//Contract
	Contract co0;
	//cout << co0;
	string numeClauze1[3] = { "Anulare","Nerespectare","Incheiere" };
	float valoareClauze1[3] = { 20000,10000,30000 };
	Contract co1(1, "Contract de vanzare-cumparare", c1, p1, plataCash, "10/06/2022", 3, numeClauze1, valoareClauze1, 1);
	//cout << co1;
	Contract co2;
	//cin >> co2;
	//cout << co2;
	co2 = co1;
	//cout << co2;
	Contract co3 = co2;
	//cout << co3;
	//indexare
	string numeClauza2 = co1[2];
	//cout << "Numele celei de a treia clauze din contractul 1 este " << numeClauza2 << endl;
	//operator + adaugare clauza+ numele ei
	Contract co4 = co1 + numeClauza2;
	//cout << co4;
	//operatorul ! ce schimba daca exista clauza de forta majora in contract
	//cout << co4;
	!co4;
	//cout << co4;
	string dataIncheiereContract1 = (string)co1;
	//cout << "Data la care se incheie primul contract este " << dataIncheiereContract1;

	//Testare gasire apartament daca apartamentul este pliabil pe cerintele clientului va returna 1 daca nu 0
	//imobilulPerfect(i1, c1);


	

	system("Color 1");
	cout <<endl<< "\tBun venit la BuyRealEstate by Epurescu Alexandru(Meniu neterminat)" << endl;
	cout << endl << "Pentru a incepe introduceti alge-ti-va profilul:"<<endl;
	cout << "1.Admin" << endl;
	cout << "2.Client" << endl;
	int tasta;
	cin >> tasta;
	switch (tasta)
{
	case 1:
	{
		system("cls");
		system("Color 4");
		cout << "Pentru a accesa contul de admin introduceti codul pin:" << endl;
		int pin;
		cin >> pin;
		if (pin == 1234)
		{
			system("cls");
			system("Color 2");
			cout << endl << "Pin-ul a fost corect"<<endl;
			cout << endl << "Introduceti numarul aferent clasei care va intereseaza!" << endl;
			//system("pause");
			//system("cls");
			system("Color 0B");
			cout << endl << endl << endl;
			cout << "1.Imobil" << endl;
			cout << "2.Proprietar" << endl;
			cout << "3.Agent" << endl;
			cout << "4.Cumparator" << endl;
			cout << "5.Contract" << endl<<endl;
			int x;
			cout << "\t";
			cin >> x;
			switch (x)
			{
				case 1:
				{


				}
				case 2:
				{


				}
				case 3:
				{


				}
				case 4:
				{


				}
				case 5:
				{


				}
			}
		}
		else
		{
			cout << endl << "Codul pin introdus este gresit";
			return 0;
		}
	}
	case 2:
	{
		system("cls");
		system("Color D");
		cout << endl << "Carui agent sunteti arondat:" << endl;
		cout << "1. " << a1.getNume() << " " << a1.getPrenume() << endl;
		cout << "2. " << a10.getNume() << " " << a10.getPrenume() << endl;
		cout << "3. " << a11.getNume() << " " << a11.getPrenume() << endl;
		cout << "4. " << a12.getNume() << " " << a12.getPrenume() << endl;
		cout << "5. " << a13.getNume() << " " << a13.getPrenume() << endl;
	
	}
	
	
	
}


	return 0;
	}
