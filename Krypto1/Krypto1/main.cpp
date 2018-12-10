#include <iostream>
#include <string>
#include <stdio.h>
#define ZNAKI 256
#pragma warning(disable:4996)
using namespace std;

int main()
{
	char tekst[ZNAKI];
	FILE *plik1;
	FILE *plik2;
	
	plik1 = fopen("rozszerzenie.txt", "r");
	fgets(tekst, ZNAKI, plik1);
	
	for (int i = 0; i < ZNAKI; i++)
	{
		tekst[i] = toupper(tekst[i]);
	}

	cout << "Nacisnij:" << endl;
	cout << "Szyfrowanie: 1 - Szyfr cezara, 2 - Szyfr afiniczny, 3 - Szyfr Vigenere-a" << endl;
	cout << "Deszyfrowanie: 4 - Szyfr cezara, 5 - Szyfr afiniczny, 6 - Szyfr Vigenere-a" << endl;
	int numer;
	cin >> numer;
	switch( numer )
	{
	case 1:
		for (int i = 0; i < ZNAKI; i++)
		{
			if ((tekst[i] >= 'A') && (tekst[i] <= 'Z')) 
				tekst[i] = char(65 + (tekst[i] - 62) % 26);
		}
		break;

	case 2:
	{
		int a = 3, b = 5;
		for (int i = 0; i < ZNAKI; i++)
		{
			if ((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
				tekst[i] = 'A' + (((tekst[i] - 'A') * a + b) % 26);
		}
		break;
	}
	case 3:
	{
		int a = 0;
		char klucz[] = "KRYPTOLOGIA";
		for (int i = 0; i < ZNAKI; i++)
		{
			if ((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
			{
				tekst[i] = ((tekst[i] - 'A') + (klucz[a % strlen(klucz)] - 'A')) % 26 + 'A';
				a++;
			}
		}
		break;
	}
	case 4:
		for (int i = 0; i < ZNAKI; i++)
		{
			if ((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
				tekst[i] = char(65 + (tekst[i] - 42) % 26);
		}
		break;

	case 5:
	{
		int a = 3, b = 5;
		int x = 1;
		while ((a*x) % 26 != 1) x++;
		
		for (int i = 0; i < ZNAKI; i++) 
		{
				if ((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
					tekst[i] = 'A' + ((x * (tekst[i] - 'A' - b + 26)) % 26);
		}
		break;
	}
	case 6:
	{
		int a = 0;
		char klucz[] = "KRYPTOLOGIA";
		for (int i = 0; i < ZNAKI; i++)
		{
			if ((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
			{
				tekst[i] = ((tekst[i] - 'A') - (klucz[a % strlen(klucz)] - 'A') + 26) % 26 + 'A';
				a++;
			}
		}
		break;
	}
	}

	plik2 = fopen("wynik.txt", "w");
	fputs(tekst, plik2);
	
	fclose(plik1);
	fclose(plik2);

	getchar();
	return 0;
}