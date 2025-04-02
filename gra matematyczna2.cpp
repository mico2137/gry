#include <iostream>
#include <cstdlib>
#include <ctime>

// Funkcja obliczająca największy wspólny dzielnik
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Funkcja upraszczająca ułamek
void simplify(int &numerator, int &denominator) {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}

// Struktura reprezentująca liczbę mieszaną
struct Mixed {
    int whole; // część całkowita
    int num;   // licznik części ułamkowej
    int den;   // mianownik części ułamkowej
};

// Konwersja liczby mieszanej na ułamek niewłaściwy
void mixedToImproper(const Mixed &m, int &numerator, int &denominator) {
    numerator = m.whole * m.den + m.num;
    denominator = m.den;
}

// Konwersja ułamka niewłaściwego na liczbę mieszaną
Mixed improperToMixed(int numerator, int denominator) {
    simplify(numerator, denominator);
    Mixed m;
    m.whole = numerator / denominator;
    m.num = numerator % denominator;
    m.den = denominator;
    if (m.num == 0) {
        m.den = 1;
    } else {
        int g = gcd(m.num, m.den);
        m.num /= g;
        m.den /= g;
    }
    return m;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    const int rounds = 5;
    int score = 0;

    // Wybór trybu gry
    std::cout << "Witaj w grze z dodawaniem liczb mieszanych (ze wspólnym mianownikiem)!\n";
    
    // Wybór poziomu trudności
    std::cout << "\nWybierz poziom trudności:\n";
    std::cout << "1 - Łatwy\n";
    std::cout << "2 - Średni\n";
    std::cout << "3 - Trudny\n";
    std::cout << "Twój wybór: ";
    
    int difficulty;
    std::cin >> difficulty;
    
    // Ustalamy zakresy w zależności od poziomu
    int wholeMax, denomMin, denomMax;
    switch(difficulty) {
        case 1: // Łatwy
            wholeMax = 5;
            denomMin = 2;
            denomMax = 9;
            break;
        case 2: // Średni
            wholeMax = 10;
            denomMin = 2;
            denomMax = 12;
            break;
        case 3: // Trudny
            wholeMax = 20;
            denomMin = 2;
            denomMax = 20;
            break;
        default:
            std::cout << "Niepoprawny wybór poziomu, ustawiono poziom Łatwy.\n";
            wholeMax = 5;
            denomMin = 2;
            denomMax = 9;
    }

    // Losujemy wspólny mianownik dla obu liczb mieszanych
    int commonDenom = std::rand() % (denomMax - denomMin + 1) + denomMin;
    
    for (int i = 0; i < rounds; i++) {
        Mixed m1, m2;
        // Losujemy część całkowitą z przedziału 1 - wholeMax
        m1.whole = std::rand() % wholeMax + 1;
        m2.whole = std::rand() % wholeMax + 1;
        // Ustawiamy wspólny mianownik
        m1.den = commonDenom;
        m2.den = commonDenom;
        // Losujemy licznik części ułamkowej z przedziału 1 do (commonDenom - 1)
        m1.num = std::rand() % (commonDenom - 1) + 1;
        m2.num = std::rand() % (commonDenom - 1) + 1;

        // Konwersja liczb mieszanych na ułamki niewłaściwe
        int num1, den1, num2, den2;
        mixedToImproper(m1, num1, den1);
        mixedToImproper(m2, num2, den2);

        // Dodawanie ułamków: num1/den1 + num2/den2
        int result_num = num1 * den2 + num2 * den1;
        int result_den = den1 * den2;
        simplify(result_num, result_den);
        Mixed result = improperToMixed(result_num, result_den);

        // Wyświetlamy zadanie
        std::cout << "\nRunda " << i + 1 << ":\n";
        std::cout << "Oblicz: " << m1.whole << " " << m1.num << "/" << m1.den 
                  << " + " << m2.whole << " " << m2.num << "/" << m2.den << "\n";

        // Pobieramy odpowiedź od użytkownika
        int user_whole, user_num, user_den;
        std::cout << "Podaj część całkowitą wyniku: ";
        std::cin >> user_whole;
        std::cout << "Podaj licznik części ułamkowej: ";
        std::cin >> user_num;
        std::cout << "Podaj mianownik części ułamkowej: ";
        std::cin >> user_den;

        // Sprawdzamy odpowiedź
        if (user_whole == result.whole && user_num == result.num && user_den == result.den) {
            std::cout << "Brawo! Prawidłowa odpowiedź.\n";
            score++;
        } else {
            std::cout << "Niestety, błędna odpowiedź.\n";
            std::cout << "Prawidłowy wynik to: " << result.whole << " " 
                      << result.num << "/" << result.den << "\n";
        }
    }

    std::cout << "\nTwój wynik: " << score << " na " << rounds << " rund.\n";
    return 0;
}
