import { useBlog } from "../context/BlogContext";
import PostForm from "../components/PostForm";
import PostCard from "../components/PostCard";

function Blog() {
  const { posts, addNewPost, removePost, toggleLike, toggleBookmark } = useBlog();

  return (
    <div>
      <h1>🧠 Context-powered React Blog</h1>
      <PostForm onAdd={addNewPost} />
      <div className="post-list">
        {posts.map((post) => (
          <PostCard
            key={post.id}
            post={post}
            onDelete={removePost}
            onLike={toggleLike}
            onBookmark={toggleBookmark}
          />
        ))}
      </div>
    </div>
  );
}

export default Blog;
