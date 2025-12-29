package com.microchat.auth_service.controller;
import com.microchat.auth_service.model.User;
import com.microchat.auth_service.service.AuthService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/auth")
public class AuthController {
    @Autowired private AuthService authService;

    @PostMapping("/register")
    public ResponseEntity<String> register(@RequestBody User user) {
        return ResponseEntity.ok(authService.register(user));
    }

    @PostMapping("/login")
    public ResponseEntity<String> login(@RequestBody User user) {
        boolean isValid = authService.validateUser(user.getUsername(), user.getPassword());
        return isValid ? ResponseEntity.ok("Login successful!") : ResponseEntity.status(401).body("Invalid credentials");
    }
}
