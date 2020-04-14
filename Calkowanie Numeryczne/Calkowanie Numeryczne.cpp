#include <iostream>

double trapezy(double a, double b,double przedzialy)
{
    double odstep = (b - a) / przedzialy;
    double suma = 0;
    for (int i = 0; i < przedzialy; i++)
    {
        suma += ((((i + 1.0) * odstep) - (i * odstep)) / 2) * (1 / (1 + 2 * (i * odstep)) + (1 / (1 + 2 * ((i + 1.0) * odstep))));

    }
    return suma;
}

double parabole(double a, double b,double przedzialy)
{
    double odstep = (b - a) / przedzialy;
    double suma = 0;
    for (int i = 0; i < przedzialy; i++)
    {
        suma += (((i + 1.0) * odstep) - (i * odstep)) / 6 * (1 / (1 + 2 * (i * odstep)) + 4 * (1 / (1 + 2 * ((i * odstep + ((i + 1.0) * odstep)) / 2))) + (1 / (1 + 2 * ((i + 1.0) * odstep))));
    }
    return suma;
}

int main()
{
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
        std::cout << trapezy(0,2,1);
        break;
    case 2:
        std::cout << parabole(0, 2,1);
        break;
    case 3:
        std::cout << trapezy(0, 2, 10);
        break;
    case 4:
        for (int i = 1; i <= 10; i++)
            std::cout << "Liczba Przedzialow: " << i << " Wynik: " << trapezy(0, 2, i) << std::endl;
        break;
    case 5:
        for (int i = 1; i <= 10; i++)
            std::cout << "Liczba Przedzialow: " << i << " Wynik: " << parabole(0, 2, i) << std::endl;
        break;
    }


}   


