/**
 * References:
 *
 *   [1] http://www.cplusplus-soup.com/2012/11/different-forms-of-polymorphism.html
 */
#include <iostream>

class Object {
  std::string type_name;
protected:
  explicit Object(std::string const& type_name) : type_name{type_name} {}
public:
  Object() : type_name{"Object"} {}
  Object(Object const &other) : type_name{other.type_name} {}
  virtual void print() { std::cout << type_name; }
  virtual ~Object() {}
};

class Door : public Object {
  std::string handle;
public:
  Door() : Object{"Door"}, handle{"normal"} {}
  explicit Door(std::string const &handle) : Object{"Door"}, handle{handle} {}
  Door(Door const &other) : Object{other}, handle{other.handle} {}
  virtual void print() { Object::print(); std::cout << " " << handle << std::endl; }
  virtual ~Door() {}
};

class Book : public Object {
  std::string title;
  std::string author;
public:
  Book() : Object{"Book"}, title{}, author{} {}
  Book(std::string author, std::string title) : Object{"Book"}, title{title}, author{author} {}
  Book(Book const &other) : Object{other}, title{other.title}, author{other.author} {}
  virtual void print() { Object::print(); std::cout << " " << title << " by " << author << std::endl; }
  virtual ~Book() {}
};

void print(Object& object) {
  object.print();
}

int main(int argc, const char * argv[])
{
  Object object;
  Door door{"simple"};
  Book book{"Dean Michael Berris", "C++ Soup"};
  print(object);
  std::cout << std::endl;
  print(door);
  print(book);
}
