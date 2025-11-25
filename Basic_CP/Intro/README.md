# Introduction
---
**Note**
- Include / Import headers for basic Input/Output(I/O) functions - `stdio.h` in c, `iostream` in c++, `fmt` in go.
- For print use `printf()` in c, `cout` in c++, `fmt.Printf()` in go.
- Every program starts from the `main function - main()`.
- `"\n"` is used for printing new line. 

**C Code**
```c
#include<stdio.h>

int main() {
	printf("ANYTHING\n");
}
```

**C++ Code**
```c++
#include<iostream>
using namespace std;

int main() {
	cout << "ANYTHING" << "\n";
}
```

**GO Code**
```go
import "fmt"

func main() {
	fmt.Println("Anything")
	fmt.Printf("Anything\n")
}
```
---
**Problem-List**
- [Hello World](https://vjudge.net/problem/Aizu-ITP1_1_A)