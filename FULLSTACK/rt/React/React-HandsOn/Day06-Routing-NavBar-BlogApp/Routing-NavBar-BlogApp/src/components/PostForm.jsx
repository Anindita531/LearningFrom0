import { useState } from "react";

function PostForm({ onAdd }) {
  const [title, setTitle] = useState("");
  const [author, setAuthor] = useState("");
  const [content, setContent] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();
    if (!title || !author || !content) return;
    onAdd({ title, author, content, likes: 0, bookmarked: false });
    setTitle("");
    setAuthor("");
    setContent("");
  };

  return (
    <form onSubmit={handleSubmit} className="post-form">
      <input value={title} onChange={(e) => setTitle(e.target.value)} placeholder="Title" />
      <input value={author} onChange={(e) => setAuthor(e.target.value)} placeholder="Author" />
      <textarea value={content} onChange={(e) => setContent(e.target.value)} placeholder="Write your post..." />
      <button type="submit">Add Post</button>
    </form>
  );
}

export default PostForm;
