# user_utils.py

def add_user(name, email):
    """Returns a dictionary with user info."""
    user_dict = {"name": name, "email": email}
    return user_dict

def show_user(user_dict):
    """Prints user info nicely."""
    print(f"Name: {user_dict['name']}, Email: {user_dict['email']}")
