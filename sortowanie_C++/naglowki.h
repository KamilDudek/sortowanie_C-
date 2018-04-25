#pragma once
#ifndef naglowki_H
#define naglowki_H
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <conio.h>
#include<algorithm>
#include <fstream> 
#include<string>
using namespace std;

template <typename T>
bool sprawdzenie(T *tab, int rozmiar);
template <typename T>
void losowanie(T *tab, int rozmiar);
template <typename T>
void dodawanie(T *&tab, int &rozmiar);
template <typename T>
int podzial(T *tab, int pierwszy, int ostatni);
template <typename T>
void quicksort(T *tablica, int p, int r);
template <typename T>
void laczenie_sc(T *tab, int pierwszy, int srodek, int ostatni);
template <typename T>
void scalanie(T *tab, int pierwszy, int ostatni);

template <typename T>
void IntroSort(T *tab, int p, int k);

template <typename T>
void MaxH(T *tab, int rozm, int k);

template <typename T>
void sortowanie_przez_kopcowanie(T *tab, int k);


#endif