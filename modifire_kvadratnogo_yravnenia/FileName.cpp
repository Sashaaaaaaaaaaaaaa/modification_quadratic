#include<iostream>
class Quadratic 
{
	char kind;
	double value = 0;
	Quadratic  (char ch):kind(ch){}
	Quadratic (char ch, double v=0) :kind(ch), value(v) {} 
};
struct Reshenie_kvadrat_yravnenia
{
	Quadratic  get();
	double get_discrimenant();
	double answer_Kvadr_yrav();

};
Quadratic  Reshenie_kvadrat_yravnenia::get()
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
		ungetc(ch);    //wtf?
			double d = 0;
				std::cin >> d;
		}
	}
}
Quadratic ts;
 double primary()
{
Quadratic
switch()

}

double Reshenie_kvadrat_yravnenia::get_discrimenant()
{}