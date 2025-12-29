<?php
class User {
    private $conn;
    private $table = "users";

    public function __construct($db){
        $this->conn = $db;
    }

    public function create($username,$email,$password){
        $query = "INSERT INTO ".$this->table." (username,email,password) VALUES (:username,:email,:password)";
        $stmt = $this->conn->prepare($query);
        $hashed = password_hash($password, PASSWORD_BCRYPT);
        $stmt->bindParam(':username',$username);
        $stmt->bindParam(':email',$email);
        $stmt->bindParam(':password',$hashed);
        if($stmt->execute()){
            return $this->conn->lastInsertId();
        }
        return false;
    }

    public function login($email,$password){
        $query = "SELECT * FROM ".$this->table." WHERE email=:email";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(":email",$email);
        $stmt->execute();
        $user = $stmt->fetch(PDO::FETCH_ASSOC);
        if($user && password_verify($password,$user['password'])){
            return $user;
        }
        return false;
    }

    public function getAllUsers($excludeId){
        $query = "SELECT id,username,email,profile_pic,status FROM ".$this->table." WHERE id != :excludeId";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(":excludeId",$excludeId);
        $stmt->execute();
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    public function updateProfile($id,$username,$status,$profilePicPath=null){
        if($profilePicPath){
            $query = "UPDATE ".$this->table." SET username=:username,status=:status,profile_pic=:profilePic WHERE id=:id";
        } else {
            $query = "UPDATE ".$this->table." SET username=:username,status=:status WHERE id=:id";
        }
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(":username",$username);
        $stmt->bindParam(":status",$status);
        $stmt->bindParam(":id",$id);
        if($profilePicPath){
            $stmt->bindParam(":profilePic",$profilePicPath);
        }
        return $stmt->execute();
    }
}
?>
