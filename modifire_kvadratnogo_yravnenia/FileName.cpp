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
	Quadratic_solv buffer;
	bool full = false;

	double a = 0;
	double b = 0;
	double c = 0;
	double x = 0;
	double x_2 = 0;

	double get_discrimenant();
	double answer_quadratic();
	Quadratic_solv  get();
	Quadratic_solv set_value();
	void put_back(Quadratic_solv t);


};
Solution_quadratic ts;
void Solution_quadratic::put_back(Quadratic_solv t)
{

	{
		if (full) throw("putback() into a full buffer");
		buffer = t;       // copy t to buffer
		full = true;      // buffer is now full
	}
}
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
	case'x²':
	{
		return Quadratic_solv(ch);
	}
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7':case'8': case '9':
	{
		std::cin.unget();
		buffer = set_value();
		return Quadratic_solv(buffer.kind, buffer.value);
	}

	default:

		std::cout << "We don't know this mean" << ch;
		exit(0);

	}
}
Quadratic_solv  Solution_quadratic::set_value()
{
	double value = 0;
	if (full)
	{


	}

	std::cin >> value;

	Quadratic_solv t = ts.get();
	switch (t.kind)
	{
	case'x²':
	{
		b = value;
		return Quadratic_solv('a', value);
	}
	case 'x':
	{
		b = value;
		return Quadratic_solv('b', value);
	}

	case '=':
	{
		c = value;
		put_back(t);
		return Quadratic_solv('c', value);
	}
	default:
	{
		put_back(t);
	}
	}



}

const char number = '3';

double primary()
{
	Quadratic_solv t = ts.get();

	switch (t.kind)
	{
		std::cout << "\n k " << t.kind << " v " << t.value << "\n";
	case'-':
	{/*
	  t = ts.get();
	  if (t.kind = number)
	  {
		  return -t.value;
	  }
	  else
	  {
		  std::cout << " wrong primary " << t.kind << " will be a number ";
		  exit(0);
	  }*/
	}
	case number:
	{
		return t.value;
	}

	case'x': case'x_2':
	{ ts.put_back(t);
	return 0;
	}
	}
}

double term()
{
	double d = primary();
	Quadratic_solv t = ts.get();
	switch (t.kind)
	{

	}
}
double Solution_quadratic::get_discrimenant()
{
	double discr = 0;
	discr = b * b - (4 * a * c);
	if (discr < 0) throw exception("I got no roots ");
	return discr;

}

double Solution_quadratic::answer_quadratic()
{
	Quadratic_solv q = ts.get_discrimenant();

	if (q.value > 0)
	{
		x = (-b + sqrt(q.value)) / (2 * a);
		x_2 = (-b - sqrt(q.value)) / (2 * a);
		return x, x_2;
	}

	else if (q.value == 0)
	{
		x = -b / (2 * a);
		return x;
	}
	else std::cout << "It dosen't have solution, because descrimenant<0 \n";
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