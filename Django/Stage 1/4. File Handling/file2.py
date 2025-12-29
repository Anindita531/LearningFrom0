# Write data for two users
for i in range(2):
    name = input("Enter Your Name: ")
    quotes = input("Enter your positive thoughts: ")
    with open("quots.txt", "a") as f:  # 'a' = append
        f.write(name + " - " + quotes + "\n")

# Read and display all data
print("\nAll stored quotes:\n")
with open("quots.txt", "r") as f:
    for line in f:
        print(line.strip())
