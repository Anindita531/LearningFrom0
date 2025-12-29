from collections import Counter
import statistics

n = int(input())
arr = list(map(int, input().split()))

print(round(statistics.mean(arr), 1))
print(round(statistics.median(arr), 1))

freq = Counter(arr)
max_freq = max(freq.values())
mode_candidates = [k for k, v in freq.items() if v == max_freq]
print(min(mode_candidates))
