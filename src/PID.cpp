#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{

	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0;
  	i_error = 0;
  	d_error = 0;

  	last_cte = 0;

}

void PID::UpdateError(double cte) 
{
	p_error = cte;
	d_error = cte - last_cte;
	i_error += cte;

	last_cte = cte;
}

double PID::TotalError() 
{
	return ((-1 * Kp) * p_error) + ((-1 * Kd) * d_error) + ((-1 * Ki) * i_error);
}

