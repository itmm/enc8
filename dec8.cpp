
#line 65 "index.md"

	
#line 75 "index.md"

	#include <iostream>

#line 98 "index.md"

	int to_digit(int ch) {
		
#line 162 "index.md"

	if ((ch -= '0') <= 9) { return ch; }

#line 169 "index.md"

	if ((ch -= 'A' - '0') < 0 ) {
		return ch;
	}
	if (ch <= 5) { return ch + 10; }

#line 179 "index.md"

	if ((ch -= 'a' - 'A') < 0) {
		return ch;
	}
	if (ch <= 5) { return ch + 10; }

#line 100 "index.md"
;
		return -1;
	}

#line 66 "index.md"
;
	int main() {
		
#line 82 "index.md"

	for (;;) {
		int ch { std::cin.get() };
		if (ch == EOF) { break; }
		if (ch == '%') {
			
#line 110 "index.md"

	int first_ch { std::cin.get() };
	int first_dgt { to_digit(first_ch) };
	if (first_dgt >= 0) {
		
#line 130 "index.md"

	int second_ch { std::cin.get() };
	int second_dgt {
		to_digit(second_ch)
	};
	if (second_dgt >= 0) {
		std::cout.put(
			(first_dgt << 4) | second_dgt
		);
	} else {
		
#line 150 "index.md"

	std::cout.put(ch);
	std::cout.put(first_ch);
	if (second_ch == EOF) { break; }
	std::cout.put(second_ch);

#line 140 "index.md"
;
	}

#line 114 "index.md"
;
	} else {
		std::cout.put(ch);
		if (first_ch == EOF) { break; }
		std::cout.put(first_ch);
	}


#line 87 "index.md"
;
		} else {
			std::cout.put(ch);
		}
	}

#line 68 "index.md"
;
	}
