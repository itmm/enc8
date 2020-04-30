# esc8 - Encode and decode binary data to 7-bit ASCII

The two tool `enc8` and `dec8` allow to convert text with non-ASCII
characters (e.g. UTF-8 encoded text) in a ASCII-compatible form and to
restore the original text with the other tool.

It is sadly still the case, that some of the standard Unix command line
tools are not working well with non-ASCII encodings (yes, I am looking at
you `join`).

To allow text processing, the text can be encoded with `enc8`. The
resulting text can be cut, copied, sorted and processed in different kind
of ways. The result can be restored to the non-ASCII encoding with
`dec8`.

## Encoding

The encoding and both tools are no big deal.

Any input character that is a percentage sign (`%`) or has the 8th bit
set will be encoded. The encoding is the percentage sign `%` following by
the two-digit hexadecimal representation of the byte.

## Decoding

The decoding copies every byte verbatim until it sees a percentage sign
(`%`). If the following two bytes are legal hexadecimal digits
(`0-9a-fA-F`) the byte with the decoded value is written instead of the
escape sequence. Otherwise the percentage sign (`%`) is treated as an
ordinary character.

## Source Code

The source code is generated with my documentation system `hex` that can
be downloaded from `https://github.com/itmm/hex`. The source is generated
from the markdown file `index.md`. `index.html` is a slide-show generated
from the same markdown file.

