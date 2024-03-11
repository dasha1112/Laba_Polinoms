#include "TVector.h"
#include "TMonom.h"
#include "TPolinom.h"
#include "MyList.h"
int main() 
{
	double arr[] = { 1, 2, 3 };
	double arr1[] = { 4, 5, 6 };
	TVector<double> a(3, arr1);
	TVector<double>a1(3, arr);
	TVector<double> b(2, 2);
	TMonom M(3, a);
	TMonom K(2, a);
	TMonom E(2, a1);
	TMonom N(2, b);
	std::cout << "First monom: " << M <<"\n";
	std::cout << "Second monom: " << K << "\n";
	std::cout << "Third monom: " << N << "\n";
	std::cout << "Fourth monom: " << E << "\n";
	double c = M.GetC();
	int c1 = M.GetDimension();
	std::cout << "Coefficient of the first monomial: " << c << "\n";
	std::cout << "Number of variables of the first monomial:" << c1 << "\n";
	TMonom A = M + K;
	TMonom C = M * K;
	TMonom B = M - K;
	std::cout << "Sum of 1st and 2nd monomials: " << A << "\n";
	std::cout << "Product of the 1st and 3rd monomials: " << C << "\n";
	std::cout << "The difference between the 1st and 2nd monomials: " << B << "\n";
	bool b1 = M == N;
	std::cout << "Are the first and third monomials equal: " << b1 << "\n";
	bool b2 = M != N;
	std::cout << "Are the first and third monomials not equal: " << b2 << "\n";
	bool b3 = M > E;
	std::cout << "The first monomial is greater than the fourth: " << b3 << "\n";
	bool b4 = M < E;
	std::cout << "The first monomial is less than the fourth: " << b4<< "\n";
	TPolinom p1, p2, p3;
	p1 += M;
	p1 += K;
	p1 -= M;
	//p1 *= E;
	p2 = p1;
	//p3 = p2 + p1;
	std::cout << p1;
	return 0;
}