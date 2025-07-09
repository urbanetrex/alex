string = input("Enter a string: ")
x = int(input("Enter a number: "))
current = 0
num = 0
for i in range(len(string)):
    if string[i] == ['S', 'N', 'A', 'K', 'E'][current]:
        num += 1
        if num == x:
            current += 1
            num = 0
    if current == 5:
        print("YES")
        break
print("NO")