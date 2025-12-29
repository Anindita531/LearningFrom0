import { BlogProvider } from "./context/BlogContext";
import Blog from "./pages/Blog";
import "./styles.css";

function App() {
  return (
    <BlogProvider>
      <Blog />
    </BlogProvider>
  );
}

export default App;

