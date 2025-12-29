import cv2, os, numpy as np

img = cv2.imread("processed.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# detect text lines
kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (100, 3))
dilated = cv2.dilate(gray, kernel, iterations=2)
contours, _ = cv2.findContours(dilated, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

os.makedirs("data/train", exist_ok=True)
i = 0
for c in contours:
    x, y, w, h = cv2.boundingRect(c)
    line = gray[y:y+h, x:x+w]
    line = cv2.resize(line, (128, 32))
    cv2.imwrite(f"data/train/line_{i}.png", line)
    i += 1

print(f"✅ Step2 done — saved {i} line images in data/train/")
