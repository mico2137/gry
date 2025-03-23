#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void askQuestion(int questionNumber, int maxRange, int& score) {
    // Losowanie dw�ch liczb w zadanym zakresie
    int num1 = rand() % maxRange + 1;
    int num2 = rand() % maxRange + 1;
    int correctAnswer;
    int playerAnswer;

    // Mno�enie
    correctAnswer = num1 * num2;

    std::cout << "Pytanie " << questionNumber << ": " << num1 << " * " << num2 << " = ?" << std::endl;

    // Oczekiwanie na odpowied� gracza
    std::cin >> playerAnswer;

    // Sprawdzanie odpowiedzi
    if (playerAnswer == correctAnswer) {
        std::cout << "Dobrze! Brawo!" << std::endl;
        score++;  // Zwi�kszamy liczb� punkt�w za poprawn� odpowied�
    }
    else {
        std::cout << "Niestety, to nie ta odpowied�. Poprawna odpowied� to: " << correctAnswer << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Inicjalizacja generatora liczb losowych
    int numQuestions = 5;  // Liczba pyta� do rozwi�zania
    int difficultyLevel;
    int score = 0;  // Zmienna przechowuj�ca wynik gracza

    std::cout << "Witaj w grze matematycznej!" << std::endl;
    std::cout << "Wybierz poziom trudno�ci:" << std::endl;
    std::cout << "1. �atwy (1-50)" << std::endl;
    std::cout << "2. �redni (1-100)" << std::endl;
    std::cout << "3. Trudny (1-200)" << std::endl;
    std::cout << "Wybierz poziom (1-3): ";
    std::cin >> difficultyLevel;

    int maxRange;
    switch (difficultyLevel) {
    case 1:
        maxRange = 50;  // �atwy
        break;
    case 2:
        maxRange = 100;  // �redni
        break;
    case 3:
        maxRange = 200;  // Trudny
        break;
    default:
        std::cout << "Nieprawid�owy wyb�r. Ustawiono poziom trudno�ci na '�redni'." << std::endl;
        maxRange = 100;  // Domy�lny poziom trudno�ci
        break;
    }

    std::cout << "Rozwi�� " << numQuestions << " pyta� w wybranym poziomie trudno�ci!" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();  // Start pomiaru czasu

    // P�tla po pytaniach
    for (int i = 1; i <= numQuestions; i++) {
        askQuestion(i, maxRange, score);
    }

    auto end = std::chrono::high_resolution_clock::now();  // Zatrzymanie pomiaru czasu
    std::chrono::duration<double> duration = end - start;  // Obliczenie czasu gry

    std::cout << "Czas gry: " << duration.count() << " sekund." << std::endl;
    std::cout << "Tw�j wynik: " << score << " / " << numQuestions << " punkt�w!" << std::endl;
    std::cout << "Dzi�kujemy za gr�!" << std::endl;

    return 0;
}