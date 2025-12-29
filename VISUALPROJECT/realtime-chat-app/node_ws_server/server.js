const io = require("socket.io")(3001, { cors: { origin: "*" } });

let onlineUsers = {};

io.on("connection", (socket) => {
  console.log("New connection:", socket.id);

  socket.on("user_online", (userId) => {
    onlineUsers[userId] = socket.id;
    io.emit("update_online_users", Object.keys(onlineUsers));
  });

  socket.on("user_offline", (userId) => {
    delete onlineUsers[userId];
    io.emit("update_online_users", Object.keys(onlineUsers));
  });

  socket.on("join_chat", (chatId) => {
    socket.join(chatId);
  });

  socket.on("send_message", (data) => {
    socket.to(data.chatId).emit("receive_message", data);
  });

  socket.on("typing", (data) => {
    socket.to(data.chatId).emit("typing", data);
  });

  socket.on("disconnect", () => {
    for(let uid in onlineUsers){
      if(onlineUsers[uid]===socket.id) delete onlineUsers[uid];
    }
    io.emit("update_online_users", Object.keys(onlineUsers));
  });
});

console.log("WebSocket server running on port 3001");
