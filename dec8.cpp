
#line 25 "index.md"

	#include <iostream>

	int to_digit(int ch) {
		if (ch >= '0' && ch <= '9') {
			return ch - '0';
		} else if (ch >= 'a' && ch <= 'f') {
			return ch - 'a' + 10;
		} else if (ch >= 'A' && ch <= 'F') {
			return ch - 'A' + 10;
		}
		return -1;
	}
	int main() {
		for (;;) {
			int ch { std::cin.get() };
			if (ch == EOF) { break; }
			if (ch == '%') {
				int c1 { std::cin.get() };
				int d1 { to_digit(c1) };
				if (d1 >= 0) {
					int c2 { std::cin.get() };
					int d2 { to_digit(c2) };
					if (d2 >= 0) {
						std::cout.put((d1 << 4) | d2);
					} else {
						std::cout.put(ch);
						std::cout.put(c1);
						if (c2 == EOF) { break; }
						std::cout.put(c2);
					}
				} else {
					std::cout.put(ch);
					if (c1 == EOF) { break; }
					std::cout.put(c1);
				}

			} else {
				std::cout.put(ch);
			}
		}
	}
