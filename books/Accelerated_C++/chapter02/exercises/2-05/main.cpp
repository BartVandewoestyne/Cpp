#include <iostream>
#include <string>

void print_rectangle(int width, int height)
{
  std::string top_bottom_row(width, '*');
  std::string inner_row = "*" + std::string(width-2, ' ') + "*";

  std::cout << top_bottom_row << std::endl;
  for (int i = 2; i <= height-1; i++)
  {
    std::cout << inner_row << std::endl;
  }
  std::cout << top_bottom_row << std::endl;
}

void print_square(int side)
{
  print_rectangle(side, side);
}

void print_triangle(int side)
{
  int outer_pad = side-1;
  int inner_pad = 0;

  std::string line;
  for (int i=1; i <= side-1; i++)
  {
    if (i == 1) {
      line = std::string(outer_pad, ' ') + "*";
    } else {
      line = std::string(outer_pad, ' ') + "*" + std::string(inner_pad, ' ') + "*";
    }
    std::cout << line << std::endl;
    outer_pad = outer_pad -1;
    inner_pad = 2*i - 1;
  }
  std::cout << std::string(2*side-1, '*') << std::endl;
}

int main()
{
   print_square(10);
   print_rectangle(20,10);
   print_triangle(6);
   return 0;
}
