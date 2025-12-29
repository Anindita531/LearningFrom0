// src/api.js
const API_URL = "http://localhost:5000/posts";

export async function getPosts() {
  const res = await fetch(API_URL);
  return res.json();
}

export async function addPost(newPost) {
  const res = await fetch(API_URL, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(newPost),
  });
  return res.json();
}

export async function updatePost(id, updatedPost) {
  const res = await fetch(`${API_URL}/${id}`, {
    method: "PUT",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(updatedPost),
  });
  return res.json();
}

export async function deletePost(id) {
  await fetch(`${API_URL}/${id}`, { method: "DELETE" });
}
