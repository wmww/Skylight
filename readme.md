
# The Skylight Programming Language

## Intro
Skylight is a shell and programming language currently being designed. It's syntax takes inspiration from the C language family, Rust and particularly Swift. It also can be run as a shell and supports simple BASH-like syntax to run commands.

## Purpose of This Document
This document will be the complete language specification. My last language, [Pinecone](https://pinecone-lang.herokuapp.com/index.html) was designed and implemented in parallel with little external feedback. While this suited the goals of that project in some ways, it was not ideal in others. This time around I will design the language, get feedback and iterate on the design several times before I begin implementation. This document on GitHub is the single source of truth of the current specification of the language. If you want to give feedback, please join the discussion on [this reddit thread that I forgot to link so it won't work](https://http.cat/404).

## Guiding Principles

### Easy
Skylight will be easy to read, write and learn. This means using syntax developers already know where applicable, and inventing new patterns where needed for reasons of simplicity or clarity. Creating functions and data structures should have little syntax overhead.

### Versatile
Skylight will be used as both a shell, a scripting language and a serious programming language. It should be suited for a wide verity of uses, including large scale applications. It should not sacrifice tools needed for any context without good reason.

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

# declare an imitable variable that holds strings
# (a variable that's value need not be known at compile time but can only be set once)
let b = "Skylight"

# this will cause a compile time error
b = "abc"

# does not cause an error because new variable of same name is created
var b = false
```

### Tuples
```
let c = (7, "abc", true)
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
	# ...
}
```

### Functions
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

## Commands
A special type of line is a command, which is like a BASH command. A line is processed as a command if it is __NOT__ any of the following patterns:
* Starts with keyword (`var`, `func`, `if`, etc.)
* Starts with identifier followed by `=` (can have white space)
* Starts with identifier followed by `(` (with no white space in between)
* Starts with identifier followed by `.` (with no white space in between)
* Maybe more in the future
As you can see, any useful statement in Skylight will start as one of those, so if a line doesn't it may be parsed as a command. Commands are parsed as a list of white space separated string literals at compile time. For example, the command `ls -A "../dir with spaces"` is parsed as `runCommand("ls", "-A", "../dir with spaces")`

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

## Coming Soon
More content is coming soon to this spec. Please give feedback on what is here and I'll get on adding more.

