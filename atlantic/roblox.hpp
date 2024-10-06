#include "headers.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// ^^ idk what happened visual studio broke something bad so i just decided to redefine already defined headers :c

#define mewing "true"

namespace roblox { // decided to do a namespace instead of a class

	namespace offsets { // placeholder of offsets these need to be changed each week
		uint64_t datamodel = 0;
		uint64_t datamodel2 = 0;
	}
	
	namespace datamodel {
		uint64_t public_datamodel = 0;
	}
}