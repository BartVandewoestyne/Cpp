#include <fstream>

int main(void) {  

  std::ofstream outfile;
  outfile.open("test.txt", std::ios_base::app);

  outfile << "Data" << std::endl; 
  outfile.close();
  return 0;

}
