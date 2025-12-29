# Base class
class Appliance:
    def turn_on(self):
        print("Powering on...")

    def turn_off(self):
        print("Shutting down...")

# Derived class
class WashingMachine(Appliance):
    def wash(self):
        print("Washing clothes...")

# Test
wm = WashingMachine()
wm.turn_on()
wm.wash()
wm.turn_off()
