<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: POST, GET, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type");
header('Content-Type: application/json');

include '../config/db.php';
include '../models/User.php';
include '../models/Message.php';

$input = json_decode(file_get_contents('php://input'), true);

$userModel = new User($conn);
$messageModel = new Message($conn);

if(!isset($input['action'])){
    echo json_encode(["status"=>false,"message"=>"No action specified"]);
    exit();
}

switch($input['action']){
    case "register":
        $id = $userModel->create($input['username'],$input['email'],$input['password']);
        echo json_encode($id ? ["status"=>true,"message"=>"User registered","userId"=>$id] : ["status"=>false,"message"=>"Registration failed"]);
        break;

    case "login":
        $user = $userModel->login($input['email'],$input['password']);
        echo json_encode($user ? ["status"=>true,"message"=>"Login successful","user"=>$user] : ["status"=>false,"message"=>"Invalid email or password"]);
        break;

    case "update_profile":
        $updated = $userModel->updateProfile($input['id'],$input['username'],$input['status'],$input['profile_pic'] ?? null);
        echo json_encode(["status"=>$updated,"message"=>$updated?"Profile updated":"Update failed"]);
        break;

    case "get_users":
        $users = $userModel->getAllUsers($input['excludeId']);
        echo json_encode(["status"=>true,"users"=>$users]);
        break;

    case "send_message":
        $id = $messageModel->sendMessage($input['chatId'],$input['senderId'],$input['text']);
        echo json_encode($id ? ["status"=>true,"messageId"=>$id] : ["status"=>false,"message"=>"Message failed"]);
        break;

    case "get_messages":
        $messages = $messageModel->getMessages($input['chatId'],$input['limit'] ?? 50,$input['offset'] ?? 0);
        echo json_encode(["status"=>true,"messages"=>$messages]);
        break;

    default:
        echo json_encode(["status"=>false,"message"=>"Invalid API call"]);
}
?>
