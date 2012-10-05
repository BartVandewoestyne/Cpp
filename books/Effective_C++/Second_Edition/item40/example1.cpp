#include <list>
using namespace std;

// the wrong way to use list for Set
//template<class T>
//class Set: public list<T> { };

// the right way to use list for Set
template<class T>
class Set {
public:
  bool member(const T& item) const;
  void insert(const T& item);
  void remove(const T& item);
  int cardinality() const;
private:
  list<T> rep;                       // representation for a set
};


template<class T>
bool Set<T>::member(const T& item) const
{ return find(rep.begin(), rep.end(), item) != rep.end(); }

template<class T>
void Set<T>::insert(const T& item)
{ if (!member(item)) rep.push_back(item); }

template<class T>
void Set<T>::remove(const T& item)
{
  // TODO: check why we need the keyword 'typename' here.
  // See also http://www-home.fh-konstanz.de/~bittel/aldaBac/Praktikum/typename.htm
  typename list<T>::iterator it =
    find(rep.begin(), rep.end(), item);

  if (it != rep.end()) rep.erase(it);
}

template<class T>
int Set<T>::cardinality() const
{ return rep.size(); }
