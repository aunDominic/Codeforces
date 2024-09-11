
def nearestPalindromic(n: str) -> str:
    all_nines = "9" * (len(n)-1)
    if not all_nines:
        all_nines = "9" * 18

    all_match = n[0:((len(n) - 1)//2)]
    reverse_match = all_match[::-1]

    zeros = str(int(n[0]) + 1) + "0" * ((len(n)-1)//2 - 1)  
    reverse_zeros = zeros[::-1]
    
    k = 2 if len(n) % 2 == 0 else 1
    if all
    all_match += reverse_match 
    zeros += reverse_zeros

    print(all_nines)
    print (zeros)
    print (all_match)



nearestPalindromic("45054")