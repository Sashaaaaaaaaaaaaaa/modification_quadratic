#include"Header.h"

using namespace std;

struct Quadratic_solv
{
	char kind;
	double value = 0;

	Quadratic_solv(char ch) :kind(ch) {}
	Quadratic_solv(char ch, double v) :kind(ch), value(v) {}
};
struct Solution_quadratic
{
	bool full = false;
	Quadratic_solv buffer;
	double a = 0;
	double b = 0;
	double c = 0;
	double x;
	double x_2;

	Solution_quadratic(double w) : x(w) {}
	Solution_quadratic(double s, double q) :x(s), x_2(q) {}

	Quadratic_solv  get();
	Quadratic_solv unget(Quadratic_solv t) { full = false; buffer = t; }
	double get_discrimenant();
	double answer_quadratic();

};

Quadratic_solv  Solution_quadratic::get()
{
	char ch;
	std::cin >> ch;
	switch (ch)
	{
	case'+':
	case'-':
	case'x':
	case'=':
	{
		return Quadratic_solv(ch);
	}
	default:
		if (isdigit(ch))
		{
			ts.unget(ch);    //wtf?
			double d = 0;
			std::cin >> d;
			return Quadratic_solv(number, d);
		}
		else
		{
			std::cout << "We don't know this mean" << ch;
			exit(0);
		}
	}
}
Solution_quadratic ts;
const char number = '3';

double primary()
{
	Quadratic_solv t = ts.get();

	switch (t.kind)
	{
		std::cout << "\n k " << t.kind << " v " << t.value << "\n";
	case'-':
	{
		t = ts.get();
		if (t.kind = number)
		{
			return -t.value;
		}
		else
		{
			std::cout << " wrong primary " << t.kind << " will be a number ";
			exit(0);
		}
	}
	case number: return t.value;

	}
}

double Solution_quadratic::get_discrimenant()
{
	double discr = 0;
	discr = b * b - (4 * a * c);
	if (discr < 0) throw exception("I got no roots ");
	return discr;


	double Solution_quadratic::answer_quadratic()
	{
		double x = 0;
		double x_2 = 0;

		if (discr > 0)
		{
			x = (-b + sqrt(discr)) / (2 * a);
			x_2 = (-b - sqrt(discr)) / (2 * a);
			return
		}

		else if (discr == 0)
			x = -b / (2 * a);
	}
}


int main()
{
	try
	{
		std::cout << 3 + 3;
	}
	catch (exception& err)
	{
		cerr << err.what() << endl;
		return 3;

	}
	return 0;


}