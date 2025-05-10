#include "Array.h"
#include <string>

int main(){
	Array<char> alphabet(26);

	for (size_t i = 0; i < 26; i++) {
		alphabet.at(i) = 65 + i;
	}

	for (auto& letter : alphabet) {
		std::cout << letter << std::endl;
	}

	return 0;
}
