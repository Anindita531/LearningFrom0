import cv2
import os

# Load image from correct path
img_path = "images/test1.png"  # or "images/input_image.jpg" if renamed
img = cv2.imread(img_path)

# Check if image loaded successfully
if img is None:
    raise FileNotFoundError(f"❌ Could not load image at {img_path}. Check the path and file name.")

# Proceed with preprocessing
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(gray, (5, 5), 0)
thresh = cv2.adaptiveThreshold(blur, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
                               cv2.THRESH_BINARY_INV, 11, 2)

cv2.imwrite("processed.jpg", thresh)
print("✅ Step1 done — saved as processed.jpg")
