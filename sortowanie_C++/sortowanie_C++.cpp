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



int main() {

	int rozmiar;
	cout << "Podaj ile liczb wylosowac: ";
	cin >> rozmiar;
	
	int *tablica = new int[rozmiar];
	losowanie(tablica, rozmiar);
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "wylosowane[" << i << "] = " << tablica[i] << endl;
	
	
	getchar();
	getchar();
	delete[] tablica;
	return 0;
}


