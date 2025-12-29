import { FaBookmark, FaHeart, FaTrash } from "react-icons/fa6";

function PostCard({ post, onDelete, onLike, onBookmark }) {
  return (
    <div className="post-card">
      <h2>{post.title}</h2>
      <p><strong>{post.author}</strong></p>
      <p>{post.content}</p>
      <div className="actions">
        <button onClick={() => onLike(post.id)}> <FaHeart className="fa"/> {post.likes}</button>
        <button onClick={() => onBookmark(post.id)}>
{post.bookmarked ? (
  <>
    <FaBookmark  className="famarked"/>
  </>
) : (
  <>
    <FaBookmark className="fa"/> 
  </>
)}
        </button>
        <button onMouseEnter={()=>{}}
        onClick={() => onDelete(post.id)}><FaTrash className="fa delete"/> </button>
      </div>
    </div>
  );
}

export default PostCard;
