#include <iostream>
#include "FileManager/FileManager.h"
#include "Demodulator/Demodulator.h"

int main()
{   
    FileManager MyFiles; // задаю файловый менеджер 

    std::string AM_File = "signal.dat"; // путь к файлу в котором лежит АМ сигнал
    std::vector<Complex<float>> AM_signal = MyFiles.GetComplexSignal(AM_File); // извлекаю комплексный АМ сигнал
    Demodulator AM(Demodulator::AM); // создаю демодулятор для АМ сигнала
    std::vector<float> demod_AM = AM.demodulate(AM_signal); // демодулирую АМ сигнал
    MyFiles.WAV(12e+3, 16, demod_AM, "AM.wav"); // записываю демодулированный АМ сигнал в звуковой файл

    std::string FM_File = "signal.bin"; // путь к файлу в котором лежит ЧМ сигнал
    std::vector<Complex<float>> FM_signal = MyFiles.GetComplexSignal(FM_File); // извлекаю комплексный ЧМ сигнал
    Demodulator FM(Demodulator::FM); // создаю демодулятор для ЧМ сигнала
    std::vector<float> demod_FM = FM.demodulate(FM_signal); // демодулирую ЧМ сигнал
    Filter low_pass_filter (8, Filter::F_Type::NON_RECURSIVE); // задаю нерекурсивный фильтр с окном 8
    std::vector<float> low_pass_signal; 
    low_pass_signal = low_pass_filter.Filtering(demod_FM); // демодулированный сигнал, пропущенный через фильтр
    int down = 25; // задаю понижение частоты дискретизации
    std::vector<float> decem_signal = downsample(low_pass_signal,down); // прореживаю сигнал после фильтра
    int sampleRate = 500e+3 / down; // задаю дискретизации для записи в звуковой файл
    MyFiles.WAV(sampleRate, 16, decem_signal, "FM.wav"); //записываю сигнал в звуковой файл

	return 0;
}
