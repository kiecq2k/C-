#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ZAKRES 20 // najwieksza liczba kolumn

int wczytaj_int(int lewy,int prawy);
void wczytaj_tab(int tab[][ZAKRES], int n);
void wypisz_tab(int tab[][ZAKRES], int n);
void dodaj_kolumny(int tab[][ZAKRES], int n);

int main()
{
	int tab[ZAKRES][ZAKRES]; // tablica liczb
	int n = wczytaj_int(0, ZAKRES); // liczba wierszy i kolumn tabeli
	wczytaj_tab(tab, n);
	wypisz_tab(tab, n);
	printf("Dodaje kolumny...");
	Sleep(1000);
	dodaj_kolumny(tab, n);
	wypisz_tab(tab, n);
	return 0;
}

int wczytaj_int(int lewy,int prawy)
{
	printf("Podaj liczbe %d< n <=%d : ", lewy, prawy);
	int x; // liczba podana przez uzytkownika
	while (scanf_s("%d", &x) != 1 || x <= lewy || x > prawy || getchar() != '\n')
	{
		printf("Bledne dane.Popraw: ");
		while (getchar() != '\n')
		{
			;
		}
	}
	return x;
}

void wczytaj_tab(int tab[][ZAKRES], int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		int liczba = 1;
		for (int j = 0; j < n; ++j)
		{
			if (j > i)
			{
				tab[i][j] = ++liczba;
			}
			else if (j == i)
			{
				tab[i][j] = liczba;
			}
			else
			{
				tab[i][j] = rand() % 5;
			}
		}
	}
}

void wypisz_tab(int tab[][ZAKRES], int n)
{
	putchar('\n');
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%3d", tab[i][j]);
		}
		putchar('\n');
	}
}

void dodaj_kolumny(int tab[][ZAKRES], int n)
{
	/*for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tab[j][i] += tab[j][0];
		}
	}*/
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			tab[i][j] += tab[i][0];
		}
	}
}