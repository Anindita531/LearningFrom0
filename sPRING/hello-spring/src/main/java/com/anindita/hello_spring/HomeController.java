package com.anindita.hello_spring;

import org.springframework.web.bind.annotation.GetMapping;

import org.springframework.web.bind.annotation.RestController;

@RestController
public class HomeController {

    @GetMapping("/")
    public String home() {
        return "Hello, Anindita! 🌸 Your Spring Boot app is running!";
    }
    @GetMapping("/about")
public String about() {
    return "This is Anindita's first Spring Boot project 🌱";
}


}
