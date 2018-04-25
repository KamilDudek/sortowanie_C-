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
	rozmiar = nowy_rozmiar;
}

 /*
* Algorytm sortowania Quicksort
*/

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

/*
* Algorytm sortowania przez scalanie
*/

template <typename T>
void laczenie_sc(T *tab, int pierwszy, int srodek, int ostatni)
{
	int i, j, q;
	int *t = new int[ostatni + 1];
	for (i = pierwszy; i <= ostatni; i++)
		t[i] = tab[i];  // Skopiowanie danych do tablicy pomocniczej
	i = pierwszy; j = srodek + 1; q = pierwszy;                 // Ustawienie wskaznikow tablic
	while (i <= srodek && j <= ostatni) {		  // Przenoszenie danych z sortowaniem ze zbiorow pomocniczych do tablicy glownej
		if (t[i]<t[j])
			tab[q++] = t[i++];
		else
			tab[q++] = t[j++];
	}
	while (i <= srodek)  tab[q++] = t[i++];	// Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbioru sie skoonczy
	delete[]t;
}


template <typename T>
void scalanie(T *tab, int pierwszy, int ostatni)
{
	int srodek;
	if (pierwszy < ostatni) {
		srodek = (pierwszy + ostatni) / 2;
		scalanie(tab, pierwszy, srodek);    // Dzielenie lewej czesci
		scalanie(tab, srodek + 1, ostatni);   // Dzielenie prawej czesci
		laczenie_sc(tab, pierwszy, srodek, ostatni);   
	}
}
/*
* Algorytm sortowanie introsort
*/
template <typename T>
void IntroSort(T *tab, int p, int k)
{
	int wywolania = podzial(tab, p, k);
	if (wywolania >(2 * log(k)))
	{
		sortowanie_przez_kopcowanie(tab, k);
	}
	else
	{
		quicksort(tab, p, k);
	}
}

template <typename T>
void MaxH(T *tab, int rozm, int k)
{
	int l = (k + 1) * 2 - 1;
	int r = (k + 1) * 2;
	int najwiekszy = 0;

	if (l < rozm && tab[l] > tab[k])
		najwiekszy = l;
	else
		najwiekszy = k;

	if (r < rozm && tab[r] > tab[najwiekszy])
		najwiekszy = r;

	if (najwiekszy != k)
	{
		int temp = tab[k];
		tab[k] = tab[najwiekszy];
		tab[najwiekszy] = temp;

		MaxH(tab, rozm, najwiekszy);
	}
}
template <typename T>
void sortowanie_przez_kopcowanie(T *tab, int k)
{
	int rozm = k;
	for (int p = (rozm - 1) / 2; p >= 0; --p)
		MaxH(tab, rozm, p);

	for (int i = k - 1; i > 0; --i)
	{
		swap(tab[i], tab[0]);
			--rozm;
		MaxH(tab, rozm, 0);
	}
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