#include <iostream>
#include "FileManager/FileManager.h"

static std::map <std::string, std::vector<Complex<float>>> F_Manager;

void FileManager::NewFile(std::string name)// вытаскиваем сигнал из файла, добавляем его в бинарное дерево
    {
        std::ifstream file(name, std::ios::binary); // открываем файл для чтения в бинарном режиме 
        std::vector<float> signal; 
        int32_t temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(int32_t))) // читаем данные из файла
        { 
            signal.push_back(temp); // добавляем прочитанный элемент в вектор
        }
        file.close();
        std::vector<float> re, im;
        for (int i = 0; i < size(signal)/2; i++) // вещественная и мнимая части комплексного сигнала
        {
            re.push_back(signal[2*i]);
            im.push_back(signal[2*i+1]);
        }
        std::vector<Complex<float>> complex_signal; // собираем в комплексный сигнал
        for (int i = 0; i < size(re); i++) 
        {
            complex_signal.push_back(Complex(re[i], im[i]));
        }
        F_Manager.emplace(name, complex_signal);
    }

std::vector<Complex<float>> FileManager::GetComplexSignal(std::string name) // получаем комплексный сигнал по ключу(путь к файлу)  
    {
        auto it = F_Manager.find(name);
        if (it != F_Manager.end()) // если в дереве файл уже есть просто получаем его значение
        {
            return it -> second;
        }
        else // если выйла в дереве нет
        {   
            std::ifstream file(name);
            if(file.bad()==false) // если файл вообще существует - вытаскиваем из него сигнал - добавляем в дерево - получаем комплексный сигнал по ключу
            {
                NewFile(name);
                return F_Manager.find(name) -> second;
            } 
        }
    }

void FileManager::SaveComplexSignal(std::string name, std::vector<Complex<float>> signal) // запись комплексного сигнала в бинарник
    {
        std::ofstream complex_signal (name, std::ios_base::binary | std::ios_base::trunc);
        if (!complex_signal.is_open()) { std::cout << "Файл не может быть открыт" << std::endl; }
        else {
            for (int i = 0; i != signal.size(); ++i)
            {
                float re = signal[i].Re();
                float im = signal[i].Im();
                complex_signal.write((char *) &re, sizeof(re));
                complex_signal.write((char *) &im, sizeof(im));
            }
        }
        complex_signal.close();
        F_Manager.emplace(name, signal);
    }

void writeToFile(std::ofstream &file, int value, int size) 
{
    file.write(reinterpret_cast<const char*> (&value), size);
}

void FileManager::WAV (int sampleRate, int bitDepth, std::vector<float> signal, std::string name)
{
    std::ofstream audioFile;
    audioFile.open(name, std::ios::binary);
    //Header chunk
    audioFile << "RIFF";
    audioFile << "----";
    audioFile << "WAVE";

    // Format chunk
    audioFile << "fmt ";
    writeToFile(audioFile, 16, 4); // Size
    writeToFile(audioFile, 1, 2); // Compression code
    writeToFile(audioFile, 1, 2); // Number of channels
    writeToFile(audioFile, sampleRate, 4); // Sample rate
    writeToFile(audioFile, sampleRate * bitDepth / 8, 4 ); // Byte rate
    writeToFile(audioFile, bitDepth / 8, 2); // Block align
    writeToFile(audioFile, bitDepth, 2); // Bit depth

    //Data chunk
    audioFile << "data";
    audioFile << "----";

    int preAudioPosition = audioFile.tellp();
    auto maxAmplitude = pow(2, bitDepth - 1) - 1;
    for(int i = 0; i < signal.size(); i++ ) {
        auto sample = signal;
        int intSample = static_cast<int> (sample[i] * maxAmplitude);
        writeToFile(audioFile, intSample, 2);
    }
    int postAudioPosition = audioFile.tellp();

    audioFile.seekp(preAudioPosition - 4);
    writeToFile(audioFile, postAudioPosition - preAudioPosition, 4);

    audioFile.seekp(4, std::ios::beg);
    writeToFile(audioFile, postAudioPosition - 8, 4);

    audioFile.close();   
}