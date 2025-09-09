![logo](img/logo.svg) [](logo-id)

<!-- markdown-link-check-disable -->

# Markdown: Syntax [](title-id) <!-- omit in toc -->

### Table of contents [](toc-id) <!-- omit in toc -->

- [Overview](#overview)
  - [Philosophy](#philosophy)
- [Block Elements](#block-elements)
  - [Paragraphs and Line Breaks](#paragraphs-and-line-breaks)
  - [Headers](#headers)
  - [Blockquotes](#blockquotes)
  - [Lists](#lists)
  - [Code Blocks](#code-blocks)
- [Span Elements](#span-elements)
  - [Links](#links)
  - [Emphasis](#emphasis)
  - [Code](#code)
- [Links](#links-1)
- [Images](#images)
- [Code and syntax highlighting](#code-and-syntax-highlighting)
- [Tables](#tables)
- [Style italic](#style-italic)
- [Style bold](#style-bold)
- [Style bold italic](#style-bold-italic)
- [Style strikethrough](#style-strikethrough)
- [References](#references)

---

**v0.1.1 [](version-id)** This document is a template for our TI S2 documentation and example code.

---

## Overview

### Philosophy

Markdown is intended to be as easy-to-read and easy-to-write as is feasible.

Readability, however, is emphasized above all else. A Markdown-formatted
document should be publishable as-is, as plain text, without looking
like it's been marked up with tags or formatting instructions. While
Markdown's syntax has been influenced by several existing text-to-HTML
filters -- including [Setext](http://docutils.sourceforge.net/mirror/setext.html), [atx](http://www.aaronsw.com/2002/atx/), [Textile](http://textism.com/tools/textile/), [reStructuredText](http://docutils.sourceforge.net/rst.html),
[Grutatext](http://www.triptico.com/software/grutatxt.html), and [EtText](http://ettext.taint.org/doc/) -- the single biggest source of
inspiration for Markdown's syntax is the format of plain text email.

## Block Elements

### Paragraphs and Line Breaks

A paragraph is simply one or more consecutive lines of text, separated
by one or more blank lines. (A blank line is any line that looks like a
blank line -- a line containing nothing but spaces or tabs is considered
blank.) Normal paragraphs should not be indented with spaces or tabs.

The implication of the "one or more consecutive lines of text" rule is
that Markdown supports "hard-wrapped" text paragraphs. This differs
significantly from most other text-to-HTML formatters (including Movable
Type's "Convert Line Breaks" option) which translate every line break
character in a paragraph into a `<br />` tag.

When you _do_ want to insert a `<br />` break tag using Markdown, you
end a line with two or more spaces, then type return.

### Headers

Markdown supports two styles of headers, [Setext][1] and [atx][2].

Optionally, you may "close" atx-style headers. This is purely
cosmetic -- you can use this if you think it looks better. The
closing hashes don't even need to match the number of hashes
used to open the header. (The number of opening hashes
determines the header level.)

### Blockquotes

Markdown uses email-style `>` characters for blockquoting. If you're
familiar with quoting passages of text in an email message, then you
know how to create a blockquote in Markdown. It looks best if you hard
wrap the text and put a `>` before every line:

> This is a blockquote with two paragraphs. Lorem ipsum dolor sit amet,
> consectetuer adipiscing elit. Aliquam hendrerit mi posuere lectus.
> Vestibulum enim wisi, viverra nec, fringilla in, laoreet vitae, risus.
>
> Donec sit amet nisl. Aliquam semper ipsum sit amet velit. Suspendisse
> id sem consectetuer libero luctus adipiscing.

Markdown allows you to be lazy and only put the `>` before the first
line of a hard-wrapped paragraph:

> This is a blockquote with two paragraphs. Lorem ipsum dolor sit amet,
> consectetuer adipiscing elit. Aliquam hendrerit mi posuere lectus.
> Vestibulum enim wisi, viverra nec, fringilla in, laoreet vitae, risus.

> Donec sit amet nisl. Aliquam semper ipsum sit amet velit. Suspendisse
> id sem consectetuer libero luctus adipiscing.

Blockquotes can be nested (i.e. a blockquote-in-a-blockquote) by
adding additional levels of `>`:

> This is the first level of quoting.
>
> > This is nested blockquote.
>
> Back to the first level.

Blockquotes can contain other Markdown elements, including headers, lists,
and code blocks:

> ## This is a header
>
> 1. This is the first list item.
> 2. This is the second list item.
>
> Here's some example code:
>
>     return shell_exec("echo $input | $markdown_script");

Any decent text editor should make email-style quoting easy. For
example, with BBEdit, you can make a selection and choose Increase
Quote Level from the Text menu.

### Lists

Markdown supports ordered (numbered) and unordered (bulleted) lists.

Unordered lists use asterisks, pluses, and hyphens -- interchangably
-- as list markers:

- Red
- Green
- Blue

is equivalent to:

- Red
- Green
- Blue

and:

- Red
- Green
- Blue

Ordered lists use numbers followed by periods:

1. Bird
2. McHale
3. Parish

It's important to note that the actual numbers you use to mark the
list have no effect on the HTML output Markdown produces. The HTML
Markdown produces from the above list is:

If you instead wrote the list in Markdown like this:

1. Bird
1. McHale
1. Parish

or even:

3. Bird
1. McHale
1. Parish

you'd get the exact same HTML output. The point is, if you want to,
you can use ordinal numbers in your ordered Markdown lists, so that
the numbers in your source match the numbers in your published HTML.
But if you want to be lazy, you don't have to.

To make lists look nice, you can wrap items with hanging indents:

- Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
    Aliquam hendrerit mi posuere lectus. Vestibulum enim wisi,
    viverra nec, fringilla in, laoreet vitae, risus.
- Donec sit amet nisl. Aliquam semper ipsum sit amet velit.
    Suspendisse id sem consectetuer libero luctus adipiscing.

But if you want to be lazy, you don't have to:

- Lorem ipsum dolor sit amet, consectetuer adipiscing elit.
    Aliquam hendrerit mi posuere lectus. Vestibulum enim wisi,
    viverra nec, fringilla in, laoreet vitae, risus.
- Donec sit amet nisl. Aliquam semper ipsum sit amet velit.
    Suspendisse id sem consectetuer libero luctus adipiscing.

List items may consist of multiple paragraphs. Each subsequent
paragraph in a list item must be indented by either 4 spaces
or one tab:

1. This is a list item with two paragraphs. Lorem ipsum dolor
    sit amet, consectetuer adipiscing elit. Aliquam hendrerit
    mi posuere lectus.

    Vestibulum enim wisi, viverra nec, fringilla in, laoreet
    vitae, risus. Donec sit amet nisl. Aliquam semper ipsum
    sit amet velit.

2. Suspendisse id sem consectetuer libero luctus adipiscing.

It looks nice if you indent every line of the subsequent
paragraphs, but here again, Markdown will allow you to be
lazy:

- This is a list item with two paragraphs.

        This is the second paragraph in the list item. You're

    only required to indent the first line. Lorem ipsum dolor
    sit amet, consectetuer adipiscing elit.

- Another item in the same list.

To put a blockquote within a list item, the blockquote's `>`
delimiters need to be indented:

- A list item with a blockquote:

    > This is a blockquote
    > inside a list item.

To put a code block within a list item, the code block needs
to be indented _twice_ -- 8 spaces or two tabs:

- A list item with a code block:

        <code goes here>

### Code Blocks

Pre-formatted code blocks are used for writing about programming or
markup source code. Rather than forming normal paragraphs, the lines
of a code block are interpreted literally. Markdown wraps a code block
in both `<pre>` and `<code>` tags.

To produce a code block in Markdown, simply indent every line of the
block by at least 4 spaces or 1 tab.

This is a normal paragraph:

    This is a code block.

Here is an example of AppleScript:

    tell application "Foo"
        beep
    end tell

A code block continues until it reaches a line that is not indented
(or the end of the article).

Within a code block, ampersands (`&`) and angle brackets (`<` and `>`)
are automatically converted into HTML entities. This makes it very
easy to include example HTML source code using Markdown -- just paste
it and indent it, and Markdown will handle the hassle of encoding the
ampersands and angle brackets. For example, this:

    <div class="footer">
        &copy; 2004 Foo Corporation
    </div>

Regular Markdown syntax is not processed within code blocks. E.g.,
asterisks are just literal asterisks within a code block. This means
it's also easy to use Markdown to write about Markdown's own syntax.

```
tell application "Foo"
    beep
end tell
```

## Span Elements

### Links

Markdown supports two style of links: _inline_ and _reference_.

In both styles, the link text is delimited by [square brackets].

To create an inline link, use a set of regular parentheses immediately
after the link text's closing square bracket. Inside the parentheses,
put the URL where you want the link to point, along with an _optional_
title for the link, surrounded in quotes. For example:

This is [an example](http://example.com/) inline link.

[This link](http://example.net/) has no title attribute.

### Emphasis

Markdown treats asterisks (`*`) and underscores (`_`) as indicators of
emphasis. Text wrapped with one `*` or `_` will be wrapped with an
HTML `<em>` tag; double `*`'s or `_`'s will be wrapped with an HTML
`<strong>` tag. E.g., this input:

_single asterisks_

_single underscores_

**double asterisks**

**double underscores**

### Code

To indicate a span of code, wrap it with backtick quotes (`` ` ``).
Unlike a pre-formatted code block, a code span indicates code within a
normal paragraph. For example:

Use the `printf()` function.

## Links

    - [I'm an inline-style wiki-page link](Markdown Test Page)
    - [I'm an inline-style link](https://www.google.com)
    - [I'm a reference-style link][Arbitrary case-insensitive reference text]
    - [You can use numbers for reference-style link definitions][1]

    Or leave it empty and use the [link text itself]

    URLs and URLs in angle brackets will automatically get turned into links.
    http://www.example.com or <http://www.example.com> and sometimes
    example.com (but not on Github, for example).

    Some text to show that the reference links can follow later.

    [arbitrary case-insensitive reference text]: https://www.mozilla.org
    [1]: http://slashdot.org
    [link text itself]: http://www.reddit.com 

- [I'm an inline-style wiki-page link](Markdown Test Page)
- [I'm an inline-style external link](https://www.google.com)

- [I'm a reference-style link][arbitrary case-insensitive reference text]
- [You can use numbers for reference-style link definitions][1]

Or leave it empty and use the [link text itself]

URLs and URLs in angle brackets will automatically get turned into links.
<http://www.example.com> or <http://www.example.com> and sometimes
example.com (but not on Github, for example).

Some text to show that the reference links can follow later. Reference links only support full URL's, not internal wiki pagenames.

[arbitrary case-insensitive reference text]: https://www.mozilla.org
[1]: http://slashdot.org
[link text itself]: http://www.reddit.com

<!-- markdown-link-check-enble -->

## Images

Here's our logo (hover to see the title text):

Inline-style:

    ![wiki inline img attachment](Markdown Behavior/markdown-solid.png "Markdown Logo Title")

    ![img url](https://github.com/dcurtis/markdown-mark/blob/master/png/66x40.png?raw=true "Markdown Logo Title")

![wiki inline img attachment](Markdown Behavior/markdown-solid.png "Markdown Logo Title")

![img url](https://github.com/dcurtis/markdown-mark/blob/master/png/66x40.png?raw=true "Markdown Logo Title")

Reference-style:

    ![alt text markdown-logo][logo]

    [logo]: https://github.com/dcurtis/markdown-mark/blob/master/png/66x40.png?raw=true "Markdown Logo Title"

![alt text markdown-logo][logo]

[logo]: https://github.com/dcurtis/markdown-mark/blob/master/png/66x40.png?raw=true "Markdown Logo Title"

## Code and syntax highlighting

    Inline `code` has `back-ticks around` it.

Inline `code` has `back-ticks around` it.

Blocks of code are either fenced by lines with three back-ticks ```, or are indented with four spaces. The fenced code blocks are easier and only they support syntax highlighting.

```javascript
//code highlighting
var s = "JavaScript syntax highlighting";
alert(s);
```

```
//No language indicated, so no syntax highlighting.
var s = "Lorem Ipsum";
```

## Tables

Tables aren't part of the core Markdown spec, but they are part of GFM.

Colons can be used to align columns.

```
| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |
```

| Tables        |      Are      |   Cool |
| ------------- | :-----------: | -----: |
| col 3 is      | right-aligned | \$1600 |
| col 2 is      |   centered    |   \$12 |
| zebra stripes |   are neat    |    \$1 |

The outer pipes (|) are optional, and you don't need to make the raw Markdown line up prettily. You can also use inline Markdown.

```
Markdown | Less | Pretty
--- | --- | ---
*Still* | `renders` | **nicely**
1 | 2 | 3
```

| Markdown | Less      | Pretty     |
| -------- | --------- | ---------- |
| _Still_  | `renders` | **nicely** |
| 1        | 2         | 3          |

## Style italic

Use single asterisks for *italic text* `*italic text*`

Underscores work the same for _italic text_ `_italic text_`

## Style bold

Use double asterisks for **bold text** `**bold text**`

## Style bold italic

Use triple asterisks for ***bold italic text*** `***bold italic text***`

## Style strikethrough

Use double tilde for ~~strikethrough~~ `~~strikethrough~~`

## References

- Markdown example taken from <https://github.com/PavelLaptev/markdown-theme-shell/tree/master>
- Markdown cheat-sheet <https://www.markdownguide.org/cheat-sheet/>
- Extended syntax <https://www.markdownguide.org/extended-syntax/>
