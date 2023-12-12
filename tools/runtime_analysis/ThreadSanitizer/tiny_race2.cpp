// Compile and run with:
//
//   clang++ tiny_race2.cpp -fsanitize=thread -g
//   ./a.out
//
// Reference:
//
//  https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual

#include <pthread.h>
#include <stdio.h>
#include <string>
#include <map>

typedef std::map<std::string, std::string> map_t;

void *threadfunc(void *p) {
  map_t& m = *(map_t*)p;
  m["foo"] = "bar";
  return 0;
}

int main() {
  map_t m;
  pthread_t t;
  pthread_create(&t, 0, threadfunc, &m);
  printf("foo=%s\n", m["foo"].c_str());
  pthread_join(t, 0);
}
