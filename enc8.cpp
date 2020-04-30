
#line 4 "index.md"

	#include <iostream>

	int main() {
		char digits[] { "0123456789abcdef" };
		for (;;) {
			int ch { std::cin.get() };
			if (ch == EOF) { break; }
			if (ch & 0x80 || ch == '%') {
				std::cout << '%' <<
					digits[ch >> 4] <<
					digits[ch & 0xf];
			} else {
				std::cout.put(ch);
			}
		}
	}
