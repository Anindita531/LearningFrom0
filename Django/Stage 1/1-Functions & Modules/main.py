# main.py
from greetings import say_hello, say_goodbye
from user_utils import add_user, show_user

# Ask for user input
name = input("Enter your name: ")
print(say_hello(name))

email = input("Enter your email-id: ")
if "@" not in email:
    print("Email must contain '@'")
else:
    user = add_user(name, email)
    show_user(user)

print(say_goodbye(name))
