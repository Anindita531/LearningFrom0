import datetime
import os

# Accept user input
task = input("Enter today's task: ")

# Get current timestamp
timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

# Append task to log file
log_file = "task_log.txt"
with open(log_file, "a") as file:
    file.write(f"{timestamp} - {task}\n")

# Check if today is Sunday (weekday() == 6)
if datetime.datetime.now().weekday() == 6:
    # Generate archival filename with date
    archive_name = f"log_{datetime.datetime.now().strftime('%Y-%m-%d')}.txt"
    
    # Avoid overwriting existing archives
    if os.path.exists(archive_name):
        archive_name = f"log_{datetime.datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.txt"
    
    # Rename current log file
    os.rename(log_file, archive_name)
    print(f"Weekly archive created: {archive_name}")
else:
    print(f"Task logged in {log_file}")
