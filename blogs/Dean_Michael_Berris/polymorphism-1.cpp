/**
 * References:
 *
 *   [1] http://www.cplusplus-soup.com/2012/11/different-forms-of-polymorphism.html
 */
#include <iostream>

class Book {
  std::string author, title;
public:
  Book(std::string const &author, std::string const &title)
  : author{author}, title{title}
  {}
  Book(Book const &other) : author{other.author}, title{other.title} {}
  Book() : author{}, title{} {}
  void print() { std::cout << "Book " << title << " by " << author << std::endl; }
};

class Door {
  std::string handle;
public:
  explicit Door(std::string const &handle) : handle{handle} {}
  Door(Door const &other) : handle{other.handle} {}
  Door() : handle{"normal"} {}
  void print() { std::cout << "Door " << handle << std::endl; }
};

class Object {
  std::string type_name;
public:
  Object() : type_name{"Object"} {}
  explicit Object(std::string const &type_name) : type_name{type_name} {}
  Object(Object const &other) : type_name{other.type_name} {}
  void print() { std::cout << type_name << std::endl; }
};

template <class O>  // O models the Object concept.
void print(O &&object) {
  object.print();
}

int main(int argc, const char * argv[])
{
  Object object;
  Door door{"simple"};
  Book book{"Dean Michael Berris", "C++ Soup"};
  print(object);
  print(book);
  print(door);
}
