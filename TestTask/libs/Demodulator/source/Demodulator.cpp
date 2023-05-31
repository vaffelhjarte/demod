#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "Demodulator/Demodulator.h"

Filter::Filter(int size, F_Type f_type): window(size), type(f_type){} // Конструктор

std::vector<float> Recursive (int window, const std::vector<float>& input)
{
    int s = std::size(input) - window + 1;
    std::vector<float> values(s);
    float sum = 0;
    int j = 0;
    for (int i = 0; i < size(input); i++)
    {
        sum += input[i];
        if (i >= window - 1)
        {
            values[i - window +1] = sum / window;
            sum -= input[j];
            j++;
        }
    }
    return values;    
}

std::vector<float> Non_Recursive (int window, const std::vector<float>& input)
{
    int s = std::size(input) - window + 1;
    std::vector<float> values(s);
    float sum = 0;
    int j = 0;
    for (int i = 0; i < size(input) - window + 1; i++)
    {
        for (j; j <= window - 1; j++)
        {
            sum += input[i+j];
        }
        values[i] = sum / window;
        j = 0;
        sum = 0;
    }
    return values;    
}

std::vector<float> Filter::Filtering(const std::vector<float>& input) // Фильтрация
{   
    switch (type)
    {
    case F_Type::RECURSIVE:  // реализация рекурсивного
        {
            std::vector<float> res = Recursive(window,input);
            return res;
        }
        break;
    case F_Type::NON_RECURSIVE: // реализация нерекурсивного
        {
            std::vector<float> res = Non_Recursive(window,input);
            return res;
        }
        break;
    }
}

std::vector<float> downsample(const std::vector<float>& input, int d)
{
    std::vector<float> out;
    for(int i = 0; i < std::size(input); i += d) // оставляем 0, д, 2д и след. отсчёты (-> изм. частота дискретизации)
        out.push_back(input[i]);
    return out;
}

Demodulator::Demodulator(ModulationType modulationtype) : modtype(modulationtype) {}

std::vector<float> Demodulator::demodulate(std::vector<Complex<float>>& signal) // демодуляция
{
    switch (modtype) 
    {
        case ModulationType::FM: 
        { // демодуляция
            return demodulateFM(signal);
        }
            break;
        case ModulationType::AM:
        {
            return demodulateAM(signal);
        }
            break;
    }
}

std::vector<float> Demodulator::demodulateFM(std::vector<Complex<float>>& signal) 
{    
    std::vector<float> re;
    std::vector<float> im;
    for (int i = 0; i < size(signal); i++) // вещественная и мнимая части комплексного сигнала
    {
        re.push_back(signal[i].Re());
        im.push_back(signal[i].Im());
    }

    std::vector<float> diff_re;
    for (int i = 1; i < re.size(); i++)
    {
        diff_re.push_back(re[i] - re[i - 1]);
    }

    std::vector<float> diff_im;
    for (int i = 1; i < im.size(); i++)
    {
        diff_im.push_back(im[i] - im[i - 1]);
    }

    std::vector<float> diff;
    for (int i = 0; i < diff_re.size(); i++)
    {
        diff.push_back((re[i] * diff_im[i] - im[i] * diff_re[i])/(im[i] * im[i] + re[i] * re[i]));
    }
    return diff;
    // int window = 8; //надо будет определить каким-то образом 
    // Filter low_pass_filter (window, Filter::F_Type::NON_RECURSIVE);
    // std::vector<float> low_pass_diff;
    // low_pass_diff = low_pass_filter.Filtering(diff);

    // int down = 25; // понижение частоты дискретизации
    // std::vector<float> decem_diff = downsample(low_pass_diff,down);

    // // Запись в wav файл
    // int sampleRateFM = 500e+3 / down;
    // int bitDepth = 16;
    // std::string name = "FM.wav";
    // WAV(sampleRateFM, bitDepth, decem_diff, name);
 
}

std::vector<float> Demodulator::demodulateAM(std::vector<Complex<float>>& signal) 
{   
    std::vector <float> ABS; 
    for (int i = 0; i < size(signal); i++) // берём модуль 
    {
        ABS.push_back(signal[i].Abs());
    }
    
    int window = 2; //надо будет определить каким-то образом 
    Filter low_pass_filter (window, Filter::F_Type::RECURSIVE);
    std::vector<float> low_pass_signal;
    low_pass_signal = low_pass_filter.Filtering(ABS);

    float max_ABS = low_pass_signal[0];
    for (int i = 0; i < size(low_pass_signal); i++) // максимальное значение ищём
    {
        if (low_pass_signal[i] > max_ABS) 
        {
            max_ABS = low_pass_signal[i];
        }
    }
    
    std::vector <float> norm;
    for (int i = 0; i < size(low_pass_signal); i++) // нормируем
    {
        norm.push_back(low_pass_signal[i] / max_ABS);
    }
    return norm;
    // // запись в звуковой файл
    // int sampleRateAM = 12e+3;
    // int bitDepth = 16;
    // std::string name = "AM.wav";
    // WAV(sampleRateAM, bitDepth, norm, name);
}
