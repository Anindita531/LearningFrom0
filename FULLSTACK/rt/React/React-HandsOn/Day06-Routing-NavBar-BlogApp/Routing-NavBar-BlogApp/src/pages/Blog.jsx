import { useEffect, useState } from "react";
import { getPosts, addPost, deletePost, updatePost } from "../api";
import PostForm from "../components/PostForm";
import PostCard from "../components/PostCard";
import "../styles.css";

function Blog() {
  const [posts, setPosts] = useState([]);

  useEffect(() => {
    getPosts().then(setPosts);
  }, []);

  const handleAdd = async (newPost) => {
    const created = await addPost(newPost);
    setPosts([...posts, created]);
  };

  const handleDelete = async (id) => {
    await deletePost(id);
    setPosts(posts.filter((p) => p.id !== id));
  };

  const handleLike = async (id) => {
    const post = posts.find((p) => p.id === id);
    const updated = { ...post, likes: post.likes + 1 };
    await updatePost(id, updated);
    setPosts(posts.map((p) => (p.id === id ? updated : p)));
  };

  const handleBookmark = async (id) => {
    const post = posts.find((p) => p.id === id);
    const updated = { ...post, bookmarked: !post.bookmarked };
    await updatePost(id, updated);
    setPosts(posts.map((p) => (p.id === id ? updated : p)));
    localStorage.setItem("bookmarks", JSON.stringify(posts.filter((p) => p.bookmarked)));
  };

  return (
    <div>
      <h1>React CRUD Blog</h1>
      <PostForm onAdd={handleAdd} />
      <div className="post-list">
        {posts.map((post) => (
          <PostCard
            key={post.id}
            post={post}
            onDelete={handleDelete}
            onLike={handleLike}
            onBookmark={handleBookmark}
          />
        ))}
      </div>
    </div>
  );
}

export default Blog;
