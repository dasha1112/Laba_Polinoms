#include "TPolinom.h"
#include "TMonom.h"
#include "TVector.h"
#include "gtests.h"

TEST(TMonomTest, DefaultConstructor) {
	TVector<double> a(3, 3);
	TVector<double> b(2, 2);
	TMonom M(3, a);
	double c = M.GetC();
	TMonom N(2, b);
	TPolinom p1, p2, p3;
	p1 += M;
	p2 += M;
	//ASSERT_EQ(M.GetC(), 3); // Проверка инициализации C
  //ASSERT_EQ(M.GetDegrees().Length(), 3); // Проверка инициализации вектора degrees
}
