n, m = input().split()
n = int(n)
m = int(m)
result = 1
if n - m < m : 
    m = n - m
for i in range(m):
    result *= n
    n = n - 1

for i in range(m):
    result //= m
    m = m - 1
    
print(int(result))