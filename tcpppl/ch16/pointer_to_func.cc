#include<iostream>

class Fred {
public:
  void memberFn(int p);
  static void staticMemberFn(int p);  // A static member function can usually handle it
  int signaled;
  // ...
};

void Fred::memberFn(int p) {
  std::cout << "member func " << p << std::endl;
  signaled = p;
}

void Fred::staticMemberFn(int p) {
  std::cout << "static member func" << p << std::endl;
}
// Wrapper function uses a global to remember the object:
Fred* object_which_will_handle_signal;
void Fred_memberFn_wrapper(int p)
{
  std::cout << object_which_will_handle_signal << std::endl;
  object_which_will_handle_signal->memberFn(p);
}
int main()
{
  Fred fred {};
  object_which_will_handle_signal = &fred;
  /* signal(SIGINT, Fred::memberFn); */   // Can NOT do this
  signal(SIGINT, Fred_memberFn_wrapper);  // Okay
  signal(SIGINT, Fred::staticMemberFn);   // Okay usually; see below
  // ...

  std::cout << object_which_will_handle_signal->signaled << std::endl;
  return 0;
}
