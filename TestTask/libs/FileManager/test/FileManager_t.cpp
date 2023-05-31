#include <gtest/gtest.h>
#include "FileManager/FileManager.h"

TEST(FileManagerTests, SAVE)
{
	std::string a = "/home/sofi/deleteMe/demod/tests_FileManager/test1";
	std::vector<Complex<float>> signal = {{1.0, 2.0},{-3.0, 4.0},{0.0, -5.0}};
	FileManager F_Manager;
	F_Manager.SaveComplexSignal(a,signal);
	ASSERT_EQ (signal[0].Re(), 1.0);
	ASSERT_EQ (signal[1].Re(), -3.0);
	ASSERT_EQ (signal[2].Re(), 0.0);
	ASSERT_EQ (signal[0].Im(), 2.0);
	ASSERT_EQ (signal[1].Im(), 4.0);
	ASSERT_EQ (signal[2].Im(), -5.0);
	
} 
TEST(FileManagerTests, GET)
{
	std::string a = "/home/sofi/deleteMe/demod/tests_FileManager/test1";
	FileManager F_Manager;
    std::vector<Complex<float>> signal = F_Manager.GetComplexSignal(a);
	ASSERT_EQ (signal[0].Re(), 1.0);
	ASSERT_EQ (signal[1].Re(), -3.0);
	ASSERT_EQ (signal[2].Re(), 0.0);
	ASSERT_EQ (signal[0].Im(), 2.0);
	ASSERT_EQ (signal[1].Im(), 4.0);
	ASSERT_EQ (signal[2].Im(), -5.0);
} 

