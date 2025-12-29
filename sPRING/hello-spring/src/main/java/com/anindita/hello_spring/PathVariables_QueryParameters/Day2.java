package com.anindita.hello_spring.PathVariables_QueryParameters;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.GetMapping;

public class Day2 {
    @GetMapping("/greet/{name}")
public String greet(@PathVariable String name) {
    return "Hello, " + name + "! 🌸 Welcome to Spring Boot!";
}
@GetMapping("/greet2")
public String greet2(@RequestParam String name) {
    return "Hello, " + name + "! 🌱 Using query parameters!";
}
}
