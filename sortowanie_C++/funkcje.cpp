#include "naglowki.h"

using namespace std;


template <typename T>
void losowanie(T *tab, int rozmiar)
{
	srand(time(0));
	T przedzial, zakres;
	int *tablica = new int[rozmiar];
	cout << "Podaj przedzial losowania liczb (do jakiej liczby max, inna niz 0): ";
	cin >> przedzial;
	cout << "Podaj od jakiej liczby bedziesz losowal (od jakiej min): ";
	cin >> zakres;
	cout << endl;
	for (int i = 0; i <= rozmiar; i++)
	{
		tab[i] = rand() % przedzial + zakres;
	}
}
template <typename T>
void dodawanie(T *&tab, int &rozmiar)
{
	srand(time(0));
	T przedzial, zakres;
	int nowy_rozmiar;
	cout << "Podaj ile liczb wylosowac: ";
	cin >> nowy_rozmiar;
	nowy_rozmiar += rozmiar;
	int *tablica = new int[nowy_rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = tab[i];
	}
	//delete tab;
	tab = new int[nowy_rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = tablica[i];
	}
	delete tablica;
	cout << "Podaj przedzial losowania liczb (do jakiej liczby max): ";
	cin >> przedzial;
	cout << "Podaj od jakiej liczby bedziesz losowal (od jakiej min): ";
	cin >> zakres;
	cout << endl;
	for (int i = rozmiar; i < nowy_rozmiar; i++)
	{
		tab[i] = rand() % przedzial + zakres;
	}
	//delete rozmiar;
	rozmiar = nowy_rozmiar;
}

template <typename T>
int podzial(T *tab, int pierwszy, int ostatni)
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
void quicksort(T *tablica, int p, int r) // sortowanie szybkie
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
void laczenie_sc(T *tab, int pierwszy, int srodek, int ostatni)
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
	while (i <= srodek)  tab[q++] = t[i++];	// Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbi�r si� sko�czy�
	delete[]t;
}

/*
* Algorytm sortowania przez scalanie
*/

template <typename T>
void scalanie(T *tab, int pierwszy, int ostatni)
{
	int srodek;
	if (pierwszy < ostatni) {
		srodek = (pierwszy + ostatni) / 2;
		scalanie(tab, pierwszy, srodek);    // Dzielenie lewej czesci
		scalanie(tab, srodek + 1, ostatni);   // Dzielenie prawej czesci
		laczenie_sc(tab, pierwszy, srodek, ostatni);   // 
	}
}

template <typename T>
void fixHeap(T *tab, int korzen, int bottom)
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


template <typename T>
void _swap(T *a, T *b) {
	T save = *a;
	*a = *b;
	*b = save;
}
template <typename T>
void heapsort(T *tab, int pierwszy, int ostatni) {
	int i;
	for (int i = (ostatni - 1) / 2; i >= pierwszy; i--) {
		fixHeap(tab, i, ostatni - 1);
	}
	for (i = ostatni - 1; i>pierwszy; i--) {
		_swap(&tab[i], &tab[pierwszy]);
		fixHeap(tab, pierwszy, i - 1);
	}
}


template <typename T>
void introsort_r(T *tab, int pierwszy, int ostatni, int glebokosc) {
	while (ostatni - pierwszy > 0) {
		if (glebokosc = 0)
			heapsort(&tab[pierwszy], pierwszy, ostatni - pierwszy + 1);
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
template <typename T>
void wstawianie(T *tab, int n) {
	int i;
	for (i = 1; i < n; i++) {
		int j, save = tab[i];
		for (j = i; j >= 1 && tab[j - 1] > save; j--)
			tab[j] = tab[j - 1];
		tab[j] = save;
	}
}
template <typename T>
void _introsort(T *tab, int n) {
	introsort_r(tab, 0, n - 1, (int(2 * log(double(n)))));
	wstawianie(tab, n);
}
template <typename T>
bool sprawdzenie(T *tab, int rozmiar)
{

	for (int i = 0; i < rozmiar - 1; i++)
	{

		if (tab[i] > tab[i + 1])
		{
			return false;
		}
	}
	return true;

}