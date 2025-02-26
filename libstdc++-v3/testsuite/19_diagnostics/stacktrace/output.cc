// { dg-options "-std=gnu++23" }
// { dg-do compile { target c++23 } }
// { dg-require-effective-target stacktrace }

#include <stacktrace>
#include <sstream>
#include <testsuite_hooks.h>

#ifndef __cpp_lib_formatters
# error "Feature-test macro for formatters missing in <stacktrace>"
#elif __cpp_lib_formatters < 202302L
# error "Feature-test macro for formatters has wrong value in <stacktrace>"
#endif

void
test_to_string()
{
  auto trace = std::stacktrace::current();
  std::string s1 = std::to_string(trace.at(0));
  VERIFY( s1.contains("test_to_string():15") );
  std::string s2 = std::to_string(trace);
  VERIFY( s2.contains(s1) );
}

void
test_ostream()
{
  std::ostringstream out;
  auto trace = std::stacktrace::current();
  out << trace.at(0);
  VERIFY( out.str() == std::to_string(trace.at(0)) );
  out.str("");
  out << trace;
  VERIFY( out.str() == std::to_string(trace) );
}

void
test_format()
{
  static_assert( std::is_default_constructible_v<std::formatter<std::stacktrace_entry, char>> );
  static_assert( std::is_default_constructible_v<std::formatter<std::stacktrace, char>> );
  static_assert( std::is_default_constructible_v<std::formatter<std::pmr::stacktrace, char>> );

  auto trace = std::pmr::stacktrace::current();
  VERIFY( std::format("{}", trace) == std::to_string(trace) );

  std::stacktrace_entry entry = trace.at(0);
  std::string str = std::to_string(entry);
  VERIFY( std::format("{}", entry) == str );
  VERIFY( std::format("{0:!<{1}}", entry, str.size() + 3) == (str + "!!!") );
}

int main()
{
  test_to_string();
  test_ostream();
  test_format();
}
