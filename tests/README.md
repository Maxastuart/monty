# monty Tests
#### Max Stuart, 24 September 2019


### In this README:

_testname_ - _brief explaination_:
_expected output_

### In this /tests/ directory:

push0.m - checks extraneous spacing in correct usage of `push` and `pall` (sample code from README & instructions):
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

push1.m - checks extraneous input after opcode / opcode + argument and newlines (more sample code from README & instructions):
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

push2.m - checks for error on nothing provided after `push`:
```
L3: usage: push integer
```

push3.m - checks for error on non-integer argument after `push`:
```
L1: usage: push integer
```

push4.m - checks that line count on errors counts blank lines:
```
1
L4: usage: push integer
```

pall0.m - checks pall when stack is empty:
```

```

pall1.m - checks basic pall usage:
```
3
2
1
```

pint0.m - checks basic pint usage:
```
1
2
3
```

