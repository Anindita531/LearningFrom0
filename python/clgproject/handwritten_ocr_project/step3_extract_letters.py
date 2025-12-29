import os, pandas as pd

lines = sorted(os.listdir("data/train"))
text_labels = []

print("📝 Enter text for each handwritten line:")
for fname in lines:
    label = input(f"{fname} → ")
    text_labels.append({"image": fname, "text": label})

df = pd.DataFrame(text_labels)
df.to_csv("data/labels.csv", index=False)
print("✅ Step3 done — labels saved in data/labels.csv")
