#include <stdexcept>
#include <string>

void assertImpl(const char* cond, const char* file, int line)
{
    std::string s = "Failed: " + std::string(cond) + " at " + std::string(cond) + ", " + std::to_string(line);
	throw std::runtime_error(s);
}
