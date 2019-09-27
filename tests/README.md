# monty Tests
#### Max Stuart, 24 September 2019
___
### To Use These Tests
You'll need:
- the `monty` program compiled using `gcc 4.8.4` (most easily setup on `ubuntu 14.04.4 (trusty-64)`)
- and Valgrind (`sudo apt-get install valgrind`).
From the /monty/ directory run:
```
:~/monty$ gcc -Wall -Werror -Wextra -pedantic *.c -g -o monty
```
then:
```
:~/monty$ valgrind --track-origins=yes --leak-check=full ./monty ./tests/<testfilename>
```
___
#### Below test explainations are formatted like so:
**_testfilename_** - _brief explaination_:
```
expected output
```
___
### The Tests In This /tests/ Directory

__0.m__ - checks result on empty file:
```

```

__1.m__ - checks result on file with only whitespace:
```

```

__ppush0.m__ - checks typo in beginning of opcode:
```
L1: unknown instruction ppush
```

__ppush1.m__ - checks typo in end of opcode:
```
L1: unknown instruction pushh
```

__ppush2.m__ - checks for capitolization in opcode:
```
L1: unknown instruction Push
```

__push0.m__ - checks extraneous spacing in correct usage of `push` and `pall` (sample code from README & instructions):
```
3
2
1
0
6
5
4
3
2
1
0
```

__push1.m__ - checks extraneous input after opcode / opcode + argument and newlines (more sample code from README & instructions):
```
3
2
1
0
6
5
4
3
2
1
0
```

__push2.m__ - checks for error on nothing provided after `push`:
```
L3: usage: push integer
```

__push3.m__ - checks for error on non-integer argument after `push`:
```
L1: usage: push integer
```

__push4.m__ - checks that line count on errors counts blank lines:
```
1
L4: usage: push integer
```

__push5.m__ - checks no error on pushing negative numbers:
```

```

__push6.m__ - checks for error on 1%1 non-integer argument after `push`:
```
L1: usage: push integer
```

__push7.m__ - checks for error on 1+1 non-integer argument after `push`:
```
L1: usage: push integer
```

__push8.m__ - checks for error on % non-integer argument after `push`:
```
L1: usage: push integer
```

__push9.m__ - checks whats the result of only + as argument after `push`:
```
0 (unknown if this is to be expected!)
```

__pall0.m__ - checks `pall` does nothing when stack is empty:
```

```

__pall1.m__ - checks basic `pall` usage:
```
3
2
1
```

__pall2.m__ - checks no error on printing negative numbers:
```
-3
-2
-1
```

__pint0.m__ - checks basic `pint` usage:
```
1
2
3
```

__pint1.m__ - checks `pint`'s error message:
```
L1: can't pint, stack empty
```

__pint2.m__ - checks `pint` prints multi-digit & negatives:
```
-1234
```

__pop0.m__ - checks `pop` basic usage:
```
303
7
```

__pop1.m__ - checks `pop` usage s'more:
```
3
2
1
2
1
1
```

__pop2.m__ - checks `pop`'s error message:
```
L1: can't pop an empty stack
```

__swap0.m__ - checks `swap`'s basic usage:
```
3
2
1
2
3
1
```

__swap1.m__ - checks `swap`'s error message for empty stack:
```
L1: can't swap, stack too short
```

__swap2.m__ - checks `swap`'s error message for stack of 1:
```
L2: can't swap, stack too short
```

__add0.m__ - checks `add`'s basic usage:
```
3
2
1
5
1
6
```

__add1.m__ - checks `add`'s error message on no stack (& that `pall` doesn't do anything):
```
L2: can't add, stack too short
```

__add2.m__ - checks `add`'s error message on stack of 1:
```
3
L3: can't add, stack too short
```

__add3.m__ - checks `add`'s handling of negative integers:
```
-25
-30
```

__nop0.m__ - checks that `nop` does nothing when alone:
```

```

__nop1.m__ - checks that `nop` does nothing in a sentence:
```

```

__nop2.m__ - checks that `nop` does nothing in a script:
```
1
69
70
```

__sub0.m__ - checks basic `sub` usage:
```
7
2
1
```

__sub1.m__ - checks `sub`'s error message on no stack:
```
L1: can't sub, stack too short
```

__sub2.m__ - checks `sub`'s error message on stack of 1:
```
L2: can't sub, stack too short
```

__div0.m__ - checks basic `div` usage:
```
2
1
```

__div1.m__ - checks `div`'s error message on no stack:
```
L1: can't div, stack too short
```

__div2.m__ - checks `div`'s error message on stack of 1:
```
L2: can't div, stack too short
```

__div3.m__ - checks `div`'s error message on attempted division by 0:
```
L4: division by zero
```

__comment0.m__ - checks comment normal usage
```
1
```
