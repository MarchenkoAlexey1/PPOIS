#include "pch.h"
#include "CppUnitTest.h"
#include "..\Laba_Matrix\Matrix.h"
#include "..\Laba_Matrix\Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
	TEST_CLASS(MatrixTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix M;
			Assert::AreEqual(M.get_columns(), 3);
			Assert::AreEqual(M.get_lines(), 3);
		}

		TEST_METHOD(TestMethod2)
		{
			Matrix M(3, 1);
			Assert::AreEqual(M.get_columns(), 3);
			Assert::AreEqual(M.get_lines(), 1);
		}

		TEST_METHOD(TestMethod3)
		{
			Matrix M;
			Assert::IsTrue(M.Type_Definition() == "Нижняя треугольная");
			M.set_matrix(0, 1, 0);
			Assert::IsTrue(M.Type_Definition() == "Единичная");
			M.set_matrix(0, 0, 0);
			Assert::IsTrue(M.Type_Definition() == "Диагональная");
			M.set_matrix(0, 1, 1);
			M.set_matrix(0, 2, 2);
			Assert::IsTrue(M.Type_Definition() == "Нулевая");
			M.set_matrix(4, 0, 1);
			M.set_matrix(6, 1, 0);
			Assert::IsTrue(M.Type_Definition() == "Квадратная");
		}

		TEST_METHOD(TestMethod4)
		{
			Matrix M;
			M.Rows_and_Columns_Change(2, 3);
			Assert::AreEqual(M.get_columns(), 2);
			Assert::AreEqual(M.get_lines(), 3);
			Assert::IsTrue(M.Type_Definition() == "Прямоугольная");
		}

		TEST_METHOD(TestMethod5)
		{
			Matrix M;
			M--;
			Assert::AreEqual(M.get_matrix(0, 0), 0);
			M++;
			M++;
			Assert::AreEqual(M.get_matrix(0, 0), 2);
		}

		TEST_METHOD(TestMethod6)
		{
			Matrix M;
			Matrix N(M.Submatrix_Extraction(0, 1, 1, 2));
			Assert::AreEqual(2, N.get_columns());
		}

		TEST_METHOD(TestMethod7)
		{
			Matrix M;
			Assert::AreEqual(M.get_matrix(1, 0), 2);
			Assert::AreEqual(M.get_matrix(0, 1), 0);
			Matrix N(M.Matrix_Transpose());
			Assert::AreEqual(N.get_matrix(1, 0), 0);
			Assert::AreEqual(N.get_matrix(0, 1), 2);
		}
	};
}
