// Load quotes from local JSON
const quotes=[
  {"text": "Be yourself; everyone else is already taken.", "author": "Oscar Wilde"},
  {"text": "Do what you can, with what you have, where you are.", "author": "Theodore Roosevelt"},
  {"text": "Success is not final, failure is not fatal: it is the courage to continue that counts.", "author": "Winston Churchill"},
  {"text": "Believe you can and you're halfway there.", "author": "Theodore Roosevelt"},
  {"text": "Happiness is not something ready made. It comes from your own actions.", "author": "Dalai Lama"}
]
;

document.getElementById("btn").addEventListener("click", () => {
  if (quotes.length === 0) return;
  const random = quotes[Math.floor(Math.random() * quotes.length)];
  document.getElementById("quote").innerText = `"${random.text}"`;
  document.getElementById("author").innerText = `- ${random.author}`;
});
