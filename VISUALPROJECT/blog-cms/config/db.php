<?php
$host = 'localhost';
$db   = 'blog_cms';
$user = 'root';
$pass = 'MyNewSecure@123'; // default XAMPP MySQL password is empty

$conn = new mysqli($host, $user, $pass, $db);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
