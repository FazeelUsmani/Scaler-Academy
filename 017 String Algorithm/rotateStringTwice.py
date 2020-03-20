s1 = "amazon"
s2 = 'azonam'

x = s2[2:] + s2[:2]
if x == s1:
  print("YEs")

n = len(s2)
y = s2[n-2:] + s2[:n-2]
if y == s1:
  print("Yes")


