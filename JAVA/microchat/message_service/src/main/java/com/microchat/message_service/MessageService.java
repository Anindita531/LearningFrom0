package com.microchat.message.service;
import com.microchat.message.model.Message;
import com.microchat.message.repository.MessageRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class MessageService {
    @Autowired private MessageRepository repo;
    @Autowired private RedisTemplate<String, Message> redis;

    public Message saveMessage(Message msg) {
        redis.opsForList().leftPush("chat:" + msg.getReceiver(), msg);
        return repo.save(msg);
    }

    public List<Message> getMessages(String receiver) {
        return repo.findByReceiver(receiver);
    }
}
