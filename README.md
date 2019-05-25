# beauty

Built-in Entities for Automatic Unit-testing, Y'all

## Overview

Beauty is a system for including a per-namespace unit test in C++ code.  It is
based on the idea that multiple `main` functions may co-exist in source, but
compiled separately. Namespaces in source may define at most one `main`
function. Source files that define a `main` function may be individually
compiled into executables, but may also be used as libraries.

This is roughly equivalent to the `if __name__ == '__main__'` idiom in Python,
which runs given code only if the current module was directly run by the user
and not imported as a library.

If this sounds like a bad idea, it's because it is.

## How to use

This example is a simple CMake project. You can compile like so:

```bash
mkdir build
cmake ..
make -j 4
```

This will create three executables: `main`, `beauties/flowers`, and
`beauties/gems`. The latter two are compiled and run `main()` functions from
within their respective namespaces.

## How it works

`main()` functions can exist inside of namespaces and be used as the program
entrypoint as long as they are prepended with `extern "C"`. This enables
creating `main()` functions per namespace for, for example, unit testing.
Namespaced `main()` functions can be excluded from library code with
preprocessor macros to allow the actual application `main` function to compile.

## Gotchas and other tricks

You don't need to hide the entire function with preprocessor macros as the
example shows. You can instead hide just the `extern "C"` prefix. This
retains `namespace::main()` functions with mangled symbols when compiled in
case the code contained within them is needed. However they cannot be used
to create an executable.

If you split the definitions of a namespace between multiple files, you
_can_ have a `main()` per file, so long as you do not try to compile
multiple files containing `main()`s at once into a single test executable.
That is, you can define multiple `main()`s per namespace, but you must take
care to not define multiple per executable. This is part of why it's a bad
idea to do this anyway.

The preprocessor macro can be a CMake-defined variable. This allows you to
enable/disable testing via CMake.
