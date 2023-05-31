#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

template<typename T>
class Complex         // класс комплексных чисел
{
private:
  T re, im;      // действительная и мнимая части

public:

  T Re() const {return re;}
  T Im() const {return im;}
  Complex (): re(0), im(0) {} //  конструктор по умолчанию
  Complex (T r): re(r), im(0) {}  // конструктор от одного аргумента 
  Complex (T r, T i): re(r), im(i) {} // конструктор от двух аргументов
  Complex (const Complex &c): re(c.re), im(c.im) {}  // конструктор копирования
  ~Complex () {} // деструктор
  float Abs () { return std::sqrt(re * re + im * im); } // модуль      
  float Arg () { return atan(im/re);} // фаза в рад
  float ArgDeg () { return atan(im/re)*180/M_PI; } // фаза в град
  Complex Conj() { return Complex (re, -im); } // комплексно-сопряжённое
  Complex operator* (T c) { return Complex(re * c, im * c); }
  Complex operator+ (T c) { return Complex(re + c, im); }
};

std::vector<float> Recursive (int window, const std::vector<float>& input);

std::vector<float> Non_Recursive (int window, const std::vector<float>& input);

class Filter // фильтр скользящего среднего
{
public:
    enum F_Type {RECURSIVE, NON_RECURSIVE}; // Тип фильтра
    Filter(int size, F_Type f_type); // Конструктор
    std::vector<float> Filtering(const std::vector<float>& input); // Функция фильтрации

private:
    int window; // Размер окна
    F_Type type; // Тип фильтра
};

std::vector<float> downsample(const std::vector<float>& input, int d); // понижение частоты дискретизации

class Demodulator  // демодулятор
{
public:
    enum ModulationType {FM,AM}; // выбор типа демодуляции
    Demodulator(ModulationType modulationtype); // конструктор
    std::vector<float> demodulate(std::vector<Complex<float>>& signal); // демодуляция

private:
    ModulationType modtype; //тип демодуляции
    std::vector<float> demodulateFM(std::vector<Complex<float>>& signal); 
    std::vector<float> demodulateAM(std::vector<Complex<float>>& signal);
};

