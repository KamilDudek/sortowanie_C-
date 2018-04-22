#include <iostream>
#include<cstdlib>
#include<ctime>
#include <conio.h>
#include<algorithm>
#include <fstream> 

using namespace std;

bool sprawdzenie(int tab[], int rozmiar);

template <typename T>
void losowanie(T tab[], int rozmiar) {
	srand(time(0));
	T przedzial, zakres;
	cout << "Podaj przedzial losowania liczb:";
	cin >> przedzial;
	cout << "Podaj od jakiej liczby bedziesz losowal:";
	cin >> zakres;
	cout << endl;
	for (int i = 0; i <= rozmiar; i++) {
		tab[i] = rand() % przedzial + zakres;
	}
}

template <typename T>
int podzial(T tab[], int pierwszy, int ostatni)
{
	int pivot = tab[(pierwszy + ostatni) / 2];
	int p = pierwszy, o = ostatni;
	while (p < o)
	{

		while (tab[p] < pivot)
			p++;
		while (pivot < tab[o])
			o--;

		if (p < o)
		{
			swap(tab[p], tab[o]);
			p++;
			o--;
		}

	}
	return o;

}

template <typename T>
void quicksort(T tablica[], int p, int r) // sortowanie szybkie
{
	int srodek;
	if (p < r)
	{
		srodek = podzial(tablica, p, r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		quicksort(tablica, p, srodek); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		quicksort(tablica, srodek + 1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}


//podzial tablicy

template <typename T>
int laczenie_sc(T tab[], int pierwszy, int ostatni)
{
	int i, j, q, srodek = (pierwszy + ostatni) / 2;
	int *t = new int[ostatni + 1];
	for (i = pierwszy; i <= ostatni; i++)
		t[i] = tab[i];  // Skopiowanie danych do tablicy pomocniczej
	i = pierwszy; j = srodek + 1; q = pierwszy;                 // Ustawienie wska�nik�w tablic
	while (i <= srodek && j <= ostatni) {		  // Przenoszenie danych z sortowaniem ze zbior�w pomocniczych do tablicy g��wnej
		if (t[i]<t[j])
			return tab[q++] = t[i++];
		else
			return tab[q++] = t[j++];
	}
	while (i <= srodek) return tab[q++] = t[i++];	// Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbi�r si� sko�czy�
	delete[]t;
}

/*
* Algorytm sortowania przez scalanie
*/

template <typename T>
void scalanie(T tab[], int pierwszy, int ostatni)
{
	int srodek;
	if (pierwszy < ostatni) {
		srodek = (pierwszy + ostatni) / 2;
		scalanie(tab, pierwszy, srodek);    // Dzielenie lewej czesci
		scalanie(tab, srodek + 1, ostatni);   // Dzielenie prawej czesci
		laczenie_sc(tab, pierwszy, ostatni);   // 
	}
}


void fixHeap(int tab[], int korzen, int bottom)
{
	bool done;
	int maxChild, tmp;
	done = false;
	while ((korzen * 2 <= bottom) && (!done))
	{
		if (korzen * 2 == bottom)
			maxChild = korzen * 2;
		else if (tab[korzen * 2] > tab[korzen * 2 + 1])
			maxChild = korzen * 2;
		else
			maxChild = korzen * 2 + 1;

		if (tab[korzen] < tab[maxChild])
		{
			tmp = tab[korzen];
			tab[korzen] = tab[maxChild];
			tab[maxChild] = tmp;
			korzen = maxChild;

		}
		else
			done = true;
	}
}

/*
* Algorytm sortowania przez kopcowanie
*/
void _swap(int *a, int *b) {
	int save = *a;
	*a = *b;
	*b = save;
}
void heapsort(int tab[], int pierwszy, int ostatni) {
	int i;
	for (int i = (ostatni - 1) / 2; i >= pierwszy; i--) {
		fixHeap(tab, i, ostatni - 1);
	}
	for (i = ostatni - 1; i>pierwszy; i--) {
		_swap(&tab[i], &tab[pierwszy]);
		fixHeap(tab, pierwszy, i - 1);
	}
}



void introsort_r(int tab[], int pierwszy, int ostatni, int glebokosc) {
	while (ostatni - pierwszy > 0) {
		if (glebokosc = 0)
			heapsort(&tab[pierwszy],pierwszy, ostatni - pierwszy + 1);
		else {
			int pivot;
			if (sprawdzenie(tab, ostatni))
				break;
			pivot = podzial(tab, pierwszy, ostatni);
			introsort_r(tab, pivot + 1, ostatni, glebokosc - 1);
			ostatni = pivot - 1;
		}
	}
}
void wstawianie(int tab[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j, save = tab[i];
		for (j = i; j >= 1 && tab[j - 1] > save; j--)
			tab[j] = tab[j - 1];
		tab[j] = save;
	}
}

void _introsort(int tab[], int n) {
	introsort_r(tab, 0, n - 1, (int(2 * log(double(n)))));
	wstawianie(tab, n);
}

bool sprawdzenie(int tab[], int rozmiar)
{

	for (int i = 0; i < rozmiar - 1; i++)
	{

		if (tab[i] > tab[i + 1])
		{
			/*cerr << "\nZle posortowana" << endl;;
			system("pause");*/
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

	quicksort(tablica, 0, rozmiar - 1); // wywolanie funkcji sortujacej
	cout << endl << "Quicksort" << endl;
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	cout << endl << "introspektywne" << endl;
	//scalanie(tablica, 0, rozmiar - 1);
	_introsort(tablica, rozmiar);
	for (int i = 0; i < rozmiar; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	//delete[] tablica;
	getchar();
	getchar();

	return 0;
}

