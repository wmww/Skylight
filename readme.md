
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
```
# declare a variable that holds integers
var a = 6

# change the value of the variable
a = a + 1

# declare an imutable variable that holds strings
# (a variable that's value need not be known at compile time but can only be set once)
let b = "Skylight"

# this will cause a compile time error
b = "abc"

# does not cause an error because new variable of same name is created
# this is known as shadowing
var b = false
```

### Tuples
```
let y = (5.2, false)
let x = (a: 7, b: "abc", the_bool: true)
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

### Loops
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
	# if start >= end not iterations will be run
	
	# ...
}
```

## Commands
A special type of line is a command, which is like a BASH command. A line is processed as a command if it is __NOT__ any of the following patterns:
* Starts with keyword (`var`, `func`, `if`, etc.).
* Starts with identifier followed by `=` (can have white space).
* Starts with identifier followed by `(` (with no white space in between).
* Starts with identifier followed by `.` (with no white space in between).
* Maybe more in the future.

As you can see, any useful statement in Skylight will start as one of those, so if a line doesn't it may be parsed as a command. Commands are parsed as a list of white space separated string literals at compile time. For example, the command `ls -A "../dir with spaces"` is parsed as `run_command("ls", "-A", "../dir with spaces")`

### variables in commands
You can drop the values of variables into commands, just prepend the name with `$`.
```
var a = 12
echo a is $a
# output: a is 12
```

### expressions in commands
You can also use expressions in commands. To do so, wrap them in `[]`.
```
echo [12 + 2.9] [sin(3.2)]
# output: 14.9 0.0558215
```

## References
Pointers and references are always hard. I think I have a decent system.

### Shared References
The default reference in Skylight is a shared reference, which uses ARC for memory management. To make one, simply use the `ref` keyword before the thing you want a reference to. The space for that thing will be heap allocated, it will be copied there and a shared reference will be returned.
```
{
	# allocate an int reference to 9
	var a = ref 9
	
	# copy reference (not data)
	var b = a
	
	# manually dereference and copy data
	var c = *a
	
	# change the value a refers to
	a = 12
	
	echo b is $b, c is $c
	# output: b is 12, c is 9
}
# a and b both go out of scope, so the reference count drops to 0 and the memory is freed
```

### Caged References
Caged References are a way of efficiently passing stack and heap values around. The trade off is the memory referred to by caged references can never be freed while they exist and caged references can never escape the current scope.
```
# an anonymous global variable with the initial value of 5 is created
# the global variable x is set to refer to 5
var x = &5

func take_ref(a: &int) {
	echo $a
	# output: 3
	
	# this would cause a compile time error
	# the values in references are immutable unless they are sent in with &
	# a = 7
	
	# this would cause a compile error, because references can not escape the current scope
	# x = a
	
	# this works because it is copying values
	# in fact the * before the x can be omitted and the line will act the same
	*x = *a
}

# 3 is places in an anonymous stack variable
take_ref(3)
```

## Functions
In Skylight, type syntax in functions is optional. This is because all functions are lazily compiled. They only get compiled if/when they are called and only for whatever types are calling them. They are implemented similarly to templates and generics in other languages.

### Basic Usage
```
func my_name(a: int, b: dub || string, c: array(int), d) {
	# a is of type int
	# b is of type dub or string
	# c is of type array of ints
	# d can be of any type
	
	# function is created like a C++ template, so there is no runtime cost to flexible typing
	
	# ...
	
	return true
	
	# return type is implicit
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
The only time there is explicit type syntax in Skylight is in function headers. The names you use in them are simply the names of functions that return the type you want. Confused? here is an example:
```
func int_dub_tuple(a: int, b: dub) {
	return (i: a, d: b)
}

func use_tuple(val: int_dub_tuple) {
	echo int is [val.i], dub is [val.d]
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
var my_cat = cat("Felix", "black" 6)
my_cat.speak()
```

### Methods
You can now put methods on classes by making functions that take a reference to the class as left hand input.
```
func (me: &cat)speak() {
	echo [me.name] says \"meow\"
}
```
There is a shortcut to make methods that gives implicit access to members and automatically makes input a reference.
```
func cat.speak() {
	echo $name says \"meow\"
}
``` 

## Polys
A poly is a value that can hold multiple different types. They are the only way to do polymorphism in Skylight. They are similar in implementation to Rust and Swift enums, in that they have several possible alternatives they can be and for each alternative there may or may not be an associated value with a different type. The big difference is that the options a poly can be does not have to be declared explicitly.

## Coming Soon
More content is coming soon to this spec, especially about Polys. Please give feedback on what is here and I'll get on adding more.
