/**
 * (*2) Define a class Histogram that keeps count of numbers in some intervals
 * specified as arguments to Histogram's constructor.  Provide functions to
 * print out the histogram. Handle out-of-range values.
 */
#include <iostream>
#include <vector>
using namespace std;


struct bin {
  double lowerbound;
  double upperbound;
  int nbElements;
};


class Histogram
{

  public:
    Histogram(vector<double> boundaries);
    void add(int x);
    void print();

  private:
    vector<bin> bins;
    vector<double> numbers;

};


Histogram::Histogram(vector<double> boundaries)
{
  for (int i=0; i < boundaries.size()-2; i++)
  {
    bin mybin;
    mybin.lowerbound = boundaries.at(i);
    mybin.upperbound = boundaries.at(i+1);
    mybin.nbElements = 0;
    bins.push_back( mybin );
  }
}


void Histogram::add(int x)
{
  cout << "Adding " << x << " to histogram." << endl;
  numbers.push_back(x);
  int i = 0;
  if (x < bins.front().lowerbound || x > bins.back().upperbound)
  {
    cout << "ERROR: " << x << " is out of the histogram bounds, ignoring value!" << endl;
    return;
  }
  else
  {
    while (x > bins.at(i).upperbound)
    {
      i = i++;
    }
    bins.at(i).nbElements += 1;
    return;
  }
}


void Histogram::print()
{
  vector<bin>::iterator pos;
  for (pos = bins.begin(); pos < bins.end(); ++pos)
  {
    cout << "[" << pos->lowerbound << ", " << pos->upperbound << "]: " << pos->nbElements << endl;
  }
}


int main()
{
  vector<double> boundaries;
  boundaries.push_back(0);
  boundaries.push_back(10);
  boundaries.push_back(20);
  boundaries.push_back(30);
  Histogram hist(boundaries);
  hist.add(5);
  hist.add(5);
  hist.add(5);
  hist.add(15);
  hist.add(25);
  hist.add(75);
  hist.add(40);
  hist.print();
}
