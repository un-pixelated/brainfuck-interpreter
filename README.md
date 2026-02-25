yabi - yet another brainfuck interpreter.

So this was a project I've been wanting to make for quite a while now
And so I sat down one day and decided to build it, and it's here.
It's not as polished as some other intepreters out there, I mean it's just two
while loops and kind of a menu interpreter, but it works. And it's pretty fast because it's
written in C.

Getting started with brainfuck:

A good YouTube video by fireship which does a really godo job at telling you about the history of the language and how it works: https://www.youtube.com/watch?v=hdHjjBS4cs8

If you are a fan of written tutorials you can read this article: https://learnxinyminutes.com/bf/

Interpreter spec:
length of cell array is 30000
the amount of data which can be stored in a cell is 7 bits, so 0 to 127
and it wraps around

and the cell array also wraps around if you move ahead at the end of the cell array or
if you move behind at the beginning of the cell array

The stack's max size is 1024 and that's the nesting depth of the loops
