#include<iostream>
class quadratic 
{
	char kind;
	double value = 0;
	quadratic  (char ch):kind(ch){}
	quadratic (char ch, double v=0) :kind(ch), value(v) {} 
};
struct Reshenie_kvadrat_yravnenia
{
	quadratic  get();
	double get_discrimenant();
	double answer_Kvadr_yrav();

};
quadratic  Reshenie_kvadrat_yravnenia::get()
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
		return (quadratic(ch)); 
	}
	default:
		if (isdigit(ch))
		{
		ungetc(ch);
			double d = 0;
				std::cin >> d;
		}
	}
}