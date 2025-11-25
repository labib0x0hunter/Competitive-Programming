# Basic Data Types
---
**Variables-Notes**
- int : 4/8bytes, 32bits / 64bits ( `int` in c,c++, go )
- long long : 8bytes, 64bits ( `long long` in c,c++. `int64` in go )
- char : 1byte, 8bits ( `char` in c,c++. `byte` in go )
- double : 8bytes, 64bits ( `double` in c,c++. `float64` in go )
- For precision use `printf("%0.2f", d)` or `cout << fixed << setprecision(2) << d` which will print 2digits after dot.
- `fixed` and `setprecision()` are defined in `<iomanip>` header.
- `printf()` and `scanf()` are defined in `<stdio.h>` header.
- `cin` and `cout` are defined in `<iostream>` header.

**C,C++ Var**
```c
int a;
long long a;
char a;
double a;
```

**GO Var**
```go
var a int
var a int64
var a byte
var a float64
```
---

**Input-Notes**
- For input use `scanf()` in c, `cin` in c++, `fmt.Scanf()` in go
- %d : int
- %lld : long long
- %c : char
- %f : float
- %lf : double

**C Code**
```c
int a;
long long b;
char c;
double d;
scanf("%d %lld %c %lf", &a, &b, &c, &d);
```

**C++ Code**
```c++
int a;
long long b;
char c;
double d;
cin >> a >> b >> c >> d;
```

**GO Code**
```go
var a int
var b int64
var c byte
var d float64
fmt.Scanf("%d %d %c %f", &a, &b, &c, &d)
```

---
**Problem-Lists**
- [Basic Data Types](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/B)