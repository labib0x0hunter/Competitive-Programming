# Operators
---

**Notes**
- In `go` `int` might pass multiplication without overflow because of the system. In 32bit architecture int works as 32bit and for 64bit architecture as 64bit.
- In `c` or `c++`, you have to `typecast` int into `long long` (eg. `1ll * a * b`) to avoid overflow of 32bit int.
- `setw(2)` will fix how many spaces are to be filled, here 2.
- `setfill('0')` will fill the empty spaces fixed by `setw`
- `setw()` and `setfill()` are included in `<iomanip>` header.
- `printf("%02d\n", d);` pad with 0, and minimum width 2. same as `setw(2)` and `setfill('0')`.

**Problem-Lists**
- [PB01](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/C)
- [PB02](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/D)
- [PB03](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/E)
- [PB04](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/R)
- [PB05](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/G)
- [PB06](https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/Y)