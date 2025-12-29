import tensorflow as tf, cv2, numpy as np, pandas as pd, os
from tensorflow.keras.models import load_model

IMG_W, IMG_H = 128, 32
model = load_model("model/ocr_model.h5")

# same char list used during training
df = pd.read_csv("data/labels.csv")
chars = sorted(list(set(''.join(df['text'].values))))

def decode(pred):
    return ''.join([chars[np.argmax(c)] for c in pred if np.max(c) > 0.5])

img = cv2.imread("data/train/line_0.png", cv2.IMREAD_GRAYSCALE)
img = cv2.resize(img, (IMG_W, IMG_H)).astype("float32")/255.0
img = np.expand_dims(img, (0, -1))
pred = model.predict(img)
print("🔮 Predicted Text:", decode(pred[0]))
