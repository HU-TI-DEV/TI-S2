![logo](../getalsysteem/img/Numeral_Systems_of_the_World.svg) [](logo-id)

# Numeral system[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Numeral system](#numeral-system)
    - [Inhoud](#inhoud)
  - [Bases](#bases)
  - [Where do we use this?](#where-do-we-use-this)
  - [Numbers from 0 to 16 in four different bases](#numbers-from-0-to-16-in-four-different-bases)
  - [Larger bases - are they actually used?](#larger-bases---are-they-actually-used)
  - [Referenties](#referenties)

---

**v0.1.1 [](version-id)** Getalsysteem door HU IICT[](author-id).

---

## Bases

We can write numbers in different 'bases'. The base we know best is base
ten - the decimal system. This is how we usually write numbers. It was
probably chosen because humans usually have ten fingers. But we can also
write numbers in other bases.

## Where do we use this?

The most relevant number bases for programming are:

-   decimal - the default base for numbers, a single digit is from 0
    to 9

-   hexadecimal or sexagesimal, a convenient abbreviation for binary
    numbers, because each hexadecimal digit (0..F) represents four bits

-   octal - this was used in early computers and one octal digit
    (0..7) represents three bits, we see it when Unix file access rights
    are printed or entered, e.g. `chmod 644 myfile.txt` for `rw-r–r–`

-   binary - the base in which all conventional digital computer
    circuits work, a bit or binary digit (0..1) represents 'no current'
    and 'current'

To represent bases larger than 10 we normally use the Latin alphabet
from A to Z for anything larger than 9. This way we can represent values
from 0 up to base $10 + 26 =$ 36 in a single digit.

## Numbers from 0 to 16 in four different bases

    10     16        8             2
  ---- ------ ----- ------------
    00   0x00       0o00       0b00000000
    01   0x01       0o01       0b00000001
    02   0x02       0o02       0b00000010
    03   0x03       0o03       0b00000011
    04   0x04       0o04       0b00000100
    05   0x05       0o05       0b00000101
    06   0x06       0o06       0b00000110
    07   0x07       0o07       0b00000111
    08   0x08       0o10       0b00001000
    09   0x09       0o11       0b00001001
    10   0x0A       0o12       0b00001010
    11   0x0B       0o13       0b00001011
    12   0x0C       0o14       0b00001100
    13   0x0D       0o15       0b00001101
    14   0x0E       0o16       0b00001110
    15   0x0F       0o17       0b00001111
    16   0x10       0o20       0b00010000

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

## Fun Fact
Many early civilizations (and some current civilizations, too) used to count in a base 12 (duodecimal) system, by using their thumb to count their phalanges. For further reading, see: https://en.wikipedia.org/wiki/Duodecimal

## Referenties

- Numeral system (<https://en.wikipedia.org/wiki/Numeral_system>)