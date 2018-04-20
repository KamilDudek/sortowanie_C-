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
	int x = tab[(pierwszy + ostatni) / 2];
	int p = pierwszy, o = ostatni;
	do
	{

		while (tab[p] < x)
			p++;
		while (x < tab[o])
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


int main() {

	int rozmiar;
	cout << "Podaj ile liczb wylosowac: ";
	cin >> rozmiar;
	
	int *tablica = new int[rozmiar];
	losowanie(tablica, rozmiar);
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "wylosowane[" << i << "] = " << tablica[i] << endl;
	
	quickSort(tablica, 0, rozmiar - 1); // wywolanie funkcji sortujacej
	cout << endl << "Quicksort" << endl;
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	getchar();
	getchar();
	delete[] tablica;
	return 0;
}


