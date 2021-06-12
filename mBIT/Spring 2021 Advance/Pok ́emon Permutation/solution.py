import sys
from sys import stdout
import io, os

# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# input = sys.stdin.buffer.readline
input = lambda: sys.stdin.readline().strip()
P = lambda: list(map(int, input().split()))
from math import factorial as f, gcd
from collections import deque, defaultdict as dd, Counter as C
from heapq import heapify, heappop, heappush, heappushpop, heapreplace, merge
from random import randint, choice, sample
import time
mod = 10**9+7
a = ord('a')


start = time.time()
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

def countBits(n):
    count = 0
    while n:
        count += n & 1
        n >>= 1
    return count

def submasks(n):
    #this is cool
    #https://cp-algorithms.com/algebra/all-submasks.html
    org = n
    while n:
        yield n
        n = (n-1) & org

def solve():
    s = input()
    c = C(s)
    v = list(c.values())
    g = v[0]
    for i in v:
        g = gcd(g, i)
    if g == 1:
        print('IMPOSSIBLE')
        return
    part = ""
    for k, v in c.items():
        part += k*(v//g)
    print(part * g)
    






# tc = int(input())
# for t in range(1, tc+1):
#     solve()

solve()
# print(time.time()-start)


