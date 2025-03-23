#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

void askQuestion(int questionNumber, int maxRange, int& score) {
    // Losowanie dwóch liczb w zadanym zakresie
    int num1 = rand() % maxRange + 1;
    int num2 = rand() % maxRange + 1;
    int correctAnswer;
    int playerAnswer;

    // Mno¿enie
    correctAnswer = num1 * num2;

    std::cout << "Pytanie " << questionNumber << ": " << num1 << " * " << num2 << " = ?" << std::endl;

    // Oczekiwanie na odpowiedŸ gracza
    std::cin >> playerAnswer;

    // Sprawdzanie odpowiedzi
    if (playerAnswer == correctAnswer) {
        std::cout << "Dobrze! Brawo!" << std::endl;
        score++;  // Zwiêkszamy liczbê punktów za poprawn¹ odpowiedŸ
    }
    else {
        std::cout << "Niestety, to nie ta odpowiedŸ. Poprawna odpowiedŸ to: " << correctAnswer << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Inicjalizacja generatora liczb losowych
    int numQuestions = 5;  // Liczba pytañ do rozwi¹zania
    int difficultyLevel;
    int score = 0;  // Zmienna przechowuj¹ca wynik gracza

    std::cout << "Witaj w grze matematycznej!" << std::endl;
    std::cout << "Wybierz poziom trudnoœci:" << std::endl;
    std::cout << "1. £atwy (1-50)" << std::endl;
    std::cout << "2. Œredni (1-100)" << std::endl;
    std::cout << "3. Trudny (1-200)" << std::endl;
    std::cout << "Wybierz poziom (1-3): ";
    std::cin >> difficultyLevel;

    int maxRange;
    switch (difficultyLevel) {
    case 1:
        maxRange = 50;  // £atwy
        break;
    case 2:
        maxRange = 100;  // Œredni
        break;
    case 3:
        maxRange = 200;  // Trudny
        break;
    default:
        std::cout << "Nieprawid³owy wybór. Ustawiono poziom trudnoœci na 'Œredni'." << std::endl;
        maxRange = 100;  // Domyœlny poziom trudnoœci
        break;
    }

    std::cout << "Rozwi¹¿ " << numQuestions << " pytañ w wybranym poziomie trudnoœci!" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();  // Start pomiaru czasu

    // Pêtla po pytaniach
    for (int i = 1; i <= numQuestions; i++) {
        askQuestion(i, maxRange, score);
    }

    auto end = std::chrono::high_resolution_clock::now();  // Zatrzymanie pomiaru czasu
    std::chrono::duration<double> duration = end - start;  // Obliczenie czasu gry

    std::cout << "Czas gry: " << duration.count() << " sekund." << std::endl;
    std::cout << "Twój wynik: " << score << " / " << numQuestions << " punktów!" << std::endl;
    std::cout << "Dziêkujemy za grê!" << std::endl;

    return 0;
}