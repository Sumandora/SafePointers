#include <cassert>
#include <cstdint>
#include <iostream>
#include <optional>

#include "SafePointer.hpp"

using namespace SafePointers;

int main()
{
	SafePointer<std::uintptr_t> null = nullptr;

	std::optional<std::uintptr_t> uintptr = *null;
	assert(!uintptr.has_value());

	printf("Null can't be dereferenced\n");

	float f = 1.0f;
	SafePointer<float> floatPtr = &f;

	std::optional<float> floatDeref = *floatPtr;
	assert(floatDeref.has_value());
	printf("However this float is valid, so we can dereference it\n");

	assert(floatDeref.value() == f);
	printf("As you can see: %f = %f\n", floatDeref.value(), f);
}