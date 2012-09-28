#include <string>
#include <stdexcept>
using namespace std;

void encrypt(string& s);  // encrypt s in place

const int MINIMUM_PASSWORD_LENGTH = 6;

// this function defines the variable "encrypted" too soon
string encryptPassword1(const string& password)
{

  string encrypted;

  if (password.length() < MINIMUM_PASSWORD_LENGTH) {
    throw logic_error("Password is too short");
  }

  //do whatever is necessary to place an encrypted
  //version of password in encrypted;

  return encrypted;

}


// this function postpones "encrypted"'s definition until
// it's truly necessary
string encryptPassword2(const string& password)
{
  if (password.length() < MINIMUM_PASSWORD_LENGTH) {
    throw logic_error("Password is too short");
  }

  string encrypted;

  // do whatever is necessary to place an encrypted
  // version of password in encrypted;

  return encrypted;

}


// this function postpones "encrypted"'s definition until
// it's necessary, but it's still needlessly inefficient
string encryptPassword3(const string& password)
{
  if (password.length() < MINIMUM_PASSWORD_LENGTH) {
    throw logic_error("Password is too short");
  }

  string encrypted;        // default-construct encrypted
  encrypted = password;    // assign to encrypted
  encrypt(encrypted);
  return encrypted;
}


// finally, the best way to define and initialize encrypted
string encryptPassword4(const string& password)
{

  if (password.length() < MINIMUM_PASSWORD_LENGTH) {
    throw logic_error("Password is too short");
  }

  string encrypted(password);     // define and initialize
                                  // via copy constructor
  encrypt(encrypted);
  return encrypted;
}
