#include <gtest/gtest.h>
#include "Demodulator/Demodulator.h"
#include <cmath>
#include <vector>

// COMPLEX_TESTS
TEST(ComplexTests, Complex_Re)
{
	Complex A (1, 2);
	Complex B (1);
	Complex C (0, 0);
	Complex D (0);
	ASSERT_EQ(A.Re(), 1);
	ASSERT_EQ(B.Re(), 1);
	ASSERT_EQ(C.Re(), 0);
	ASSERT_EQ(D.Re(), 0);
}
TEST(ComplexTests, Complex_Im)
{
	Complex A (1, 2);
	Complex B (1);
	Complex C (0, 0);
	Complex D (0);
	ASSERT_EQ(A.Im(), 2);
	ASSERT_EQ(B.Im(), 0);
	ASSERT_EQ(C.Im(), 0);
	ASSERT_EQ(D.Im(), 0);
}
TEST(ComplexTests, Complex_copy)
{
	Complex A (1, 2);
	Complex B (A);
	ASSERT_EQ(B.Re(), 1);
	ASSERT_EQ(B.Im(), 2);
	Complex C (1);
	Complex D(C);
	ASSERT_EQ(D.Re(), 1);
	ASSERT_EQ(D.Im(), 0);
}
TEST(ComplexTests, Complex_ABS)
{
	Complex A (1,2);
	Complex B (1);
	Complex C (3,4);
	float D = sqrt(5);
	ASSERT_EQ (A.Abs(), D);
	ASSERT_EQ (B.Abs(), 1);
	ASSERT_EQ (C.Abs(), 5);

}
TEST(ComplexTests, Complex_ARG)
{
	Complex A (1,2);
	Complex B (1);
	float C = atan(2/1);
	ASSERT_EQ (A.Arg(), C);
	ASSERT_EQ (B.Arg(), 0);
}
TEST(ComplexTests, Complex_ARGDEG)
{
	Complex A (1,2);
	Complex B (1);
	float C = atan(2/1)*180/M_PI;
	ASSERT_EQ (A.ArgDeg(), C);
	ASSERT_EQ (B.ArgDeg(), 0);
}
TEST(ComplexTests, Complex_CONJ)
{
	Complex A (1,2);
	Complex B = A.Conj();
	ASSERT_EQ (B.Re(), 1);
	ASSERT_EQ (B.Im(), -2);
}
TEST(ComplexTests, Complex_OPERATORS)
{
	Complex A (1,2);
	int B = 2;
	Complex D = A * B;
	Complex E = A + B;
	ASSERT_EQ (D.Re(), 2);
	ASSERT_EQ (D.Im(), 4);
	ASSERT_EQ (E.Re(), 3);
	ASSERT_EQ (E.Im(), 2);
}

// FILTER_TESTS
TEST(FilterTests, Filter_REC)
{
	std::vector<float> B = {1.0, 2.0, 3.0, 4.0}; 

	Filter A1(1, Filter::F_Type::RECURSIVE);
	ASSERT_EQ (A1.Filtering(B), B);

	Filter A2(2, Filter::F_Type::RECURSIVE); 
	std::vector<float> C2 = {1.5 , 2.5, 3.5};
	ASSERT_EQ (A2.Filtering(B), C2);

	Filter A3(3, Filter::F_Type::RECURSIVE);
	std::vector<float> C3 = {2.0 , 3.0};
	ASSERT_EQ (A3.Filtering(B), C3);

	Filter A4(4, Filter::F_Type::RECURSIVE); 
	std::vector<float> C4 = {2.5};
	ASSERT_EQ (A4.Filtering(B), C4);
}
TEST(FilterTests, Filter_NON_REC)
{
	std::vector<float> B = {1.0, 2.0, 3.0, 4.0}; 

	Filter A1(1, Filter::F_Type::NON_RECURSIVE);
	ASSERT_EQ (A1.Filtering(B), B);

	Filter A2(2, Filter::F_Type::NON_RECURSIVE); 
	std::vector<float> C2 = {1.5 , 2.5, 3.5};
	ASSERT_EQ (A2.Filtering(B), C2);

	Filter A3(3, Filter::F_Type::NON_RECURSIVE);
	std::vector<float> C3 = {2.0 , 3.0};
	ASSERT_EQ (A3.Filtering(B), C3);

	Filter A4(4, Filter::F_Type::NON_RECURSIVE); 
	std::vector<float> C4 = {2.5};
	ASSERT_EQ (A4.Filtering(B), C4);
}

// DEMOD_TESTS
TEST(DemodulatorTests, DOWNSAMPLE)
{
	std::vector <float> input = {1.8, 2.7, 3.6, 4.5};
	ASSERT_EQ (downsample(input,1), input);

	std::vector <float> output2 = {1.8, 3.6};
	ASSERT_EQ (downsample(input,2), output2);
	
	std::vector <float> output3 = {1.8, 4.5};
	ASSERT_EQ (downsample(input,3), output3);

	std::vector <float> output4 = {1.8};
	ASSERT_EQ (downsample(input,4), output4);

	std::vector <float> output7 = {1.8};
	ASSERT_EQ (downsample(input,7), output7);
}
TEST(DemodulatorTests, AM1)
{
	std::vector<Complex<float>> input = {{1.0, 0.0}, {1.0, 0.0}, {1.0,0.0},{1.0,0.0}};
    Demodulator A (Demodulator::AM);
	std::vector<float> output = {1.0, 1.0, 1.0};
	ASSERT_EQ (A.demodulate(input), output);	
}
TEST(DemodulatorTests, AM2)
{
	std::vector<Complex<float>> input = {{1.0, 0.0}, {3.0, 4.0}, {4.0,3.0},{1.0,0.0}};
    Demodulator A (Demodulator::AM);
	std::vector<float> output = {0.6, 1.0, 0.6};
	ASSERT_EQ (A.demodulate(input), output);	
}
TEST(DemodulatorTests, FM)
{
	std::vector<Complex<float>> input = {{1.0, 0.0}, {2.0, 2.0}, {3.0,4.0},{4.0,6.0}};
    Demodulator A (Demodulator::FM);
	std::vector<float> output = {2.0, 0.25, 0.08};
	ASSERT_EQ (A.demodulate(input), output);
}
