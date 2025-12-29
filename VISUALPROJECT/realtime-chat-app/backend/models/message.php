<?php
class Message {
    private $conn;
    private $table = "messages";

    public function __construct($db){
        $this->conn = $db;
    }

    public function sendMessage($chatId,$senderId,$text){
        $query = "INSERT INTO ".$this->table." (chat_id,sender_id,text) VALUES (:chatId,:senderId,:text)";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(":chatId",$chatId);
        $stmt->bindParam(":senderId",$senderId);
        $stmt->bindParam(":text",$text);
        if($stmt->execute()){
            return $this->conn->lastInsertId();
        }
        return false;
    }

    public function getMessages($chatId,$limit=50,$offset=0){
        $query = "SELECT * FROM ".$this->table." WHERE chat_id=:chatId ORDER BY created_at ASC LIMIT :offset,:limit";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(":chatId",$chatId);
        $stmt->bindValue(":offset",(int)$offset,PDO::PARAM_INT);
        $stmt->bindValue(":limit",(int)$limit,PDO::PARAM_INT);
        $stmt->execute();
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }
}
?>
