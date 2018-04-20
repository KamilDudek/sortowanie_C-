// sortowanie_C++.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
#include <conio.h>
#include<algorithm>
#include <fstream> 

using namespace std;



template <typename T>
void losowanie(T tab[], int rozmiar) {
	srand(time(0));
	T przedzial,zakres;
	cout << "Podaj przedzial losowania liczb:";
	cin >> przedzial;
	cout << "Podaj od jakiej liczby bedziesz losowal:";
	cin >> zakres;
	cout << endl;
	for (int i = 0; i <= rozmiar; i++) {
		tab[i] = rand() % przedzial + zakres ;
	}
}

void quickSort(int tab[], int pierwszy, int ostatni)
{
	int pivot = tab[(pierwszy + ostatni) / 2]; 
	int p = pierwszy, o = ostatni;
	do
	{

		while (tab[p] < pivot)
			p++;
		while (pivot < tab[o])
			o--;

		if (p <= o)
		{
			swap(tab[p], tab[o]);
			p++;
			o--;
		}
	}

	while (p <= o);

	if (pierwszy < o) quickSort(tab, pierwszy, o);
	if (p < ostatni) quickSort(tab, p, ostatni);
}
//podzial tablicy
void podzial_sc(int tab[], int pierwszy, int srodek, int ostatni)
{
	int i, j, q;
	int *t = new int[ostatni + 1];
	for (i = pierwszy; i <= ostatni; i++)
		t[i] = tab[i];  // Skopiowanie danych do tablicy pomocniczej
	i = pierwszy; j = srodek + 1; q = pierwszy;                 // Ustawienie wska�nik�w tablic
	while (i <= srodek && j <= ostatni) {		  // Przenoszenie danych z sortowaniem ze zbior�w pomocniczych do tablicy g��wnej
		if (t[i]<t[j])
			tab[q++] = t[i++];
		else
			tab[q++] = t[j++];
	}
	while (i <= srodek) tab[q++] = t[i++];	// Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbi�r si� sko�czy�
	delete[]t;
}

/*
* Algorytm sortowania przez scalanie
*/
void scalanie(int tab[], int pierwszy, int ostatni)
{
	int srodek;
	if (pierwszy < ostatni) {
		srodek = (pierwszy + ostatni) / 2;
		scalanie(tab, pierwszy, srodek);    // Dzielenie lewej czesci
		scalanie(tab, srodek + 1, ostatni);   // Dzielenie prawej czesci
		podzial_sc(tab, pierwszy, srodek, ostatni);   // 
	}
}

bool sprawdzenie(int tab[], int rozmiar)
{

	for (int i = 0; i < rozmiar - 1; i++)
	{

		if (tab[i] > tab[i + 1])
		{
			cerr << "\nZle posortowana" << endl;;
			system("pause");
			return false;
		}
	}
	return true;

}



int main() {

	int rozmiar;
	cout << "Podaj ile liczb wylosowac: ";
	cin >> rozmiar;
	
	int *tablica = new int[rozmiar];
	losowanie(tablica, rozmiar);
	for (int i = 0; i < rozmiar; i++) // wypisanie tablicy
		cout << "wylosowane[" << i << "] = " << tablica[i] << endl;
	
	quickSort(tablica, 0, rozmiar - 1); // wywolanie funkcji sortujacej
	cout << endl << "Quicksort" << endl;
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	cout << endl << "Scalanie" << endl;
	scalanie(tablica, 0, rozmiar - 1);
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	getchar();
	getchar();
	delete[] tablica;
	return 0;
}


