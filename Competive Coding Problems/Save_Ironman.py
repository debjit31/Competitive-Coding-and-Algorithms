n = int(input())
while n > 0 :
    
    s = input()
    s=''.join(i for i in s if i.isalnum())
    
    s=s.upper()
    s1=s
    s=s[::-1]
    if s1 == s:
        print("YES")
    else:
        print("NO")
    
    n=n-1
    
   
