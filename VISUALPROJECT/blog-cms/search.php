<?php
require_once 'includes/functions.php';
$keyword = isset($_GET['q']) ? $_GET['q'] : '';
$result = $conn->query("SELECT * FROM posts WHERE title LIKE '%$keyword%' OR content LIKE '%$keyword%' ORDER BY created_at DESC");
?>

<?php include 'includes/header.php'; ?>
<h2>Search Posts</h2>
<form method="GET">
    <input type="text" name="q" placeholder="Search..." value="<?php echo $keyword; ?>">
    <button type="submit">Search</button>
</form>
<hr>
<?php while($row = $result->fetch_assoc()): ?>
    <h3><?php echo $row['title']; ?></h3>
    <p><?php echo substr($row['content'],0,150); ?>...</p>
    <a href="posts/view_post.php?id=<?php echo $row['id']; ?>">Read More</a><hr>
<?php endwhile; ?>
<?php include 'includes/footer.php'; ?>
