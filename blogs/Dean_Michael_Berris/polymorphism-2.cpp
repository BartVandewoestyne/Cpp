/**
 * References:
 *
 *   [1] http://www.cplusplus-soup.com/2012/11/different-forms-of-polymorphism.html
 */
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

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

class object_concept_t {
public:
  virtual ~object_concept_t() = default;
  virtual void print() = 0;
  virtual object_concept_t* copy() const = 0;
};

template <class T>
class model_t : public object_concept_t {
  T t;
public:
  model_t(T const &t) : t{t} {}
  model_t(T &&t) : t{std::move(t)} {}
  virtual void print() { t.print(); }
  virtual model_t* copy() const { return new model_t{*this}; }
};

class object_t {
  std::unique_ptr<object_concept_t> object;
  friend void print(object_t const& o) { o.object->print(); }
public:
  object_t() = default;
  object_t(object_t const &other) : object{other.object->copy()} {}
  object_t(object_t &&other) : object{std::move(other.object)} {}
  
  template <class O>
  object_t(O &&o) : object{new model_t<O>{o}} {}
  
  object_t& operator= (object_t const &other) { object_t copy{other}; copy.swap(*this); return *this; }
  object_t& operator= (object_t &&other) { other.swap(*this); return *this; }
  
  void swap(object_t &other) noexcept {
    using std::swap;
    swap(other.object, this->object);
  }
};

int main(int argc, const char * argv[])
{
  std::vector<object_t> objects{
    Object{},
    Door{"simple"},
    Book{"Dean Michael Berris", "C++ Soup"}
  };
  for (const auto &object : objects) {
    print(object);
  }
}
