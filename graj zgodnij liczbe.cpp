#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    int liczba = std::rand() % 100 + 1; // Losowanie liczby od 1 do 100
    int strzal;
    int proby = 0;
    
    std::cout << "Witaj w grze 'Zgadnij liczbę'!" << std::endl;
    std::cout << "Zgadnij liczbę od 1 do 100." << std::endl;
    
    std::clock_t start = std::clock(); // Start licznika czasu
    
    do {
        std::cout << "Podaj liczbę: ";
        std::cin >> strzal;
        proby++;
        
        if (strzal > liczba) {
            std::cout << "Za duża! Spróbuj ponownie." << std::endl;
        } else if (strzal < liczba) {
            std::cout << "Za mała! Spróbuj ponownie." << std::endl;
        } else {
            std::clock_t end = std::clock(); // Zatrzymanie licznika czasu
            double czas = (double)(end - start) / CLOCKS_PER_SEC; // Obliczenie czasu w sekundach
            std::cout << "Gratulacje! Zgadłeś liczbę " << liczba << " w " << proby << " próbach!" << std::endl;
            std::cout << "Czas gry: " << czas << " sekund." << std::endl;
        }
    } while (strzal != liczba);
    
    
    
    }