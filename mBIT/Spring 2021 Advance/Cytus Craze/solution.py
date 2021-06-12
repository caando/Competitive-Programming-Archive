from math import ceil
from math import log2
from math import floor
mod = int(1e9+7)


def fast_exp(x, exp):
    ans = 1
    base = x
    while exp:
        if exp & 1:
            ans *= base
        base *= base
        base %= mod
        ans %= mod
        exp >>= 1
    return ans


n, k = [int(x) for x in input().split()]
k = min(k, pow(2, floor(log2(n+1)+1))-1)
n += 1
exp = n - 1 - ceil(log2(n))
val = fast_exp(2, exp)
ans = (((k+1) % mod)*(val % mod)) % mod
print(ans)
