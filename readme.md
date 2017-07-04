
# The Skylight Programming Language

## Intro
Skylight is a shell and programming language currently being designed. It's syntax takes inspiration from the C language family, Rust and particularly Swift. It also can be run as a shell and supports simple BASH-like syntax to run commands.

### Purpose of This Document
This document will be the complete language specification. For now, I'm keeping it short to save your time and mine. If something isn't specified, just assume its the same as any other modern C-style language (it is assumed you are familiar with at least one). If something is really unclear, ask me or open and issue and I will fix it.

### Future Plan
My last language, [Pinecone](https://pinecone-lang.herokuapp.com/index.html) was designed and implemented in parallel with little external feedback. While this suited the goals of that project in some ways, it was not ideal in others. This time around I will design the language, get feedback and iterate on the design several times before I begin implementation. This document on GitHub is the single source of truth of the current specification of the language. Once I get to a design I'm happy with and others are excited about, I will begin implementation. I have some cool ideas about bootstrapping a self compiler, but now I'm getting ahead of myself.

### Give Feedback!
If you have questions or suggestions, send them my way. Don't worry if they are too vague, too specific, or too unusual. The worst that could happen is I tell you your a fucking idiot with terrible ideas. If you have me on social media, message me there or email me at w​​​​ilco​ze ​@​ gm​​​​ai​l​.​c​om otherwise.

## Guiding Principles

### Easy
Skylight will be easy to read, write and learn. This means using syntax developers already know where applicable, and inventing new patterns where needed for reasons of simplicity or clarity. Creating functions and data structures should have little syntax overhead.

### Versatile
Skylight will be used as both a shell, a scripting language and a serious programming language. It should be suited for a wide veriaty of uses, including large scale applications. It should not sacrifice tools needed for any context without good reason.

### Fast
Or, more precisely, optionally fast. It will be possible to run Skylight code one line at a time, interpret it or compile it for improved performance. As such, Skylight will be type safe. Don't worry, this doesn't make it harder. It actually makes it easier because the compiler will catch type errors.

## Basic Syntax

### Comments
```
# this is a single line comment

//
this is a block comment
it can go on for several lines
\\

// or start and end on the same line \\
```

### Variables
A variable is a place to store data that can only be known when the program runs
```
# declare a variable that holds integers
var a = 6

# change the value of the variable
a = a + 1

# declare an immutable variable that holds strings
# (a variable that's value need not be known at compile time but can only be set once)
let b = "Skylight"

# this would cause a compile time error, because changing an immutable variable is not allowed
#b = "abc"

# does not cause an error because new variable of same name is created
# this is known as shadowing
# note that the new variable can be a var or a let, and it can be of any type
var b = false
```

### Tuples
Tuples are variables that hold multiple values. The types of the values may be different. Names are optional for each value. Unlike other languages where tuples are an afterthought, in Skylight they are the only method of creating complex data structures.
```
# create tuples
let c = (5.2, false)
var d = (a: 7, b: "abc", the_bool: true)

# use tuples
print c.1 ", " d.b
# output is 'false, abc'
```

### If/If Else
```
if true {
	# ...
}

if a == b {
	# ...
} elif some_func() {
	# ...
}
```

### Loop
There are several ways of doing loops in Skylight, the most interesting of which is the simple `loop {}` syntax. This is equivalent to `while true {}`, but make the intention to break out of the loop from the inside explicit.
```
loop {
	# endless loop until break

	if should_stop {
		break;
	}
}

while condition {
	# ...
}

for i in 0..10 {
	# start..end syntax is inclusive on for the start and exclusive for the end
	# if start >= end no iterations will be run
	
	# ...
}
```

### Function
```
func my_name() {
	# ...
	return something
}

func another_one(arg0, arg1) {
	# ...
	# or no return
}
```

## Commands
A special type of expression is a command, which is like a BASH command. An expression is processed as a command if starts with a `$`, or you are running in implicit command mode and the first identifier in the expression is not known in the program. Commands are parsed as a list of white space separated string literals at compile time. For example, the command `ls -A "../dir with spaces"` is parsed as `run_command("ls", "-A", "../dir with spaces")`

### Implicit Command Mode
Implicit command mode attempts to run commands whenever an expression starts with an identifier that isn't known. It is useful for running Skylight as an interactive shell, where starting every line with `$` may be annoying. Using it for scripts is discouraged because it causes less errors to be caught at compile time, makes code less readable and stops the grammar from being context free. There will be some mechanism for switching it on and off.

### Expressions in Commands
You can use a variable or expression in a command by wrapping it with `[]`
```
let a = 7
echo a is [a], [12 + 2.9] [sin(3.2)]
# output: a is 7, 14.9 0.0558215
```

## References
Primitives and tuples are pass-by-value by default. There are to types of references you can use, each for a specific purpose.

### Caged References
Sometimes you want to move values around efficiently without the hassle of reference counting or memory management. Caged references are great for this. The value they refer to can be on the stack or the heap, and is guaranteed to exist as long as the reference is around. That means if you send a caged reference into a function, the item will not be destroyed under any circumstances until the function returns. This also means that it must be clear to the compiler when a caged reference will go out of scope, so no value accessible outside of the current scope may be set to a caged reference, or it could 'escape'.
```
# an anonymous global variable with the initial value of 5 is created
# the global variable x is set to refer to the 5 holding global
var x = &5

func take_ref(a: &int) {
	print a
	# output: 3
	
	# this would cause a compile time error
	# the values in references are immutable unless they are sent in with &
	# a = 7
	
	# this would cause a compile error, because references can not escape the current scope
	# x = a
	
	# this works because it is manually dereferencing and copying values
	# in fact the ^ before the x or the a can be omitted and the line will act the same
	^x = ^a
}

# 3 is placed in an anonymous stack variable
take_ref(3)

# with this version of the call, the operations that modify the value a would work
# because 3 is converted to a reference explicitly
take_ref(&3)
```

### Shared References
When you need more flexibility then a caged reference, you use a shared reference. Shared references have values stored on the heap and use automatic reference counting for memory management. To make one, simply use the `ref` keyword before the thing you want a reference to. The space for that thing will be heap allocated, it will be copied there and a shared reference will be returned.
```
{
	# allocate an int reference to 9
	var a = ref 9
	
	# copy reference (not data)
	var b = a
	
	# manually dereference and copy data
	var c = ^a
	
	# change the value a refers to
	a = 12
	
	print "b is " b ", c is " c
	# output: b is 12, c is 9
}
# a and b both go out of scope, so the reference count drops to 0 and the memory is freed
```

## Advanced Functions
In Skylight, type syntax in functions is optional. This is because all functions are lazily compiled. They only get compiled if/when they are called and only for whatever types are calling them. They are implemented similarly to templates and generics in other languages.

### Declaration
```
func my_name(a: int, b: dub || string, c: int.array, d) -> bool {
	# a is of type int
	# b is of type dub or string
	# c is of type array of ints
	# d can be of any type
	
	# function is created like a C++ template, so there is no runtime cost to flexible typing
	
	# ...
	
	return true
	# return type may be implicit or explicit (sometimes, such as recursive functions, it must be explicit)
}
```
### Left Hand Input
```
# declaring a function that takes left hand input
func (a, b: int)add_all(c, d) {
	return a + b + c + d
}

# calling the function
let val = (12.2, 13).add_all(2, 1.7)
```

### Type Semantics
The only time there is explicit type syntax in Skylight is in function headers. To create a type, use the `construct` keyword instead of `func` and the function name will be usable to denote the type that function returns.
```
construct int_dub_tuple(a: int, b: dub) {
	return (i: a, d: b)
}

func use_tuple(val: int_dub_tuple) {
	print "int is " val.i ", dub is " val.d
}

# type error
use_tuple(4, 7.9)

# works
use_tuple(int_dub_tuple(4, 7.9))
```

## OOP
Skylight is not an object oriented language, but you can leverage object oriented syntax if that's what your program needs.

### Constructors
To start a class, simply write a constructor for it. Specifically write a function that returns a named tuple, or a pointer to a named tuple if you want your class to be pass by reference by default. If you want the function's name to be usable as a type (as you normally do for classes) you use the `construct` keyword.
```
construct cat(name: string, color: string, age: int) {
	if age < 0 {
		echo "cat is of invalid age $age"
		ohshit # abourt execution
	}

	return (
		name: name,
		color: color,
		age: age,
	)
}
```
Now lets use it
```
var my_cat = cat("Felix", "black", 6)
my_cat.speak()
```

### Methods
You can now put methods on classes by making functions that take a reference to the class as left hand input.
```
func (me: &cat) speak() {
	print me.name " says \"meow\""
}
```
There is a shortcut to make methods that gives implicit access to members and automatically makes input a reference.
```
func cat.speak() {
	print name " says \"meow\""
}
```

### Static Methods
To make a function be callable from a type, not an instance use a `~` before the type
```
func (a) is_it_cat() {
	return false
}

func ~cat.is_it_cat() {
	return true
}

print int.is_it_cat() # false
print cat.is_it_cat() # true
```

## Polys
A poly is a value that can hold multiple different types. They are how polymorphism and enums are done in Skylight. They are similar to Rust and Swift enums, in that they have several possible alternatives, and for each alternative there may or may not be an associated value of any type. The big difference is that the alternatives for a poly are not declared explicitly at the declaration.

### Creation
```
# create a poly with the name xyz and one alt. That alt is named (implicitly) int and holds an int
poly xyz = 3

# create an alt, 'abc' that deosn't hold any value and set xyz to it
alt xyz := abc

# create an alt cat_val that holds a cat but don't set xyz to it
alt xyz::cat_val: cat

# set xyz to 'cat' (alt is automatically selected based on type)
xyz = cat("Felix", "black", 6)

# w can use all the alts of xyz, but you can not add new alts to w
var w = xyz

# you can now add alts to v again
poly v = w
```

## Coming Soon
More content is coming soon to this spec, especially about Polys. Please give feedback on what is here and I'll get on adding more.
