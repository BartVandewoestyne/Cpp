/**
 * Demonstrate the use of const functions:
 *
 * The const at the end of a member function tells whether this member
 * function changes the this object or not.
 *
 * References:
 *
 *   [david20161003] Best practice when accessing a non-const method of a member pointer from a const-method
 *     https://stackoverflow.com/questions/39834068/best-practice-when-accessing-a-non-const-method-of-a-member-pointer-from-a-const
 */

class Person {

  public:

    Person(int age_in);
    int getAge() const;       // A read-only function.
    void setAge(int age_in);  // A write function.  This one cannot be const.
  
  private:

    int age;

};


Person::Person(int age_in)
{
  age = age_in;
}


int Person::getAge() const
{
   return age;  // This doesn't modify anything, so better put const behind it.
}


void Person::setAge( int age_in )
{
   age = age_in;  // Modifies data member, so function cannot have const.

   // Note: if you do make this function const, then you get the error:
   //
   //   "error: assignment of data-member ‘Person::age’ in read-only structure"
}


int main()
{
   Person myBrother(28);
   const Person myMother(64);

   myBrother.getAge();    // Okay
   myBrother.setAge(29);  // Okay

   myMother.getAge();      // Okay
   //myMother.setAge(65);  // Error
}
