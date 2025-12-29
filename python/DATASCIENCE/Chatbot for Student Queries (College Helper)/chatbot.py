import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# Load CSV
faq_data = pd.read_csv("faq.csv")

questions = faq_data['question'].tolist()
answers = faq_data['answer'].tolist()

# TF-IDF Vectorizer
vectorizer = TfidfVectorizer(stop_words="english")
X = vectorizer.fit_transform(questions)

def chatbot_response(user_input):
    user_vec = vectorizer.transform([user_input])
    similarity = cosine_similarity(user_vec, X)
    idx = similarity.argmax()
    return answers[idx]

# Chat Loop
print("🤖 College Helper Bot: Ask me anything (type 'exit' to quit)")
while True:
    user = input("You: ")
    if user.lower() == "exit":
        break
    print("Bot:", chatbot_response(user))
