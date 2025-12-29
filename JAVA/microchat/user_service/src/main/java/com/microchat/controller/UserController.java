import com.microchat.user.model.UserProfile;
import com.microchat.user.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController
@RequestMapping("/api/users")
public class UserController {
    @Autowired private UserRepository repo;

    @GetMapping
    public List<UserProfile> all() { return repo.findAll(); }

    @PostMapping("/update")
    public UserProfile update(@RequestBody UserProfile user) { return repo.save(user); }
}
