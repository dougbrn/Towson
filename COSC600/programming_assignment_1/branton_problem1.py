
def dec_to_binary(dec):
    dec = int(dec)
    if dec == 0:
        return ''
    else:
        return dec_to_binary(dec//2) + str(dec%2)

dec = input("Enter a positive decimal number: ")
ans = dec_to_binary(dec)

print("The binary number is ", end = '')
print(ans)
