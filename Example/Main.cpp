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

	float f = 1.0f;
	SafePointer<float> floatPtr = &f;

	std::optional<float> floatDeref = *floatPtr;
	assert(floatDeref.has_value());

	assert(floatDeref.value() == f);
}