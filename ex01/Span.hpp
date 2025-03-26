#pragma once

#include <vector>    // std::vector
#include <iostream>  // std::cerr, std::cout, std::endl
#include <algorithm> // std::sort
#include <stdexcept> // std::exception, std::logic_error, std::overflow_error

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::logic_error;
using std::overflow_error;
using std::vector;

// Span sınıfı, belirli bir kapasite içinde sayı eklemeyi ve en kısa/en uzun mesafeyi hesaplamayı sağlar
class Span
{
private:
    unsigned int _maxSize; // Maksimum kapasite
    vector<int> _numbers;  // Sayıları saklayan vektör

public:
    Span(unsigned int N);               // Kurucu fonksiyon
    Span(const Span &other);            // Kopya kurucu
    Span &operator=(const Span &other); // Atama operatörü aşırı yükleme
    ~Span();                            // Yıkıcı fonksiyon

    void addNumber(int number);                                              // Tek bir sayı ekleme fonksiyonu
    void addNumbers(vector<int>::iterator begin, vector<int>::iterator end); // Birden fazla sayı ekleme fonksiyonu
    int shortestSpan();                                                      // En kısa mesafeyi hesaplar
    int longestSpan();                                                       // En uzun mesafeyi hesaplar
};
