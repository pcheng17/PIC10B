# PIC 10B Final Exam Prep

**Disclaimer**: This is my (Peter's) own final exam prep, and it has nothing to do with the actual final which Professor Falcon is writing. Hence, you should only use these questions as a basis for what you might want to focus on. I'm also purposely writing questions that are more comprehensive and a little more difficult than what you might expect. 

1. Assume all necessary libraries have been included, and consider the following code snippets:

```
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
```
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
As you can probably guess, both snippets of code intend to remove all even integers from the set. However, the first snippet might crash, and the second one, though it won't crash, it's not doing exactly what you think it's doing! To the best of your ability, explain why for both. Then, fix the code so that it actually successfully removes all even integers.

