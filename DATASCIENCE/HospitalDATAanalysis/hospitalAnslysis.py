import pandas as pd

# Load dataset
df = pd.read_csv("hospital_data.csv")

# 1. Average stay per condition
avg_stay = df.groupby("Condition")["Length_of_Stay"].mean()
print("Average Stay:\n", avg_stay)

# 2. Total cost by gender
cost_by_gender = df.groupby("Gender")["Cost"].sum()
print("Cost by Gender:\n", cost_by_gender)

# 3. Readmission rate
readmission_rate = (df["Readmission"].value_counts(normalize=True) * 100)
print("Readmission Rate (%):\n", readmission_rate)

# 4. Mortality rate
mortality_rate = (df["Outcome"].eq("Deceased").mean() * 100)
print("Mortality Rate (%):", mortality_rate)
