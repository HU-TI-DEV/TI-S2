![logo](img/Numeral_Systems_of_the_World.svg) [](logo-id)

# Numeral system[](title-id)

### Inhoud[](toc-id)

- [Numeral system](#numeral-system)
    - [Inhoud](#inhoud)
  - [Bases](#bases)
  - [Where do we use this?](#where-do-we-use-this)
  - [Numbers from 0 to 16 in four different bases](#numbers-from-0-to-16-in-four-different-bases)
  - [Larger bases - are they actually used?](#larger-bases---are-they-actually-used)
  - [Referenties](#referenties)

---

**v0.1.1 [](version-id)** Getalsysteem. Hage Patzke[](author-id).

---

## Bases

We can write numbers in different 'bases'. The base we know best is base
ten - the decimal system. This is how we usually write numbers. It was
probably chosen because humans usually have ten fingers. But we can also
write numbers in other bases.

## Where do we use this?

The most relevant number bases for programming are:

-   \- decimal - the default base for numbers, a single digit is from 0
    to 9

-   \- hexadecimal or sexagesimal, a convenient abbreviation for binary
    numbers, because each hexadecimal digit (0..F) represents four bits

-   \- octal - this was used in early computers and one octal digit
    (0..7) represents three bits, we see it when Unix file access rights
    are printed or entered, e.g. `chmod 644 myfile.txt` for `rw-r–r–`

-   \- binary - the base in which all conventional digital computer
    circuits work, a bit or binary digit (0..1) represents 'no current'
    and 'current'

To represent bases larger than 10 we normally use the Latin alphabet
from A to Z for anything larger than 9. This way we can represent values
from 0 up to base $10 + 26 =$ 36 in a single digit.

## Numbers from 0 to 16 in four different bases

    10     16     8            2
  ---- ------ ----- ------------
     0   0x00    00   0b00000000
     1   0x01    01   0b00000001
     2   0x02    02   0b00000010
     3   0x03    03   0b00000011
     4   0x04    04   0b00000100
     5   0x05    05   0b00000101
     6   0x06    06   0b00000110
     7   0x07    07   0b00000111
     8   0x08   010   0b00001000
     9   0x09   011   0b00001001
    10   0x0A   012   0b00001010
    11   0x0B   013   0b00001011
    12   0x0C   014   0b00001100
    13   0x0D   015   0b00001101
    14   0x0E   016   0b00001110
    15   0x0F   017   0b00001111
    16   0x10   020   0b00010000

## Larger bases - are they actually used?

As one example of a larger one, base 64 is used in base64 encoding to
represent binary data as printable text.

This encoding uses 0-9, A-Z and a-z. This way we can encode
$10 + 26 + 26 =$ 62 values.\
To get to 64 we need two additional characters, base64 uses '+' and '/'
to make the digits for 62 and 63.

Each base64 character now encodes six bits. Any 8-bit-data that is not a
multiple of three bytes (24 bits) needs added 'padding' to indicate that
the string is complete. For padding, one or two '=' characters are
added.

Example for a short text file (with tabulator and newline character) in
base64 encoding:

```bash
VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZy4KCjAxMjM0NTY3ODkKCiAgICB0YWJ1bGF0b3IhCgo=
```

Hexadecimal dump of the input data (`od -Ax -t x1`):

```bash
0000000 54 68 65 20 71 75 69 63 6b 20 62 72 6f 77 6e 20 
0000010 66 6f 78 20 6a 75 6d 70 73 20 6f 76 65 72 20 74 
0000020 68 65 20 6c 61 7a 79 20 64 6f 67 2e 0a 0a 30 31 
0000030 32 33 34 35 36 37 38 39 0a 0a 20 20 20 20 74 61 
0000040 62 75 6c 61 74 6f 72 21 0a 0a 
000004a
```

## Referenties

- Numeral system (<https://en.wikipedia.org/wiki/Numeral_system>)