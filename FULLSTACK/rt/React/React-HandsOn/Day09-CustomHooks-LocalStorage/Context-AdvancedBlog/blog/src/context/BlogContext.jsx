import { createContext, useContext, useEffect, useState } from "react";
import { getPosts, addPost, deletePost, updatePost } from "../api";
import useLocalStorage from "../hooks/useLocalStorage";

const BlogContext = createContext();

export function BlogProvider({ children }) {
  const [posts, setPosts] = useState([]);
  const [bookmarks, setBookmarks] = useLocalStorage("bookmarks", []);

  useEffect(() => {
    getPosts().then(setPosts);
  }, []);

  const addNewPost = async (newPost) => {
    const created = await addPost(newPost);
    setPosts([...posts, created]);
  };

  const removePost = async (id) => {
    await deletePost(id);
    setPosts(posts.filter((p) => p.id !== id));
  };

  const toggleLike = async (id) => {
    const post = posts.find((p) => p.id === id);
    const updated = { ...post, likes: post.likes + 1 };
    await updatePost(id, updated);
    setPosts(posts.map((p) => (p.id === id ? updated : p)));
  };

  const toggleBookmark = async (id) => {
    const post = posts.find((p) => p.id === id);
    const updated = { ...post, bookmarked: !post.bookmarked };
    await updatePost(id, updated);
    setPosts(posts.map((p) => (p.id === id ? updated : p)));

    const newBookmarks = updated.bookmarked
      ? [...bookmarks, updated]
      : bookmarks.filter((b) => b.id !== id);
    setBookmarks(newBookmarks);
  };

  return (
    <BlogContext.Provider
      value={{ posts, addNewPost, removePost, toggleLike, toggleBookmark, bookmarks }}
    >
      {children}
    </BlogContext.Provider>
  );
}

export const useBlog = () => useContext(BlogContext);
