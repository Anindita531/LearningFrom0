package com.microchat.chat_socket_service.model;    
import lombok.*;
import java.time.LocalDateTime;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class ChatMessage {
    private String sender;
    private String receiver;
    private String content;
    private LocalDateTime timestamp = LocalDateTime.now();
}
