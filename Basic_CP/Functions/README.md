# Function
---
```c,c++
int FuncName(int x) {

}
```

```c++
auto FuncName = [](int x) int {
    return 10;
}

function<void(int)> FuncName = [&](int x) {
    x = x + 1;
}
```

```go
func FuncName(n int) (int, error) {
    return n + 10, nil
}

f := func(int x) (int) {
    return x + 10
}

f(10)
```
---
**Note**
- For comparing if two doubles are equal, lets `EPS = 1e-9` then check `fabs(a - b) < EPS == true`.
- `gcd()` is defined in `<numeric>`.
---
**Problem-Lists**
- [PB01](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/H)
- [PB02](https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/E)
- [PB03](https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/L)
- [PB04](https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/C)
- [PB05](https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/J)
- [PB06]()
- [PB07]()
- [PB08]()