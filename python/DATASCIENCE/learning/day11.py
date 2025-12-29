import math
#Area of a Circle → Take radius as input and print the area.
def calculate_Area(radius):
        radius = float(radius)
        if radius < 0:
            raise ValueError("Radius cannot be negative.")
        return f"Area:{math.pi * radius * radius}"

try:
    user_input = input("Enter the radius of the circle: ")
    radius = float(user_input)  
    print(f"The area of the circle with radius {radius} unit is {calculate_Area(radius)} Sq.units")

except ValueError as e:
    print( f"Invalid input value  : {e}")
except TypeError as e:
    print("Invalid input type: Please enter a number. Error: " + str(e))
    



#2.Temperature Converter → Convert Celsius to Fahrenheit.
def celsiusToFarhenheit(celsius):
    if not isinstance(celsius, (int, float)):
        return "Invalid input type: Please enter a number."
    return (celsius * 9/5) + 32
celsius=float(input("Enter temperature in Celsius: "))
print(f"{celsius}degC is equal to {celsiusToFarhenheit(celsius)}degF")
#3.Odd or Even → Take a number as input and check if it’s odd or even.
def checkOddEven(number):
    if not isinstance(number, int):
        return "Invalid input type: Please enter an integer."
    return "Even" if number%2==0 else "odd"
number = int(input("Enter a number: "))
print(f"The number {number} is {checkOddEven(number)}.")

#4.Simple Interest → Formula: (P × R × T) / 100.
def calculates_SimpleInterest(p,r,t):
    if not all(isinstance(i, (int, float)) for i in [p, r, t]):
        return "Invalid input type: Please enter numbers."
    return (p * r * t) / 100
try:
    p = float(input("Enter principal amount (P): "))
    r = float(input("Enter rate of interest (R): "))
    t = float(input("Enter time in years (T): "))
    print(f"The simple interest is: {calculates_SimpleInterest(p, r, t)}")  
except ValueError as e:
    print(f"Invalid input value: {e}")

#5.Word Reverser → Take a word and print it backwards.
def reverseWord(word):
    return word[::-1]
word = input("Enter a word: ")
print(f"The reverse of the word '{word}' is '{reverseWord(word)}'.")

