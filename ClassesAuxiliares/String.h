#include "../Afix.h"

class String
{
private:
  char* chars;
  int tam;
public:
  String();
  String(const char* str);
  String(const std::string s);
  ~String();
  void set(String s);
  void set(const char* str);
  void set(const std::string s);
  char operator[](const int i);
};
