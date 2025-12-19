# generic_c

> [!WARNING]
> This library is still under development and not suggest to use in production.

## Overview

generic_c is a C library that brings generic/template programming capabilities to the C language, similar to what C++ STL provides. It allows developers to work with containers that can hold any data type, making C code more flexible and reusable.

Currently, the library includes implementations of dynamic arrays (`Vec`) and static arrays (`Array`).

## Features

- Generic containers that can store any data type
- Dynamic array (`Vec`) with automatic resizing
- Static array (`Array`) for fixed-size collections
- Memory-safe operations with bounds checking
- Simple and consistent API design

## Usage

To use this library in your project, simply copy the `src/include` directory into your project and include the necessary headers.

```c
#include "generic_c.h"
```

## API Template

generic_c provide consistent style api for template programming. Each function starts with **Generic** and followed by the name of the container and function.
