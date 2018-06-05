# PIC 10B Final Exam Prep

**Disclaimer**: This is my (Peter's) own final exam prep, and it has nothing to do with the actual final which Professor Falcon is writing. Hence, you should only use these questions as a basis for what you might want to focus on. I'm also purposely writing questions that are more comprehensive and a little more difficult than what you might expect. 

```c++
int main() {
    set<int> numbers;
    for (int i = 0; i <= 100000; ++i) {
        numbers.insert(i);
    }
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) 
            numbers.erase(it);
    }
    return 0;
}
```
