#include "String.h"

String::String()
{
  tam = 0;
  chars = NULL;
}

String::String(const char* str)
{
  tam = strlen(str);
  chars = new char[tam];
  strcpy(chars, str);
}

String::String(const std::string s)
{
  tam = s.size();
  chars = new char[tam];
  for (int i = 0; i < tam; i++)
  {
    chars[i] = s[i];
  }
}

String::~String()
{
  delete[] chars;
}

void String::set(String s)
{
  if(chars != NULL)
  {
    delete[] chars;
  }
  tam = s.tam;
  chars = new char[tam];
  for (int i = 0; i < tam; i++)
  {
    chars[i] = s.chars[i];
  }
}

void String::set(const char* str)
{
  if(chars != NULL)
  {
    delete[] chars;
  }
  tam = strlen(str);
  chars = new char[tam];
  for (int i = 0; i < tam; i++)
  {
    chars[i] = str[i];
  }
}

void String::set(const std::string s)
{
  if(chars != NULL)
  {
    delete[] chars;
  }
  tam = s.size();
  chars = new char[tam];
  for (int i = 0; i < tam; i++)
  {
    chars[i] = s[i];
  }
}

char String::operator[](const int i)
{
  return chars[i];
}
