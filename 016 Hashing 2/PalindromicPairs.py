# Q) Given an array of strings, ["abcd", "dcba", "lls", "s", "ssll"]. All are unique strings. 
# How many palindromic pairs you can make from this array?


ans = []
string = ["abcd", "dcba", "lls", "s", "ssll"]

def checkPalin(S, start, end):
  if start > end:
    return True
  
  if S[start] == S[end]:
    return checkPalin(S, start+1, end-1)
  else:
    return False


def Palindrome(S):
  n = len(S)
  dict = {}
  for i in range(n):
    dict[ S[i][::-1] ] = i
  
  # Calculating for prefix
  for i in range(n):
    str = S[i]
    lenStr = len(str)

    for j in range(0, lenStr):
      sub = str[:j+1]
      x = "".join(sub) 

      if x in dict and dict[x] != i:
        
        if j == lenStr-1:
          ans.append(S[i]+S[i][::-1])

        elif checkPalin(S[i], j+1, lenStr-1):
          ans.append(sub+"".join(S[j+1:])+sub[::-1])
        
  # Caluclating for suffix:
  for i in range(n):
    str = S[i]
    lenStr = len(S[i])
  
    for j in range(lenStr-1, -1, -1):
      sub = str[j:]
      x = "".join(sub)
    
      if x in dict and dict[x] != i:
        if j==0:
          ans.append(str+str[::-1])

        elif checkPalin(str, 0, j-1):          
          ans.append(sub[::-1]+"".join(str[:j])+sub)
               
  
  return set(ans)



print(Palindrome(string))


