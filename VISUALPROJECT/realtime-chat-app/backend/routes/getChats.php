<?php
require_once __DIR__ . '/../config/db.php';

$data = json_decode(file_get_contents("php://input"), true);
$userId = $data['userId'] ?? 0;

if ($userId > 0) {
    $stmt = $conn->prepare("
        SELECT c.id, c.chat_name, c.is_group,
               (SELECT message FROM messages m WHERE m.chat_id = c.id ORDER BY created_at DESC LIMIT 1) AS last_message,
               (SELECT COUNT(*) FROM messages m WHERE m.chat_id = c.id AND m.sender_id != :userId AND m.is_read = 0) AS unread_count
        FROM chats c
        JOIN chat_users cu ON c.id = cu.chat_id
        WHERE cu.user_id = :userId
    ");
    $stmt->execute(['userId' => $userId]);
    $chats = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo json_encode(['status' => true, 'chats' => $chats]);
} else {
    echo json_encode(['status' => false, 'message' => 'User ID missing']);
}
?>
