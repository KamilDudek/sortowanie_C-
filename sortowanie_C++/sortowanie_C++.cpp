// sortowanie_C++.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include<cstdlib>
#include<ctime>
#include <conio.h>

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
	for (int i = 1; i <= rozmiar; i++) {
		tab[i] = rand() % przedzial + zakres ;
	}
}

template <typename T>
void Sortowanie(T tab[], int left, int right)
{
	int i = left;
	int j = right;
	int x = tab[(left + right) / 2];
	do
	{
		while (tab[i] < x)
			i++;

		while (tab[j] > x)
			j--;

		if (i <= j)
		{
			swap(tab[i], tab[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) Sortowanie(tab, left, j);

	if (right > i) Sortowanie(tab, i, right);

}



int main() {
	int tablica[1000];
	int rozmiar;
	cout << "Podaj ile liczb wylosowac: ";
	cin >> rozmiar;
	losowanie(tablica, rozmiar);
	for (int i = 1; i <= rozmiar; i++) {
		cout << tablica[i] << endl;
	}
	Sortowanie(tablica, 0, rozmiar - 1); // wywolanie funkcji sortujacej

	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	getchar();
	getchar();
	return 0;
}


