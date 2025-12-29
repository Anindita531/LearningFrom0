package com.microchat.auth_service;
import com.microchat.auth_service.model.User;
import com.microchat.auth_service.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

@Service
public class AuthService {
    @Autowired private UserRepository repo;
    private BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();

    public String register(User user) {
        user.setPassword(encoder.encode(user.getPassword()));
        repo.save(user);
        return "User registered successfully!";
    }

    public boolean validateUser(String username, String password) {
        var user = repo.findByUsername(username).orElse(null);
        return user != null && encoder.matches(password, user.getPassword());
    }
}
