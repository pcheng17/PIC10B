# PIC 10B Final Exam Prep

**Disclaimer**: This is my (Peter's) own final exam prep, and it has nothing to do with the actual final which Professor Falcon is writing. Hence, you should only use these questions as a basis for what you might want to focus on. I'm also purposely writing questions that are more comprehensive and a little more difficult than what you might expect. 

1. Assume all necessary libraries have been included, and consider the following code snippets:

```c++
int main() {
    set<int> s;
    for (int i = 0; i <= 100000; ++i) {
        s.insert(i);
    }
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it % 2 == 0) 
            s.erase(it);
    }
    return 0;
}
```
```c++
int main() {
    set<int> s;
    for (int i = 0; i <= 100000; ++i) {
        s.insert(i);
    }
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it % 2 == 0) 
           	// This line is different!
            it = s.erase(it);    
    }
    return 0;
}
```