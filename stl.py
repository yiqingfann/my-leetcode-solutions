# summarize C++ STL equivalents in python3

# https://www.acwing.com/file_system/file/content/whole/index/content/3598249/
# https://blog.csdn.net/qq_44514871/article/details/104096128
# https://codeforces.com/blog/entry/49249
# https://vibhu4agarwal.hashnode.dev/python-cs-stl-data-structures-and-their-equivalents

# ---------------------general---------------------


# ---------------------if---------------------
# if () {
# } else if () {
# } else {
# }

# if ():
# elif ():
# else


# a = 1
# b = 2
# if a > b and a < b:
#     print("hello")
# elif a == b:
#     print("")
# else:
#     print("")

# ---------------------loop---------------------
# for (int i = 0; i < n; ++i) {
#   cout << a[i] << endl;
# }
# for i in range(0, n):
# for i, v in enumerate(a):

# while (l < r) {
# }
# while l < r:


# a = [1, 2, 3]
# for i in a:
#     i = 5
# for i, v in enumerate(a):
#     a[i] = 5
# l, r = 0, 2
# while l < r:
#     mid = (l + r + 1) >> 1
#     if (a[mid] < 5):
#         l = mid
#     else:
#         r = mid - 1
# print(r)
# print(a)


# ---------------------vector---------------------
# https://blog.csdn.net/weixin_44256972/article/details/122238864

# add elem
# a.push_back() -> a.append()
# a.insert(pos iter, val) -> a.insert(pos, val)

# remove elem
# a.pop_back() -> a.pop()
# a.erase(a.begin() + pos) -> a.pop(pos)

# access elem
# a.front() -> a[0]
# a.back() -> a[-1]

# length
# a.size() -> len(a)

# sort
# sort(a.begin(), a.end(), comp) -> a.sort(reverse=True, key=)
# bool comp(const int &u, const int v) {
#   return u > v; // u在v左边的条件。想要降序，那么u在v左边如果u > v
# }
# auto comp = [](const int &a, const int &b) {
#   return a > b;
# }
# key = lambda x: x["age"]

# reverse
# reverse(a.begin(), a.end()) -> a.reverse()

# init
# vector<int> a(n, 0) -> a = [0] * 10

# copy
# b = a -> b = a[:] or b = a.copy()


# a = [5, 1, 2, 7, 3]
# a.pop(1)

# a.clear()
# a.append(1)

# a.reverse()


# def func(x):
#     return x


# a.sort(key=func)

# a = [0] * 10

# b = a.copy()
# b[0] = 1

# b = a[0:1]
# print(b)

# print(a)

# ---------------------stack---------------------

# a.append(), a.pop()
from heapq import *
import queue

# stk = queue.LifoQueue()
# stk.put(1)
# stk.put(2)
# stk.put(3)
# while stk.qsize():
#     print(stk.get())

# a = []
# a.append(1)
# print(a.pop())

# ---------------------queue---------------------
# queue<int> q;
# q.push(), q.front(), q.pop()

# q = queue.Queue()
# q.put(1)
# q.put(2)
# q.put(3)
# while q.qsize():
#     print(q.get())

# ---------------------heap---------------------

# https://stackoverflow.com/questions/2501457/what-do-i-use-for-a-max-heap-implementation-in-python


# class MaxHeapObj:
#     def __init__(self, val):
#         self.val = val

#     def __lt__(self, other):
#         return self.val > other.val

#     def __str__(self):
#         return str(self.val)


# heap = []
# heapify(heap)
# heappush(heap, MaxHeapObj((1, 100)))
# heappush(heap, MaxHeapObj((5, 1)))
# heappush(heap, MaxHeapObj((3, 50)))
# heappush(heap, MaxHeapObj((2, 30)))
# heappush(heap, MaxHeapObj((1, 99)))
# heappush(heap, MaxHeapObj((1, 10)))
# heappush(heap, MaxHeapObj((1, 1000)))

# while len(heap):
#     print(heappop(heap))


# class MinHeap(object):
#     def __init__(self): self.h = []
#     def heappush(self, x): heapq.heappush(self.h, x)
#     def heappop(self): return heapq.heappop(self.h)
#     def __getitem__(self, i): return self.h[i]
#     def __len__(self): return len(self.h)


# class MaxHeap(MinHeap):
#     def heappush(self, x): heapq.heappush(self.h, MaxHeapObj(x))
#     def heappop(self): return heapq.heappop(self.h).val
#     def __getitem__(self, i): return self.h[i].val


# minh = MinHeap()
# maxh = MaxHeap()
# # add some values
# minh.heappush(12)
# maxh.heappush(12)
# minh.heappush(4)
# maxh.heappush(4)
# # fetch "top" values
# print(minh[0], maxh[0])  # "4 12"
# # fetch and remove "top" values
# print(minh.heappop(), maxh.heappop())  # "4 12"

# ---------------------set---------------------
# unordered_set<int> s;
# s.insert(), s.count(), s.erase(), iterate

# s = {1, 3, 2}
# s.add(5)
# print(5 in s)
# s.remove(1)
# print(s)

# for i in s:
#     print(i)
# ---------------------map---------------------
# unordered_map<string, int> h;
# h["a"] = 1, h.count(), h.erase(), iterate

# h = {}
# h["a"] = [1, 2, 3]
# h["c"] = [1]
# h["d"] = [100]
# print(h.get("b", None))
# print("a" in h, "b" in h)
# print(h.pop("a", None))
# for k, v in h.items():
#     print(k, v)

# ---------------------func, assign: pass by ref/copy?---------------------
# def change(a):
#     print(f"2: {a}")
#     a += ["hello"]
#     print(f"3: {a}")


# a = ["haha"]
# print(f"1: {a}")
# change(a)
# print(f"4: {a}")

s = ["hello", "world"]
print(s)

for i, v in enumerate(s):
    s[i] += "haha"

print(s)
