#include <fstream>
#include <optional>

namespace SafePointers {
	namespace {
		inline bool IsAddressReadable(void* ptr)
		{
			static thread_local std::fstream procMem{ "/proc/self/maps", std::fstream::in };

			if (!procMem.is_open())
				return false;

			procMem.clear();
			procMem.seekg(0, std::ios::beg);

			std::uintptr_t uintptr = reinterpret_cast<std::uintptr_t>(ptr);

			for (std::string line; std::getline(procMem, line);) {
				if (line.empty())
					continue;

				std::size_t dash = line.find_first_of('-');
				std::size_t to = line.find_first_of(' ');

				if (line[to + 1] != 'r')
					continue;

				std::uintptr_t begin = std::stoull(line.substr(0, dash), 0, 16);
				std::uintptr_t end = std::stoull(line.substr(dash + 1, to), 0, 16);

				 // If the pointer lies between 2 pages something has clearly gone wrong, so I won't be handling that here
				if (begin <= uintptr && uintptr + sizeof(void*) < end) {
					return true;
				}
			}

			return false;
		}
	}

	template <typename T>
	class SafePointer {
		T* pointer;

	public:
		SafePointer()
			: pointer(nullptr)
		{
		}
		SafePointer(T* pointer)
			: pointer(pointer)
		{
		}

		std::optional<T> operator*()
		{
			if (IsAddressReadable(pointer)) {
				return *pointer;
			}
			return std::nullopt;
		}
	};
}
