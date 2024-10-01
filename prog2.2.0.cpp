#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <vector>


// Функция для приведения строки к нижнему регистру
std::string toLower(const std::string& str) {
    std::string result = str;
    for (long unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            result += str[i] + 32;  // Преобразование символов в нижний регистр
        } else {
            result += str[i];
        }
    }
    return result;
}

// Проверка, является ли слово однокоренным с "любовь" или "любить"
bool isLoveWord(const std::string& word) {
    std::string lowerWord = toLower(word);

    // Список слов и корней, связанных с любовью
    std::set<std::string> loveRoots = {"love", "love,", "love?", "love!",  "darling", "darling,", "darling!", "darling?", "lovely"};
    
    // Проверяем, содержит ли слово корень "люб" или "влюб"
    for (const auto& root : loveRoots) {
        if (lowerWord.find(root) != std::string::npos) {
            return true;
        }
    }
    return false;
}

// Разбиваем строку на слова вручную
std::vector<std::string> splitTextIntoWords(const std::string& text) {
    std::vector<std::string> words;
    std::string word = "";
    for (long unsigned int i = 0; i < text.size(); ++i) {
        char ch = text[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= 'а' && ch <= 'я') || (ch >= 'А' && ch <= 'Я')) {
            word += ch;  // Добавляем символ в текущее слово
        } else {
            if (!word.empty()) {
                words.push_back(word);  // Если слово накопилось, добавляем его в вектор
                word = "";
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);  // Добавляем последнее слово
    }
    return words;
}

int main() {
    // Входной текст
    std::string text;
    std::cout << "Введите текст: ";
    getline(std::cin, text);

    // Разбиваем текст на слова
    std::vector<std::string> words = splitTextIntoWords(text);

    // Словарь для хранения количества вхождений слов
    std::map<std::string, int> loveWords;

    // Считаем все слова, связанные с любовью
    for (const auto& word : words) {
        if (isLoveWord(word)) {
            std::string lowerWord = toLower(word);  // Приводим к нижнему регистру
            loveWords[lowerWord]++;
        }
    }

    // Выводим список слов о любви по алфавиту с количеством вхождений
    std::cout << "\nСписок слов о любви по алфавиту с количеством вхождений:\n";
    for (const auto& entry : loveWords) {
        std::cout << entry.first << ": " << entry.second <<"\n";
    }

    // Подсчет общего количества слов о любви
    int totalWords = 0;
    for (const auto& entry : loveWords) {
        totalWords += entry.second;
    }

    // Подсчет количества пачек Рафаэлло и конфет
    int raffaelloPacks = totalWords / 1000;
    int raffaelloCandies = (totalWords % 1000) / 15;

    std::cout << "\nОбщее количество слов о любви: " << totalWords << "\n";
    std::cout << "Количество пачек Рафаэлло: " << raffaelloPacks << "\n";
    std::cout << "Количество конфет Рафаэлло: " << raffaelloCandies << "\n";

    return 0;
} 


// код не мой а  gpt  ждите обновлений :)
//ну или когда я смогу понять код настолько что смогу объяснить его xD
