#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "Demodulator/Demodulator.h"


void writeToFile(std::ofstream &file, int value, int size); // функция записи в файл

struct FileManager
{

    private:
    // static std::map <std::string, std::vector<Complex<float>>> F_Manager;
    void NewFile(std::string name);// вытаскиваем сигнал из файла, добавляем его в бинарное дерево
    
    public:

    std::vector<Complex<float>> GetComplexSignal(std::string name); // получаем комплексный сигнал по ключу(путь к файлу)  

    void SaveComplexSignal(std::string name, std::vector<Complex<float>> signal); // запись комплексного сигнала в бинарник

    void WAV (int sampleRate, int bitDepth, std::vector<float> signal, std::string name);            
};