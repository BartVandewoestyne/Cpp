/*
 * Illustrates how std::weak_ptr can be used for breaking cyclic dependencies.
 *
 * References:
 *
 *   [haldar2016] Top 10 dumb mistakes to avoid with C++ 11 smart pointers (mistake 8).
 *     http://www.acodersjourney.com/2016/05/top-10-dumb-mistakes-avoid-c-11-smart-pointers/
 *
 *   [hall2014] POINTING THE WAY REDUX, PART 6: WEAK_PTR
 *     https://backwardsincompatibilities.wordpress.com/2014/05/29/pointing-the-way-redux-part-6-weak_ptr/
 *
 *   [dagum2012] Weak Pointers and Circular References in C++ 11.
 *     https://visualstudiomagazine.com/articles/2012/10/19/circular-references.aspx
 *   [bancila2008] A TR1 Tutorial: Smart Pointers.
 *     http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c15361/A-TR1-Tutorial-Smart-Pointers.htm
 */

#include <iostream>
#include <memory>
#include <string>

class Node
{
   std::string value_;
   std::shared_ptr<Node> left_;
   std::shared_ptr<Node> right_;
   std::weak_ptr<Node> parent_;
 
public:
   Node(const std::string value): value_(value){}
 
   std::string Value() const {return value_;}
   std::shared_ptr<Node> Left() const {return left_;}
   std::shared_ptr<Node> Right() const {return right_;}
   std::weak_ptr<Node> Parent() const {return parent_;}
 
   void SetParent(std::shared_ptr<Node> node)
   {
      parent_.reset();
      parent_ = node;
   }
 
   void SetLeft(std::shared_ptr<Node> node)
   {
      left_.reset();
      left_ = node;
   }
 
   void SetRight(std::shared_ptr<Node> node)
   {
      right_.reset();
      right_ = node;
   }
};
 
std::string path(const std::shared_ptr<Node>& item)
{
   std::weak_ptr<Node> wparent = item->Parent();
   std::shared_ptr<Node> sparent = wparent.lock();
 
   if(sparent)
   {
      return path(sparent) + "\\" + item->Value();
   }
 
   return item->Value();
}
 
int main()
{
   std::shared_ptr<Node> root(new Node("C:"));
 
   std::shared_ptr<Node> child1(new Node("dir1"));
   std::shared_ptr<Node> child2(new Node("dir2"));
 
   root->SetLeft(child1);
   child1->SetParent(root);
 
   root->SetRight(child2);
   child2->SetParent(root);
 
   std::shared_ptr<Node> child11(new Node("dir11"));
 
   child1->SetLeft(child11);
   child11->SetParent(child1);
 
   std::cout << "path: " << path(child11) << std::endl;
 
   return 0;
}
