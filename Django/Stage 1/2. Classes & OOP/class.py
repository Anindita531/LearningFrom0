class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email
    def greet(self):
        print("Hello ",self.name,"!")
    def show_info(self):
        print(f"Name: {self.name}, Email: {self.email}")

# Create objects
u1 = User("Anindita", "ani@example.com")
u2 = User("Debashmita", "Debashmita@example.com")
u3 = User("Debashmita", "Debashmita@example.com")

u1.show_info()
u2.show_info()
u3.greet()
