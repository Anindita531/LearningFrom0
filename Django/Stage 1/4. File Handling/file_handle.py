with open("users.txt", "w") as f:
    f.write("Anindita, ani@example.com\n")
    f.write("Rahul, rahul@example.com\n")

# Read file
with open("users.txt", "r") as f:
    for line in f:
        print(line.strip())
