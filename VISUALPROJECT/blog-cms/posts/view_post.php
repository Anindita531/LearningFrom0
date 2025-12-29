<link rel="stylesheet" href="/blog-cms/assets/css/style.css">
<?php
require_once '../includes/functions.php';

$id = $_GET['id'];
$stmt = $conn->prepare("SELECT * FROM posts WHERE id=?");
$stmt->bind_param("i", $id);
$stmt->execute();
$post = $stmt->get_result()->fetch_assoc();

$comments = $conn->query("SELECT c.comment, u.username FROM comments c JOIN users u ON c.user_id=u.id WHERE post_id=$id ORDER BY c.created_at DESC");
?>

<?php include '../includes/header.php'; ?>
<h2><?php echo $post['title']; ?></h2>
<p><?php echo $post['content']; ?></p>
<hr>
<h3>Comments</h3>
<?php while($row = $comments->fetch_assoc()): ?>
    <p><b><?php echo $row['username']; ?>:</b> <?php echo $row['comment']; ?></p>
<?php endwhile; ?>

<?php if(isLoggedIn()): ?>
<form method="POST" action="add_comment.php">
    <input type="hidden" name="post_id" value="<?php echo $id; ?>">
    <textarea name="comment" rows="3" required></textarea><br>
    <button type="submit">Add Comment</button>
</form>
<?php else: ?>
<p><a href="../admin/login.php">Login to comment</a></p>
<?php endif; ?>
<?php include '../includes/footer.php'; ?>
