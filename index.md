# Encode and decode 8 bit characters to ASCII
* encode by escaping 8-bit characters with percentage sign (`%`)
* and their 2-digit hexadecimal value

## Encoding
* escape non-ASCII characters read from `std::cin`
* and write output to `std::cout`

```
@Def(file: enc8.cpp)
	@put(enc globals);
	int main() {
		@put(enc main);
	}
@End(file: enc8.cpp)
```
* simple structure for the encoding command

```
@def(enc globals)
	#include <iostream>
@end(enc globals)
```
* needs standard input output classes and constants

```
@def(enc main)
	for (;;) {
		int ch { std::cin.get() };
		if (ch == EOF) { break; }
		if (ch & 0x80 || ch == '%') {
			@put(write escaped);
		} else {
			std::cout.put(ch);
		}
	}
@end(enc main)
```
* process characters until end is reached
* escape only 8-bit characters and the percentage sign (`%`)

```
@add(enc globals)
	static constexpr char digits[] {
		"0123456789abcdef"
	};
@end(enc globals)
```
* simple mapping to encode characters

```
@def(write escaped)
	std::cout << '%' <<
		digits[ch >> 4] <<
		digits[ch & 0xf];
@end(write escaped)
```
* write escaped character

## Decoding
* try to decode escape sequences from `std::cin`
* and write everything to `std::cout`

```
@Def(file: dec8.cpp)
	@put(dec globals);
	int main() {
		@put(dec main);
	}
@End(file: dec8.cpp)
```
* same file structure as `enc`

```
@def(dec globals)
	#include <iostream>
@end(dec globals)
```
* also needs standard input and output classes and constants

```
@def(dec main)
	for (;;) {
		int ch { std::cin.get() };
		if (ch == EOF) { break; }
		if (ch == '%') {
			@put(unescape);
		} else {
			std::cout.put(ch);
		}
	}
@end(dec main)
```
* try to expand escape sequences
* and copy everything else

```
@add(dec globals)
	int to_digit(int ch) {
		@put(to digit);
		return -1;
	}
@end(dec globals)
```
* function to convert a char to a hexadecimal digit
* returns negative value, if the character does not represent a valid
  hexadecimal digit

```
@def(unescape)
	int first_ch { std::cin.get() };
	int first_dgt { to_digit(first_ch) };
	if (first_dgt >= 0) {
		@put(parse 2nd digit);
	} else {
		std::cout.put(ch);
		if (first_ch == EOF) { break; }
		std::cout.put(first_ch);
	}

@end(unescape)
```
* if the first character after the escape sign is a valid hexadecimal
  digit:
* continue with the next character
* otherwise copy escape sign and first character to output
* unless there is no first character, of course

```
@def(parse 2nd digit)
	int second_ch { std::cin.get() };
	int second_dgt {
		to_digit(second_ch)
	};
	if (second_dgt >= 0) {
		std::cout.put(
			(first_dgt << 4) | second_dgt
		);
	} else {
		@put(copy escape seq);
	}
@end(parse 2nd digit)
```
* if the second character is a valid hexadecimal digit:
* write the character with the matching byte value
* otherwise copy escape sign, first character and the second character
  to output

```
@def(copy escape seq)
	std::cout.put(ch);
	std::cout.put(first_ch);
	if (second_ch == EOF) { break; }
	std::cout.put(second_ch);
@end(copy escape seq)
```
* copy escape sign, first character and the second character
  to output
* unless there is no second character

```
@def(to digit)
	if ((ch -= '0') <= 9) { return ch; }
@end(to digit)
```
* return valid decimal digit

```
@add(to digit)
	if ((ch -= 'A' - '0') < 0 ) {
		return ch;
	}
	if (ch <= 5) { return ch + 10; }
@end(to digit)
```
* check for the letters `A` to `F`

```
@add(to digit)
	if ((ch -= 'a' - 'A') < 0) {
		return ch;
	}
	if (ch <= 5) { return ch + 10; }
@end(to digit)
```
* check for the letters `a` to `f`

