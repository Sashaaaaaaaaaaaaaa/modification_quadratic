
/*
The program that solves
(ax²+bx+c=0, negative number also )
* complete or not complete(x2+4x=0) quadratic solution.
*
*

  cin.unget() used for return a characters  into the cin steam
get()
  to return  kind or (kind,value) entered

primaru():
	return negative or positive number

term ():
  set_value_of_variable

  define a variable :
*
   'a' is(number is before) x + character
   'b' is(number is before) x
   'c' is(number is before) =

	 retun()  value of variable

 calculate()
  return answer_quadratic_solution


*/

#include"Header.h"

using namespace std;

struct Quadratic_solv
{
	char kind;
	double value = 0;
	double a = 1;
	double b = 1;
	double c = 1;
	double x = 0;
	double x_2 = 0;


	Quadratic_solv(char ch) :kind(ch) {}
	Quadratic_solv(char ch, double v) :kind(ch), value(v) {}

};
class Solution_quadratic
{
	Quadratic_solv buffer;
	bool full = false;


public:
	Solution_quadratic() : full(0), buffer(0) { }
	double get_discrimenant();
	void answer_quadratic();
	Quadratic_solv  get();
	Quadratic_solv set_value(Quadratic_solv s);

	void unget(Quadratic_solv t) { buffer = t; full = true; }


};


/*void Solution_quadratic::put_back(Quadratic_solv t)
{

	{
		if (full) throw("putback() into a full buffer");
		buffer = t;       // copy t to buffer
		full = true;      // buffer is now full
	}
}
*/
const char number = '3';  //kind of numbers, why 3? why not!?
Solution_quadratic solut_quadrat;   //To use the Solution_quadratic function
Quadratic_solv quadratic_('a', 0);

Quadratic_solv  Solution_quadratic::get()
{
	/*if (full) {
		cout <<   " here\n";
			full = false; return buffer; }*/

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
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7':case'8': case '9':
	{
		// solut_quadrat.unget(ch);
		std::cin.unget();
		double d;
		std::cin >> d;

		return Quadratic_solv(number, d);
	}

	default:

		std::cout << "We don't know this mean" << ch;
		exit(0);

	}
}
Quadratic_solv  Solution_quadratic::set_value(Quadratic_solv s)
{
	switch (s.kind)
	{
	case'a':
	{
		quadratic_.a = s.value;

		return quadratic_.a;
	}

	case 'c':
	{
		quadratic_.c = s.value;

		return quadratic_.c;
	}
	case 'b':
	{
		quadratic_.b = s.value;

		return quadratic_.b;
	}

	default:
	{
		error("name of variable doesn't find", s.kind);
	}
	}



}



double primary()
{
	Quadratic_solv q = solut_quadrat.get();
	switch (q.kind)
	{
	case'-':
	{
		double value = -primary();
		return  value;
		// --4 return -4 
	}
	case'+':
	{
		return +primary();
	}
	case number:
	{
		return q.value;
	}
	case'x': case'=':     //if a,b,or c they don't
		// have a designation (x²+4x-3=0)
	{
		cin.unget();
		return 1;
	}

	default:
		error("wrong primary ");


		/*case'x': case'x_2':   for x²+dx+c=0 etc.
		{ solut_quadrat.put_back(t);
			return 0;
		}*/
	}
}

double term()
{
	double value = primary();
	Quadratic_solv q = solut_quadrat.get();

	switch (q.kind)
	{
	case'x':
	{
		q = solut_quadrat.get();
		if (q.kind == '-' || q.kind == '+')
		{
			cin.unget();
			solut_quadrat.set_value(Quadratic_solv('b', value));

			term();
			//primary();
			return value;
		}
		else  // the '²' can't be cheking  
		{
			solut_quadrat.set_value(Quadratic_solv('a', value));

			term();//primary();
			return    quadratic_.a;
		}
	}

	case'=':
	{
		//cin.unget();
		solut_quadrat.set_value(Quadratic_solv('c', value));
		q = solut_quadrat.get(); // read 0 after = 
		return  value;
	}
	default:

		error("some wrong into the tream ");


	}
}
double Solution_quadratic::get_discrimenant()
{

	double discrim = 0;
	discrim = quadratic_.b * quadratic_.b - (4 * quadratic_.a * quadratic_.c);
	//if (discrim < 0)  ("I got no roots ");
	return discrim;

}

void Solution_quadratic::answer_quadratic()
{
	double discrim = solut_quadrat.get_discrimenant();

	if (discrim > 0)
	{
		quadratic_.x = (-quadratic_.b + sqrt(discrim)) / (2 * quadratic_.a);
		quadratic_.x_2 = (-quadratic_.b - sqrt(discrim)) / (2 * quadratic_.a);
		cout << "x =" << quadratic_.x << " \n x²=" << quadratic_.x_2 << '\n';
	}

	else if (discrim == 0)
	{
		quadratic_.x = -quadratic_.b / (2 * quadratic_.a);
		cout << "x =" << quadratic_.x << '\n';

	}
	else cout << ("I got no roots ") << "\n";
}


double calculate()
{

	cout << " you need enter a value of variable (a,b,c)\n";
	term();

	solut_quadrat.answer_quadratic();
	return 0;

}


int main()
{
	try
	{
		for (int i = 0; i < 10; ++i)
		{
			calculate();
		}


	}
	catch (exception& err)
	{
		cerr << err.what() << endl;
		return 3;

	}
	return 0;


}