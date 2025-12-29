# Empty dictionary for storing movies
movies = {}

while True:
    print("\n1. Add Movie")
    print("2. View Movies")
    print("3. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter movie name: ")
        year = input("Enter release year: ")
        movies[name] = year
        print(f"{name} added successfully!")
    elif choice == "2":
        if not movies:
            print("No movies added yet.")
        else:
            for name, year in movies.items():
                print(f"{name} ({year})")
    elif choice == "3":
        print("Goodbye!")
        break
    else:
        print("Invalid choice! Try again.")
