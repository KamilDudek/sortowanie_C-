#include "naglowki.h"
#include"funkcje.cpp"

using namespace std;

int main() {

	cout << "\n---------------------" << endl;
	cout << "Funkcje sortujace";
	cout << "\n---------------------" << endl;
	int rozmiar;
	cout << "Podaj ile liczb wylosowac: ";
	cin >> rozmiar;
	int *tablica = new int[rozmiar];
	losowanie(tablica, rozmiar);


	int choice;
	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "Funkcje sortujace";
		cout << "\n---------------------" << endl;
		cout << "1.Wyswietlanie tablicy" << endl;
		cout << "2.Quicksort" << endl;
		cout << "3.Scalanie" << endl;
		cout << "4.Introspektywne" << endl;
		cout << "5.Czyszczenie ekranu" << endl;
		cout << "6. Sprawdzenie czy jest posortowana" << endl;
		cout << "7. Dolosowanie liczb do tablicy" << endl;
		cout << "8. Wyjscie z programu" << endl;
		cout << "Wpisz odpowiednia cyfre: ";

		string tmp;
		getline(cin, tmp);
		choice = atoi(tmp.c_str());
		switch (choice)
		{

		case 1:
			for (int i = 0; i < rozmiar; i++)
				cout << "tablica[" << i << "] = " << tablica[i] << endl;
			break;
		case 2:
			quicksort(tablica, 0, rozmiar - 1);
			break;
		case 3:
			scalanie(tablica, 0, rozmiar - 1);
			break;
		case 4:
			IntroSort(tablica,0, rozmiar);
			break;
		case 5:
			system("cls");
			break;
		case 6:
			if (sprawdzenie(tablica, rozmiar) == true)
				cout << "Tablica posortowana poprawnie!!";
			else
				cerr << "Tablica blednie posortowana!!";
			break;
		case 7:
			srand(time(NULL));
			dodawanie(tablica, rozmiar);
			break;
		case 8:
			exit(1);
		default:
			cout << endl << "Bledna komenda!!" << endl;
		}
	}


	delete[]tablica;

	return 0;
}
