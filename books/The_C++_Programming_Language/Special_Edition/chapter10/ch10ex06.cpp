/**
 * (*2) Define some classes for providing random numbers of certain
 * distributions (for example, uniform and exponential).  Each class has a
 * constructor specifying parameters for the distribution and a function draw
 * that returns the next value.
 */
 
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;


class UniformDistribution
{
  private:
    double a, b;

  public:
    UniformDistribution(double a, double b);
    double draw();
};


UniformDistribution::UniformDistribution(double a, double b)
  : a(a), b(b)
{
  srand(time(0));
}


double UniformDistribution::draw()
{
  double f = (double) rand() / RAND_MAX;
  return a + f*(b-a);
}


class ExponentialDistribution
{
  private:
    double lambda;

  public:
    ExponentialDistribution(double lambda);
    double draw();
};


ExponentialDistribution::ExponentialDistribution(double lambda)
  : lambda(lambda)
{
};


double ExponentialDistribution::draw()
{
  UniformDistribution u(0,1);
  return -log(u.draw())/lambda;
}


int main()
{
  UniformDistribution u(1,3);
  cout << u.draw() << endl;

  ExponentialDistribution e(0.5);
  cout << e.draw() << endl;
}
