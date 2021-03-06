#ifndef ASSERTION
#define ASSERTION
#ifndef NDEBUG
#include <stdexcept>
#include <iostream>
#include <string>
#define assert(X) ((void)(!(X) ? __assert(#X, __FILE__, __func__, __LINE__) : (void)(0)))

extern inline void __assert (const char* msg, const char* file, const char* func, int line) {
	std::cerr << "assertion: " << msg << "\n  failed at: " << file << ", " << func <<  "(), line: " << line << std::endl;
	throw std::logic_error("Assertion failed");
}
#else
#define assert(X)
#endif
#endif