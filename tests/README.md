# monty Tests
#### Max Stuart, 24 September 2019

_

### In this README:

__**testname**__ - _brief explaination_:
```
expected output
```
_

### In this /tests/ directory:

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
3
2
1
2
1
1
```
