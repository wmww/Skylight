# C++ Macro Implementation of Skylight
This implementation is not meant to be complete, of even compliant with the Skylight standard. Its sole purpose is to facilitate the bootstrapping of the Skylight self compiler.

## Design
This is more of a C++ framework then a language implementation. It is a collection of functions, macros, etc. that allow you to write valid C++ code in the style of Skylight.

## Purpose
This is the first implementation of Skylight. The next implementation will be a simple (also not standard compliant) Skylight to C transpiler. That implementation will be written in Skylight-like C++ using this framework. When it is complete, I will port its code from the Skylight C++ hybrid that code written with this implementation is, to Skylight which can be transpiled by the next implementation. Porting should be very easy because the paradigms are the same, the only differences will be removing the syntactical annoyances imposed by the limitations of C++. At that point I will have a self compiler (or rather a self transpiler), which than I can continue to iterate on without ever needing to write a full Skylight implementation in a language other then Skylight.