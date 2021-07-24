A C++ library for interfacing with a few keyboard IC's.

![Status](https://github.com/cmumford/kbdlib/actions/workflows/push_audit.yml/badge.svg)

Supported Keyboard IC's:

1. [ADP5589](https://www.analog.com/en/products/adp5589.html#)
2. [LM8330](https://www.ti.com/product/LM8330)
2. [TCA8418](https://www.ti.com/lit/ds/symlink/tca8418.pdf)

This library does not communicate with the IC's via I<sup>2</sup>C. Instead
it contains enums, types, and register definitions to make it easier to
decode and encode register values.

## Developer Notes

### Code formatting

All code should be formatted as so:

```shell
clang-format -i <source_file>
```
