
# Complete Specification Skylight Shell/Programming Language

## Intro
Skylight will be a Unix shell and high level general purpose programming language. Unlike most shells and scripting languages, Skylight will be statically typed and have an option to compile for increased performance. The syntax takes inspiration from Swift, Rust and the C language family, while still being compatible with basic BASH style commands.

## Motivation
The goal of Skylight is to be a single language for all levels of software. Instead of having a different syntax for your shell, scripts, build system and primary code base, they can all be Skylight. Skylight will reduce context switching and be a pleasure to work in at all stages of development. The improvement over existing languages will be particularly noticeable in the field of shell scripting, where there is huge room for improvement.

## Purpose of This Document
This document is to eventually be the complete specification of the language. My last language, [Pinecone](https://pinecone-lang.herokuapp.com/index.html) was designed and implemented in parallel with little external feedback. While this suited the goals of that project in some ways, it was not ideal in others. This time around I will design the language, get feedback and iterate on the design several times before I even begin implementation. This document on GitHub is the single source of truth of the current specification of the language. If you want to give feedback, please do not open a GitHub issue but instead join the discussion on [this reddit thread that I forgot to link so it won't work](https://http.cat/404).

## Context Free Grammar
Skylight uses a context free grammar, which means that "context" (aka things defined in the source code like variable and function names) does not determine how future lines are parsed.

## Two Types of Lines
Skylight has two types of lines, commands and statements. Commands are like BASH commands and statements are like statements in traditional languages. There are also expressions, which are a subset of statements. The difference between expressions and other statements is that expressions return a value and can be nested. Here are some examples of each:
%%%
# commands:
ls
ls -A -R
git commit -m "bug fixes"

# statements (not expressions):
var a = 12
func concat(a, b, c) {return a.str() + b.str() + c.str()}
a = 24 + 2

# statemnts (are expressions):
24 + 2
concat(12, "xyz", true)
34.str()
%%%
Statements and expressions are parsed with the same rules, but commands are pared differently. Every argument to a command is treated as a string litetral. Whether a line is a statements or command is determined by the first token in the line. If it is a keyword like func, or while, or if it is a known token previously declared with func or var then the line is treated as a statement. If it is a command declared with the cmd keyword, then the line is treated as a command. If it is unknown the line will generate an error.


