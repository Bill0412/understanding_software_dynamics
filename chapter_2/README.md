# Chapter 2 Exercise

## 2.1

The code is at [add_instruction.cc](add_instruction.cc).

The output is like this:

```
$ g++ -O0 add_instruction.cc -o add_instruction
$ ./add_instruction 
1000000000 iterations, 5830624785 cycles, 5.83 cycles/iteration
```
Adding and assignment take about 1 cycle each.

## 2.2
```
$ gcc -O0 mystery1.cc -o mystery1
$ ./mystery1
1000000000 iterations, 5124964456 cycles, 5.12 cycles/iteration
$ gcc -O2 mystery1.cc -o mystery1
$ ./mystery1
1000000000 iterations, 18 cycles, 0.00 cycles/iteration
```

The compiler optimizes the loops when using `O2`


## 2.3

```
$ gcc -O0 mystery1.cc -o mystery1
$ ./mystery1
1000000000 iterations, 5132120795 cycles, 5.13 cycles/iteration
1757599242 10000000000
$ gcc -O2 mystery1.cc -o mystery1
$ ./mystery1
1000000000 iterations, 18 cycles, 0.00 cycles/iteration
1757599280 48000000000
```

## 2.4
```
$ gcc -O0 mystery1.cc -o mystery1
$ ./mystery1
1000000000 iterations, 5583559818 cycles, 5.58 cycles/iteration
1758033898 234000000000

$ gcc -O2 mystery1.cc -o mystery1
$ ./mystery1 
1000000000 iterations, 5824655548 cycles, 5.82 cycles/iteration
1758033955 35000000000
```

The for loop is not being optimized for both `O2` and `O0`. But `O2` is still a bit faster than `O0` for other parts.

## 2.5
[code](measure_64bit_add.cc)

```
$ gcc -O2 measure_64bit_add.cc -o measure_64bit_add
$ ./measure_64bit_add 
1000000000 iterations, 819715439 cycles, 0.82 cycles/iteration
```
Adding is close to 1 cycle.

## 2.6
[code](test_number_of_loops.cc)

```
$ gcc -O2 test_number_of_loops.cc -o test_number_of_loops
$ ./test_number_of_loops 
1 iterations, 21 cycles, 21.00 cycles/iteration
10 iterations, 112 cycles, 11.20 cycles/iteration
100 iterations, 519 cycles, 5.19 cycles/iteration
1000 iterations, 5862 cycles, 5.86 cycles/iteration
10000 iterations, 61103 cycles, 6.11 cycles/iteration
100000 iterations, 603743 cycles, 6.04 cycles/iteration
1000000 iterations, 6161044 cycles, 6.16 cycles/iteration
10000000 iterations, 61914840 cycles, 6.19 cycles/iteration
100000000 iterations, 578439901 cycles, 5.78 cycles/iteration
1000000000 iterations, 6054755228 cycles, 6.05 cycles/iteration
```

The number of loops converge at 6 cycles. When the number of tests is too small, the code we are not interested in are also counted. When the number of tests increase, those code are being averaged out.