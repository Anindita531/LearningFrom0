<?php
require_once __DIR__ . '/../config/db.php';

class AuthController {

    // Register new user
    public function register($username, $email, $password) {
        global $conn;

        // Check if email or username already exists
        $stmt = $conn->prepare("SELECT * FROM users WHERE email = :email OR username = :username");
        $stmt->execute(['email' => $email, 'username' => $username]);
        if ($stmt->rowCount() > 0) {
            return ['status' => false, 'message' => 'Username or Email already exists'];
        }

        // Hash password
        $hashed_password = password_hash($password, PASSWORD_BCRYPT);

        // Insert user
        $stmt = $conn->prepare("INSERT INTO users (username, email, password) VALUES (:username, :email, :password)");
        $result = $stmt->execute([
            'username' => $username,
            'email' => $email,
            'password' => $hashed_password
        ]);

        if ($result) {
            return ['status' => true, 'message' => 'User registered successfully'];
        } else {
            return ['status' => false, 'message' => 'Registration failed'];
        }
    }

    // Login user
    // Inside AuthController class

// User login
public function login($email, $password) {
    global $conn;

    $stmt = $conn->prepare("SELECT * FROM users WHERE email = :email");
    $stmt->execute(['email' => $email]);
    $user = $stmt->fetch(PDO::FETCH_ASSOC);

    if ($user && password_verify($password, $user['password'])) {
        // Remove password before returning user info
        unset($user['password']);
        return ['status' => true, 'message' => 'Login successful', 'user' => $user];
    } else {
        return ['status' => false, 'message' => 'Invalid email or password'];
    }
}

}
?>
