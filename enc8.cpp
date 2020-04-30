
#line 10 "index.md"

	
#line 20 "index.md"

	#include <iostream>

#line 43 "index.md"

	static constexpr char digits[] {
		"0123456789abcdef"
	};

#line 11 "index.md"
;
	int main() {
		
#line 27 "index.md"

	for (;;) {
		int ch { std::cin.get() };
		if (ch == EOF) { break; }
		if (ch & 0x80 || ch == '%') {
			
#line 52 "index.md"

	std::cout << '%' <<
		digits[ch >> 4] <<
		digits[ch & 0xf];

#line 32 "index.md"
;
		} else {
			std::cout.put(ch);
		}
	}

#line 13 "index.md"
;
	}
