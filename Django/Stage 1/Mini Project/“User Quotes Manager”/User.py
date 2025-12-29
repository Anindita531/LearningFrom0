#Step 1: Create a User class
class User:
    def __init__(self, name, quote):
        self.name = name
        self.quote = quote

    def show_info(self):
        print(f"Name: {self.name}, Quote: {self.quote}")
#Step 2: Take input for multiple users
users = []

n = int(input("How many users do you want to enter? "))
for i in range(n):
    name = input("Enter your name: ")
    quote = input("Enter your positive thought: ")
    user = User(name, quote)
    users.append(user)
#Step 3: Save to a file
with open("quotes.txt", "w") as f:
    for user in users:
        f.write(f"{user.name},{user.quote}\n")
#Step 4: Read from file and display
print("\nAll stored quotes:\n")
with open("quotes.txt", "r") as f:
    for line in f:
        name, quote = line.strip().split(",")
        print(f"Name: {name}, Quote: {quote}")
