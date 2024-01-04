- (!) Целочисленное деление с округлением вверх: 

x / y -> ceil = [(x - 1) / y] + 1.

- Figure out why this works slower in runtime than in separate lines:
```
int a = 0, b = 0;
// VS
int a = 0;
int b = 0;
```

Explanation: it's just a bug that occured w/ LeetCode, runtime should remain the same.

- TODO: Find out when it is needed to specify c-tor and d-tor manually

- TODO: add links to .cpp files inside gh

- Clang-format usage: Shift + Option + F

- TODO: Split task explanation into multiple README.md's inside tasks (?)

- TODO: Explain the difference between NULL and nullptr