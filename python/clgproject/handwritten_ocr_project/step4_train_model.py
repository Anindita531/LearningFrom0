import numpy as np
import tensorflow as tf
from tensorflow import keras
from sklearn.model_selection import train_test_split
import os

# Load data
X = np.load("features.npy", allow_pickle=True)
y = np.load("labels.npy", allow_pickle=True)

# Convert characters to numeric labels
unique_chars = sorted(list(set("".join(y))))
char_to_idx = {c: i+1 for i, c in enumerate(unique_chars)}  # +1 for padding=0
idx_to_char = {i+1: c for i, c in enumerate(unique_chars)}

# Convert text to sequences of numbers
y_seq = [[char_to_idx[c] for c in text] for text in y]
max_len = max(len(seq) for seq in y_seq)

# Pad all sequences to the same length
y_padded = keras.preprocessing.sequence.pad_sequences(y_seq, maxlen=max_len, padding="post")

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y_padded, test_size=0.2, random_state=42)

# Model
model = keras.Sequential([
    keras.layers.Input(shape=(X.shape[1],)),
    keras.layers.Dense(128, activation='relu'),
    keras.layers.Dropout(0.3),
    keras.layers.RepeatVector(max_len),  # repeat features for each char position
    keras.layers.LSTM(128, return_sequences=True),
    keras.layers.TimeDistributed(keras.layers.Dense(len(unique_chars)+1, activation='softmax'))
])

model.compile(loss='sparse_categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

# Reshape y_train for sparse categorical crossentropy
y_train = np.expand_dims(y_train, -1)
y_test = np.expand_dims(y_test, -1)

# Train
model.fit(X_train, y_train, epochs=10, batch_size=2, validation_split=0.2)

model.save("ocr_model.h5")
print("✅ Model trained and saved successfully!")
