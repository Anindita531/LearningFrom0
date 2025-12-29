class Device: 
    def __init__(self, name, location): 
        self.name = name 
        self.location = location 
        self.status = "off" 
     
    def turn_on(self): 
        self.status = "on" 
        print(f"{self.name} is now ON") 
     
    def turn_off(self): 
        self.status = "off" 
        print(f"{self.name} is now OFF") 
Device=Device("Lamp", "Living Room")
Device.turn_on()