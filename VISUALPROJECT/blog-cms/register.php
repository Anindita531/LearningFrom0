<?php
session_start();
require_once 'config/db.php';
$error = '';

if($_SERVER['REQUEST_METHOD'] === 'POST'){
    $username = trim($_POST['username']);
    $email    = trim($_POST['email']);
    $password = trim($_POST['password']);
    $cpassword= trim($_POST['cpassword']);

    if($username=='' || $email=='' || $password==''){
        $error = "All fields are required!";
    } elseif($password != $cpassword){
        $error = "Passwords do not match!";
    } else {
        $stmt = $conn->prepare("SELECT id FROM users WHERE email=?");
        $stmt->bind_param("s",$email);
        $stmt->execute();
        $res = $stmt->get_result();

        if($res->num_rows > 0){
            $error = "Email already registered!";
        } else {
            $hashed = password_hash($password,PASSWORD_DEFAULT);
            $role = 'user';
            $stmt2 = $conn->prepare("INSERT INTO users (username,email,password,role) VALUES (?,?,?,?)");
            $stmt2->bind_param("ssss",$username,$email,$hashed,$role);
            if($stmt2->execute()){
                $_SESSION['user_id'] = $conn->insert_id;
                $_SESSION['username']= $username;
                $_SESSION['role']    = $role;
                header("Location: index.php");
                exit();
            } else {
                $error = "Registration failed!";
            }
        }
    }
}

require_once 'includes/header.php';
?>
<h2>Register</h2>
<?php if($error) echo "<p style='color:red;'>$error</p>"; ?>
<form method="post">
<label>Username</label>
<input type="text" name="username" required>
<label>Email</label>
<input type="email" name="email" required>
<label>Password</label>
<input type="password" name="password" required>
<label>Confirm Password</label>
<input type="password" name="cpassword" required>
<button type="submit">Register</button>
</form>
<p>Already have an account? <a href="login.php">Login here</a></p>
<?php include 'includes/footer.php'; ?>
