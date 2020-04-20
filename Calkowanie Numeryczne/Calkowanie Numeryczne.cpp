#include <iostream>

#define A 0
#define B 2

double trapezy(double a, double b, double przedzialy)
{
    double odstep = (b - a) / przedzialy;
    double suma = 0;
    for (int i = 0; i < przedzialy; i++)
    {
        suma += ((((i + 1.0) * odstep) - (i * odstep)) / 2) * (1 / (1 + 2 * (i * odstep)) + (1 / (1 + 2 * ((i + 1.0) * odstep))));

    }
    return suma;
}

double parabole(double a, double b, double przedzialy)
{
    double odstep = (b - a) / przedzialy;
    double suma = 0;
    for (int i = 0; i < przedzialy; i++)
    {
        suma += (((i + 1.0) * odstep) - (i * odstep)) / 6 * (1 / (1 + 2 * (i * odstep)) + 4 * (1 / (1 + 2 * ((i * odstep + ((i + 1.0) * odstep)) / 2))) + (1 / (1 + 2 * ((i + 1.0) * odstep))));
    }
    return suma;
}

void porownaj(double wynik_numeryczny)
{
    double wynik_analityczny = 0.80472;
    std::cout << " Wynik: " << wynik_numeryczny << std::endl;
    std::cout << " Roznica miedzy wynikiem analitycznym: " << abs(wynik_analityczny - wynik_numeryczny) << std::endl;
}

int main()
{
    double wynik_numeryczny;
    int choice;
    std::cout << "1. Calkowanie za pomoca wzoru trapezow" << std::endl
        << "2. Calkowanie za pomoca wzoru parabol" << std::endl
        << "3. Calkowanie za pomoca wzoru trapezow dla 10 przedzialow" << std::endl
        << "4. Stopniowe zwiekszanie przedzialow wzorem trapezow" << std::endl
        << "5. Stopniowe zwiekszanie przedzialow wzorem parabol" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        wynik_numeryczny = trapezy(A, B, 1);
        porownaj(wynik_numeryczny);
        break;
    case 2:
        wynik_numeryczny = parabole(A, B, 1);
        porownaj(wynik_numeryczny);
        break;
    case 3:
        wynik_numeryczny = trapezy(A, B, 10);
        porownaj(wynik_numeryczny);
        break;
    case 4:
        for (int i = 1; i <= 10; i++)
        {
            wynik_numeryczny = trapezy(A, B, i);
            std::cout << "Liczba Przedzialow: " << i;
            porownaj(wynik_numeryczny);
        }         
        break;
    case 5:
        for (int i = 1; i <= 10; i++)
        {
            wynik_numeryczny = parabole(A, B, i);
            std::cout << "Liczba Przedzialow: " << i;
            porownaj(wynik_numeryczny);
        }
        break;
    }
}
