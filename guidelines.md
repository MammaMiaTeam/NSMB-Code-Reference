# Coding Guidelines

### Casing
The reference uses lowercase starting camelCase. That means, all variables, arguments, functions start with a lowercase word and every other word starts uppercase.
```cpp
void thisIsMyFunction(bool argumentOne, int test2);
```
Classes, structs, namespaces (all structures creating a new scope) take uppercase starting CamelCase.
```cpp
class MyClassBeingEpic : public OldBaseClass {};
```
Underscores are strictly forbidden outside of internal, compiler/runtime library emitted symbols.

### Indentation
You should **always** use tabs when indenting comments, members, other scopes. **No spaces are allowed.** This is necessary to ensure proper formatting.

New scopes are always indented once.
```cpp
struct Test {

	int a;		//First comment
	char b;		//Second comment
	
};
```
One space is added before/after brackets in general. There are tons of exceptions, so here are the important examples:
```cpp
if (condition) {
} else if (false) {
} else {
}

switch (number) {
}

struct A {
};
```
Brackets come always after their declaration. You can observe this in the example above.
There is *one* exception where brackets must appear in the next line:
```cpp
class Test : public LMAO
{
public:

};
```
### Includes
Headers always take
```cpp
#ifndef NSMB_x_H_
#define NSMB_x_H_

#endif // !NSMB_x_H_
```
as an include guard. It is good practice to comment the defined preprocessor symbol after endif when closing a scope.

### Storage Objects
Structs are to be used when the object purely consists of variables or has only a constructor with a few accompanying members / functions.

Classes are used for inheritance, when a vtable exists or are simply larger. They always take public as their visibility specifier (members and inheritance), eexceptions may exist.

Both classes and structs can *only* have static functions if the following conditions are met:
- The static is used in a class-related context
- The code is packed together to assume static linkage
- It doesn't fit into a related namespace

For all other cases, static functions should appear in public namespaces as non-statics. Static variables not fitting in a class due to above constraints are to be declared `extern` in a namespace.

Namespaces should be used for global, static functions.

### Grouping
In storage objects, members are packed as follows:
- Members
- Static members
- Constructors and destructors, ranging from default to parametric to non-virtual destructor in order
- Virtual functions
- Member functions
- Static functions

Between each category there is at least one newline. You can add more newlines in a category to subdivide them further.
Virtual functions must be in vtable order to allow correct virtual dispatch.

### Commenting
Comments are crucial for documentation. Single-line comments are used as follows:
```cpp
void callMe();		//Enter text here
```
Single-line comments should be grouped with tabs wherever possible.
They may also appear above function definitions.

Multi-line comments are almost always above the documenting object and are used as follows:
```cpp
/*
	Comments start on the next line with a tab.
	Another line OMEGALOL
*/
void doStuff();
```
There are cases where a member variable requires more explanation (e.g. masked fields). The multi-line comment should then start in the same line as the definition and be properly indented to match the above style.

### Documentation
All classes/functions and related variables are to be documented. If there are functions/variables without a properly defined context, end the file with a comment to indicate unknown functions.

**Note that this is the only exception. A documentation block is not counted as finished as long as functions are still missing.**

Variables and functions must be fully analyzed. That means, to decide on a name
- the caller context
- the callee context
- and the function itself

must be understood. As a result, names such as `decrementCount` are to be used with caution. The callee context may e.g. imply it's actually a `decrementTimer` function.

Names never describe the in-game contextual functionality.
As an example, there may be a function that is used to spawn Bowser specifically in world 8. 
However, only because it's used in world 8 doesn't immediately imply it can only be used to spawn him in limited scope.
It could reveal you can use it to spawn any boss anywhere, so don't draw conclusions from an in-game perspective.
This is mandatory to ensure usability for modding. (Variables used for *really* only one purpose in-game may be named specifically, though)

### Casting
C-style casts are forbidden. To cast pointers, use `reinterpret_cast<>`.

### Types
Standard C++ types are discouraged. To keep the repo consistent, use `u8`, `u16`, `u32` for unsigned types and `s8`, `s16`, `s32` for signed types.
Library typedefs can be found in `nitro_if.h`.

### Padding
**Never** use `__attribute__((packed))`. The target system is fixed so rely on gcc struct padding rules.
Be careful with padding and inheritance. Consider the following case:
```cpp
class A
{
public:
	u32 a;
	u8 b;
};

class B : public A
{
public:
	u8 c;
	u32 d;
};
```
yields a dangerous situation. The compiler will pad c immediately after b. 
B therefore has a size of 12 bytes instead of the expected 16. To avoid this, add `alignas(4)` above the first member of all subclasses.

### Abbreviations
Abbreviations are context-dependent. The casing depends on the general usage, so everything is fine as long as they're consistently used. Exception: ID is always spelled uppercase.

### Symbols
Symbol generation is one of the hardest task. Every fully documented section requires symbol generation. Symbols need to be properly mangled after the Itanium ABI. For symbol generation, contact one of the contributors to help you.
Symbols that **must** be generated include
- Functions
- Static variables
- Extern variables
- All constructors / destructors
- Vtables

Deleting destructors take D0. Standard destructors called from outside take D1. Class inheritance destructors take D2.
Standard constructors take C1. Class inheritance constructors take C2.
If you don't know what any of this means, let a contributor generate them for `symbols.x`. Always group symbols together.

###  Other
If you are unsure about a rare case, make a pull request and it will be reviewed.
Already documented parts can also be used as a guideline reference.


