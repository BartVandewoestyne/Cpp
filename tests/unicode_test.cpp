#include <iostream>
#include <fstream>

using namespace std;
 
int main() {

  ofstream myfile;
  myfile.open("unicode_test.txt");
  myfile << "Liège";
  myfile.close();
  
  return 0;

}
