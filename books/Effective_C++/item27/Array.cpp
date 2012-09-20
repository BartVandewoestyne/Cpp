template<class T>
class Array {
private:
  // Don't define this function!
  Array& operator=(const Array& rhs);
};


int main()
{
  Array<int> a;
  Array<int> b;

  // error: ‘Array<T>& Array<T>::operator=(const Array<T>&) [with T = int,
  // Array<T> = Array<int>]’ is private within this context.
  //a = b;
}
