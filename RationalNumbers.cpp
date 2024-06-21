#include <iostream>
#include <iomanip>
class Rational
{
    public:
        int64_t Numerator;
        int64_t Denominator;

    Rational(int a, int b)
    {
        this->Numerator = a;
        if(b != 0)
            this->Denominator = b;
        else
            this->Denominator = 1;
    };

    Rational operator+ (const Rational& a)
    {
        Rational ans(1, 1);
        ans.Numerator = a.Numerator*this->Denominator + this->Numerator*a.Denominator;
        ans.Denominator = a.Denominator*this->Denominator;
        return ans;
    };

    Rational operator/ (int64_t del)
    {
        Rational ans(1, 1);
        ans.Numerator = this->Numerator;
        ans.Denominator = this->Denominator*del;
        return ans;
    };
    
    Rational delim(const Rational& a, int64_t b)
    {
        Rational ans(1, 1);
        ans.Denominator = a.Numerator;
        ans.Numerator = a.Denominator*b;
        return ans;
    };
    
    double to_double()
    {
    
     double a = (this->Numerator * 1.0)/this->Denominator;
     return a;
    };
};

int main()
{
    Rational a(1, 1);
    Rational b(1, 1);
    Rational c(1, 1);
    const size_t ITER = 40;
	auto phi = Rational{ 1, 1 };
	for (size_t i = 0; i < ITER; ++i) {
		phi = b.delim(a + phi, 1);
	}
    c = a + phi;
    double ans = c.to_double();
	std::cout << std::setprecision(15) << "Golden Ratio = " << ans << "\n";
}